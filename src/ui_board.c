#include <stdio.h>
#include <string.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#include "ui_board.h"
#include "usb_host.h"
#include "pd_seq.h"

#define I2C_SLAVE_ADDR 0x42

typedef struct
{
   uint16_t pot_adc_values[8];   // raw adc values
   uint16_t pot_positions[4];    // absolute position 0..65535
   uint8_t pot_states[4];        // BIT0: fwd, BIT1: bwd, BIT2: medium, BIT3: fast, BIT7: error
   uint16_t d_btns;              // BIT0-15: D1-D16
   uint16_t d_btns_long_press;   // BIT0-15: D1-D16
   uint8_t f_btns;               // BIT0: F1, BIT1: F2, BIT2: F3, BIT3: F4
   uint8_t f_btns_long_press;    // BIT0: F1, BIT1: F2, BIT2: F3, BIT3: F4
   uint8_t encoder_state;        // BIT0: encoder button, BIT1: forward, BIT2: backward, BIT3: medium, BIT4: fast
   uint32_t encoder_counter;     // 32 bit counter
   uint8_t encoder_absolute_pos; // depending on ENCODER_WHOLE_ROTATION
   uint8_t encoder_speed;        // velocity of encoder
   uint32_t systicks;            // timestamp
} ui_data_t;

ui_data_t ui_data;
ui_data_t last_ui_data2;
uint8_t first_data_read;

void ui_init()
{
   printf("Initializing ui i2c.\n");
   first_data_read = 1;
}

uint16_t _get_knob_delta_from_values(int32_t lastvalue, int32_t newvalue)
{
   int32_t dist = abs(lastvalue - newvalue);
   int32_t ret = 0;

   if (dist > 32768)
   {
      lastvalue += 65536;
      // returns
      ret = 0; //  -(newvalue - lastvalue);
   }
   else
   {
      ret = newvalue - lastvalue;
   }

   // printf("_get_knob_delta_from_values %d to %d (dist %d) ---> %d\n", lastvalue, newvalue, dist, ret);

   return ret;
}

