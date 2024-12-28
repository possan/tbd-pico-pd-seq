#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "display.h"

#define OLED_RESET 10        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels

// Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET, 1000000, 1000000);

void display_init()
{
    printf( "Initializing display.\n");

    // // useful information for picotool

//   display.begin(SCREEN_ADDRESS, true);
//   display.setRotation(2);
//   display.clearDisplay();
//   display.drawPixel(10, 10, SH110X_WHITE);
//   display.display();


}

void display_tick()
{
    // uint8_t buf[2] = {0x80, cmd};
    // i2c_write_blocking(i2c_default, SSD1306_I2C_ADDR, buf, 2, false);



//      static unsigned long tick = 0;
//   unsigned long delta = millis() - tick;
//   tick = millis();
//   Wire1.readAsync(I2C_SLAVE_ADDR, &ui_data, sizeof(ui_data_t), true);
//   while (!Wire1.finishedAsync()) delay(1);

//   char buf[17];
//   display.clearDisplay();
//   display.setTextSize(1);
//   display.setTextColor(SH110X_WHITE);
//   display.setCursor(0, 0);
//   display.printf("%04d %04d %04d %04d\n", ui_data.pot_positions[3], ui_data.pot_positions[2], ui_data.pot_positions[1], ui_data.pot_positions[0]);
//   for (int j = 3; j >= 0; j--) {
//     for (int i = 0; i < 4; i++) {
//       if (ui_data.pot_states[j] & (1 << i)) buf[(3 - j) * 4 + (3 - i)] = '1';
//       else buf[(3 - j) * 4 + (3 - i)] = '0';
//     }
//   }
//   buf[16] = 0;
//   display.printf("%s\n", buf);
//   for (int i = 0; i < 5; i++) {
//     if (ui_data.encoder_state & (1 << i)) buf[4 - i] = '1';
//     else buf[4 - i] = '0';
//   }
//   if (ui_data.encoder_state & (1)) strip.setPixelColor(0, strip.Color(0, 255, 0));
//   else strip.setPixelColor(0, strip.Color(0, 0, 0));
//   if (ui_data.encoder_state & (2)) strip.setPixelColor(0, strip.Color(255, 0, 0));
//   buf[5] = 0;
//   display.printf("%02d %s\n", ui_data.encoder_absolute_pos, buf);

//   for (int i = 0; i < 16; i++) {
//     if (ui_data.d_btns & (1 << i)) {
//       buf[i] = '1';
//       strip.setPixelColor(i + 1, strip.Color(0, 255, 0));
//     } else {
//       buf[i] = '0';
//       strip.setPixelColor(i + 1, strip.Color(64, 64, 64));
//     }
//     if (ui_data.d_btns_long_press & (1 << i)) {
//       buf[i] = 'L';
//       strip.setPixelColor(i + 1, strip.Color(255, 0, 0));
//     }
//   }
//   buf[16] = 0;
//   display.printf("%s\n", buf);
//   for (int i = 0; i < 4; i++) {
//     if (ui_data.f_btns & (1 << i)) buf[i] = '1';
//     else buf[i] = '0';
//     if (ui_data.f_btns_long_press & (1 << i)) buf[i] = 'L';
//   }
//   buf[4] = 0;
//   display.printf("%s\n", buf);
//   display.printf("FPS %dHz, MSPF %dms\n", 1000 / delta, delta);

//   display.display();
//   strip.show();







//   // always differs
//   last_ui_data.pot_adc_values[0] = ui_data.pot_adc_values[0];
//   last_ui_data.pot_adc_values[1] = ui_data.pot_adc_values[1];
//   last_ui_data.pot_adc_values[2] = ui_data.pot_adc_values[2];
//   last_ui_data.pot_adc_values[3] = ui_data.pot_adc_values[3];
//   last_ui_data.pot_adc_values[4] = ui_data.pot_adc_values[4];
//   last_ui_data.pot_adc_values[5] = ui_data.pot_adc_values[5];
//   last_ui_data.pot_adc_values[6] = ui_data.pot_adc_values[6];
//   last_ui_data.pot_adc_values[7] = ui_data.pot_adc_values[7];
//   last_ui_data.encoder_counter = ui_data.encoder_counter;
//   last_ui_data.systicks = ui_data.systicks;

//   if (memcmp(&ui_data, &last_ui_data, sizeof(ui_data_t)) != 0) {
//     memcpy(&last_ui_data, &ui_data, sizeof(ui_data_t));

//     Serial1.printf("%04d %04d %04d %04d ", ui_data.pot_positions[3], ui_data.pot_positions[2], ui_data.pot_positions[1], ui_data.pot_positions[0]);
//     for (int j = 3; j >= 0; j--) {
//       for (int i = 0; i < 4; i++) {
//         if (ui_data.pot_states[j] & (1 << i)) buf[(3 - j) * 4 + (3 - i)] = '1';
//         else buf[(3 - j) * 4 + (3 - i)] = '0';
//       }
//     }
//     buf[16] = 0;
//     Serial1.printf("%s ", buf);
//     for (int i = 0; i < 5; i++) {
//       if (ui_data.encoder_state & (1 << i)) buf[4 - i] = '1';
//       else buf[4 - i] = '0';
//     }
//     buf[5] = 0;
//     Serial1.printf("%02d %s ", ui_data.encoder_absolute_pos, buf);
//     for (int i = 0; i < 16; i++) {
//       if (ui_data.d_btns & (1 << i)) {
//         buf[i] = '1';
//       } else {
//         buf[i] = '0';
//       }
//       if (ui_data.d_btns_long_press & (1 << i)) {
//         buf[i] = 'L';
//       }
//     }
//     buf[16] = 0;
//     Serial1.printf("%s ", buf);
//     for (int i = 0; i < 4; i++) {
//       if (ui_data.f_btns & (1 << i)) buf[i] = '1';
//       else buf[i] = '0';
//       if (ui_data.f_btns_long_press & (1 << i)) buf[i] = 'L';
//     }
//     buf[4] = 0;
//     Serial1.printf("%s", buf);
//     Serial1.printf("  TMB=%d\n", total_midi_bytes);
//   }


}
