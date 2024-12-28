#include <stdio.h>
#include <string.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "bsp/board_api.h"

#include "usb_host.h"
#include "pd_seq.h"
#include "pio_usb.h"
#include "tusb.h"
#include "usb_midi_host.h"

// USB MIDI Host
#define USBA_PWR_ENA_GPIO 24
#define USBA_SEL_GPIO 5

// USB Host object
// Adafruit_USBH_Host USBHost;

// holding device descriptor
tusb_desc_device_t desc_device;

// holding the device address of the MIDI device
uint8_t midi_dev_addr = 0;

uint32_t total_midi_bytes = 0;

bool pio_usb_host_endpoint_abort_transfer(uint8_t rhport, uint8_t dev_addr, uint8_t ep_addr)
{
  // uint8_t const pio_rhport = RHPORT_PIO(rhport);
  // return pio_usb_host_endpoint_abort_transfer(pio_rhport, dev_addr, ep_addr);
  return true;
}

void usbhost_init()
{
  // printf("Initializing usb host.\n");

  // Enable USB-A
  // printf("enabling usb-a\r\n");
  // gpio_init(USBA_PWR_ENA_GPIO);
  // gpio_set_dir(USBA_PWR_ENA_GPIO, GPIO_OUT);
  // gpio_put(USBA_PWR_ENA_GPIO, 1);
  // gpio_init(USBA_SEL_GPIO);
  // gpio_set_dir(USBA_SEL_GPIO, GPIO_OUT);
  // gpio_put(USBA_SEL_GPIO, 1);

  // printf("enabling tiny-usb\n");
  // tusb_init();
  // sleep_ms(100);
}

void usbhost_tick()
{
  // tuh_task();

  // tuh_task();
  //   USBHost.task();
  //   bool connected = midi_dev_addr != 0 && tuh_midi_configured(midi_dev_addr);
}

//--------------------------------------------------------------------+
// TinyUSB Callbacks
//--------------------------------------------------------------------+

// Invoked when device with hid interface is mounted
// Report descriptor is also available for use. tuh_hid_parse_report_descriptor()
// can be used to parse common/simple enough descriptor.
// Note: if report descriptor length > CFG_TUH_ENUMERATION_BUFSIZE, it will be skipped
// therefore report_desc = NULL, desc_len = 0
void tuh_midi_mount_cb(uint8_t dev_addr, uint8_t in_ep, uint8_t out_ep, uint8_t num_cables_rx, uint16_t num_cables_tx)
{
  printf("MIDI device address = %u, IN endpoint %u has %u cables, OUT endpoint %u has %u cables\r\n",
         dev_addr, in_ep & 0xf, num_cables_rx, out_ep & 0xf, num_cables_tx);

  if (midi_dev_addr == 0)
  {
    // then no MIDI device is currently connected
    midi_dev_addr = dev_addr;
  }
  else
  {
    printf(
        "A different USB MIDI Device is already connected.\r\nOnly one device at a time is supported in this program\r\nDevice is disabled\r\n");
  }
}

// Invoked when device with hid interface is un-mounted
void tuh_midi_umount_cb(uint8_t dev_addr, uint8_t instance)
{
  if (dev_addr == midi_dev_addr)
  {
    midi_dev_addr = 0;
    printf("MIDI device address = %d, instance = %d is unmounted\r\n", dev_addr, instance);
  }
  else
  {
    printf("Unused MIDI device address = %d, instance = %d is unmounted\r\n", dev_addr, instance);
  }
}

void tuh_midi_rx_cb(uint8_t dev_addr, uint32_t num_packets)
{
  // if (midi_dev_addr == dev_addr){
  if (num_packets != 0)
  {
    uint8_t cable_num;
    uint8_t buffer[32];
    while (1)
    {
      // read messages from the MIDI device
      uint32_t bytes_read = tuh_midi_stream_read(dev_addr, &cable_num, buffer, sizeof(buffer));
      if (bytes_read == 0)
        return;
      // place the message in the SPI buffer

      // spi_trans_t *current_trans_ptr = &spi_trans[current_trans];
      // uint8_t *wpos = current_trans_ptr->wpos;
      // // safety check for buffer size
      // if(*wpos > 32 + 3){ // 32 is max buffer size for USB HOST MIDI data, 3 is magic numbers and length
      //     printf("usb midi message too long %d!\r\n", *wpos);
      // }else{
      //     uint8_t *out_buf = current_trans_ptr->out_buf + *wpos + 3; // add 3 for magic numbers and length
      //     memcpy(out_buf, buffer, bytes_read);
      //     *wpos += (uint8_t)bytes_read;
      //     // send the message to the midi uart out
      //     // TODO may block when a lot of data comes in from USB
      //     // TX fifo is 32 bytes deep
      //     uart_write_blocking(UART_ID, buffer, bytes_read);
      // }

      if (bytes_read < 5)
      {
        tbd_send_midi(buffer, bytes_read);
      }
    }
  }
  //}
}

void tuh_midi_tx_cb(uint8_t dev_addr)
{
  (void)dev_addr;
}