void ui_tick()
{
   static uint32_t lasttick = 0;

   uint32_t T = time_us_32();
   uint32_t DT = T - lasttick;
   if (DT < 5000)
   {
      return;
   }

   lasttick = T;

   int n = i2c_read_blocking(i2c1, I2C_SLAVE_ADDR, &ui_data, sizeof(ui_data_t), false);
   if (!n)
   {
      return;
   }

   if (first_data_read)
   {
      memcpy(&last_ui_data2, &ui_data, sizeof(ui_data_t)); // don't trigger on first call
      first_data_read = 0;
   }

   for (int i = 0; i < 4; i++)
   {
      if (ui_data.pot_positions[i] != last_ui_data2.pot_positions[i])
      {
         // printf("UI: Pot %d changed value: %d -> %d\n", i, last_ui_data2.pot_positions[i], ui_data.pot_positions[i]);

         int16_t delta = _get_knob_delta_from_values(last_ui_data2.pot_positions[i], ui_data.pot_positions[i]);
         pd_send_knobturn(3 - i, delta);

         last_ui_data2.pot_positions[i] = ui_data.pot_positions[i];
         // Pot changed value
      }
   }

   if (ui_data.f_btns != last_ui_data2.f_btns)
   {
      // printf("UI: f_btns changed value: %d -> %d\n", last_ui_data2.f_btns, ui_data.f_btns);

      for (int i = 0; i < 4; i++)
      {
         int bitmask = 1 << i;
         int oldbit = (last_ui_data2.f_btns & bitmask) > 0;
         int newbit = (ui_data.f_btns & bitmask) > 0;
         if (newbit != oldbit)
         {
            printf("  bit %d changed value: %d -> %d\n", i, oldbit, newbit);
            pd_send_funcbutton(i, newbit ? button_press : button_release);
         }
      }
      last_ui_data2.f_btns = ui_data.f_btns;
   }

   if (ui_data.f_btns_long_press != last_ui_data2.f_btns_long_press)
   {
      // printf("UI: f_btns_long_press changed value: %d -> %d\n", last_ui_data2.f_btns_long_press, ui_data.f_btns_long_press);

      for (int i = 0; i < 4; i++)
      {
         int bitmask = 1 << i;
         int oldbit = (last_ui_data2.f_btns_long_press & bitmask) > 0;
         int newbit = (ui_data.f_btns_long_press & bitmask) > 0;
         if (newbit != oldbit)
         {
            // printf("  bit %d changed value: %d -> %d\n", i, oldbit, newbit);
            if (newbit)
            {
               pd_send_funcbutton(i, button_longpress);
            }
         }
      }

      last_ui_data2.f_btns_long_press = ui_data.f_btns_long_press;
   }

   if (ui_data.d_btns != last_ui_data2.d_btns)
   {
      // printf("UI: d_btns changed value: %d -> %d\n", last_ui_data2.d_btns, ui_data.d_btns);
      for (int i = 0; i < 16; i++)
      {
         int bitmask = 1 << i;
         int oldbit = (last_ui_data2.d_btns & bitmask) > 0;
         int newbit = (ui_data.d_btns & bitmask) > 0;
         if (newbit != oldbit)
         {
            // printf("  bit %d changed value: %d -> %d\n", i, oldbit, newbit);
            pd_send_stepbutton(i, newbit ? button_press : button_release);
         }
      }
      last_ui_data2.d_btns = ui_data.d_btns;
   }

   if (ui_data.d_btns_long_press != last_ui_data2.d_btns_long_press)
   {
      // printf("UI: d_btns_long_press changed value: %d -> %d\n", last_ui_data2.d_btns_long_press, ui_data.d_btns_long_press);
      for (int i = 0; i < 16; i++)
      {
         int bitmask = 1 << i;
         int oldbit = (last_ui_data2.d_btns_long_press & bitmask) > 0;
         int newbit = (ui_data.d_btns_long_press & bitmask) > 0;
         if (newbit != oldbit)
         {
            // printf("  bit %d changed value: %d -> %d\n", i, oldbit, newbit);
            if (newbit)
            {
               pd_send_stepbutton(i, button_longpress);
            }
         }
      }
      last_ui_data2.d_btns_long_press = ui_data.d_btns_long_press;
   }

   if (ui_data.encoder_state != last_ui_data2.encoder_state)
   {
      // printf("UI: encoder_state changed value: %d -> %d\n", last_ui_data2.encoder_state, ui_data.encoder_state);
      for (int i = 0; i < 5; i++)
      {
         int bitmask = 1 << i;
         int oldbit = (last_ui_data2.encoder_state & bitmask) > 0;
         int newbit = (ui_data.encoder_state & bitmask) > 0;
         if (newbit != oldbit)
         {
            // printf("  bit %d changed value: %d -> %d\n", i, oldbit, newbit);
         }
      }

      int bitmask = 1 << 0;
      int oldpressbit = (last_ui_data2.encoder_state & bitmask) > 0;
      int newpressbit = (ui_data.encoder_state & bitmask) > 0;
      if (newpressbit != oldpressbit)
      {
         // printf("  press bit changed value: %d -> %d\n", oldpressbit, newpressbit);
         pd_send_navbutton(newpressbit ? button_press : button_release);
      }

      bitmask = 1 << 1;
      int oldrightbit = (last_ui_data2.encoder_state & bitmask) > 0;
      int newrightbit = (ui_data.encoder_state & bitmask) > 0;
      if (newrightbit != oldrightbit)
      {
         // printf("  right bit changed value: %d -> %d\n", oldrightbit, newrightbit);
         if (newrightbit)
         {
            pd_send_navturn(1);
         }
      }

      bitmask = 1 << 2;
      int oldleftbit = (last_ui_data2.encoder_state & bitmask) > 0;
      int newleftbit = (ui_data.encoder_state & bitmask) > 0;
      if (newleftbit != oldleftbit)
      {
         // printf("  left bit changed value: %d -> %d\n", oldleftbit, newleftbit);
         if (newleftbit)
         {
            pd_send_navturn(-1);
         }
      }

      last_ui_data2.encoder_state = ui_data.encoder_state;
   }

   // char buf[17];

   // // always differs
   // last_ui_data.pot_adc_values[0] = ui_data.pot_adc_values[0];
   // last_ui_data.pot_adc_values[1] = ui_data.pot_adc_values[1];
   // last_ui_data.pot_adc_values[2] = ui_data.pot_adc_values[2];
   // last_ui_data.pot_adc_values[3] = ui_data.pot_adc_values[3];
   // last_ui_data.pot_adc_values[4] = ui_data.pot_adc_values[4];
   // last_ui_data.pot_adc_values[5] = ui_data.pot_adc_values[5];
   // last_ui_data.pot_adc_values[6] = ui_data.pot_adc_values[6];
   // last_ui_data.pot_adc_values[7] = ui_data.pot_adc_values[7];
   // last_ui_data.encoder_counter = ui_data.encoder_counter;
   // last_ui_data.systicks = ui_data.systicks;

   // if (memcmp(&ui_data, &last_ui_data, sizeof(ui_data_t)) != 0)
   // {
   //    memcpy(&last_ui_data, &ui_data, sizeof(ui_data_t));

   //    printf("UI: All values: %04d %04d %04d %04d ", ui_data.pot_positions[3], ui_data.pot_positions[2], ui_data.pot_positions[1], ui_data.pot_positions[0]);
   //    for (int j = 3; j >= 0; j--)
   //    {
   //       for (int i = 0; i < 4; i++)
   //       {
   //          if (ui_data.pot_states[j] & (1 << i))
   //             buf[(3 - j) * 4 + (3 - i)] = '1';
   //          else
   //             buf[(3 - j) * 4 + (3 - i)] = '0';
   //       }
   //    }
   //    buf[16] = 0;
   //    printf("%s ", buf);
   //    for (int i = 0; i < 5; i++)
   //    {
   //       if (ui_data.encoder_state & (1 << i))
   //          buf[4 - i] = '1';
   //       else
   //          buf[4 - i] = '0';
   //    }
   //    buf[5] = 0;
   //    printf("%02d %s ", ui_data.encoder_absolute_pos, buf);
   //    for (int i = 0; i < 16; i++)
   //    {
   //       if (ui_data.d_btns & (1 << i))
   //       {
   //          buf[i] = '1';
   //       }
   //       else
   //       {
   //          buf[i] = '0';
   //       }
   //       if (ui_data.d_btns_long_press & (1 << i))
   //       {
   //          buf[i] = 'L';
   //       }
   //    }
   //    buf[16] = 0;
   //    printf("%s ", buf);
   //    for (int i = 0; i < 4; i++)
   //    {
   //       if (ui_data.f_btns & (1 << i))
   //          buf[i] = '1';
   //       else
   //          buf[i] = '0';
   //       if (ui_data.f_btns_long_press & (1 << i))
   //          buf[i] = 'L';
   //    }
   //    buf[4] = 0;
   //    printf("%s", buf);
   //    printf("  TMB=%d\n", total_midi_bytes);
   // }
}
