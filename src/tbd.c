#include <stdio.h>

#include "pico/stdlib.h"
// #include "pico/binary_info.h"
#include "hardware/spi.h"

#include "tbd.h"

// #include <SPI.h>

#define SPI_SPEED 8000000
#define SPI_SCLK 18
#define SPI_MOSI 19
#define SPI_MISO 20
#define SPI_CS 21
#define SPI_BUFFER_LEN 64

#define WS_PIN 22

// LED_BUILTIN
#define WS_LED 13

// transfer structure is
// byte 0, 1 -> 0xCA 0xFE (fingerprint)
// byte 2 -> amount of data bytes (max. 64 - 3)
typedef struct
{
    uint8_t *magic1, *magic2;                                // points at magic numbers
    uint8_t *wpos;                                           // points at size field
    uint8_t out_buf[SPI_BUFFER_LEN], in_buf[SPI_BUFFER_LEN]; // actual buffers
} spi_trans_t;

spi_trans_t spi_trans[2];
uint32_t current_trans = 0;
uint32_t ws_counter = 0;

unsigned long previousMillis = 0;

void ws_sync_cb(uint gpio, uint32_t events)
{
    // sync to word clock of codec i2s @ 44100Hz
    // divider 32 is block size of TBD

    ws_counter ++;

    static uint32_t cnt = 0;
    cnt++;
    if (cnt % 32 == 0)
    {
        // is 44100Hz / 32 = 1378,125Hz or 725,62us
        //     if (SPI.finishedAsync()) SPI.endTransaction();
        //     SPI.beginTransaction(spiSettings);
        //     SPI.transferAsync(spi_trans[current_trans].out_buf, spi_trans[current_trans].in_buf, SPI_BUFFER_LEN);

        // swap buffers
        current_trans ^= 0x1;

        // reset buffer state
        *(spi_trans[current_trans].wpos) = 0;
    }

    // toggle indicator LED
    static bool led_state = false;
    if (cnt % 44100 == 0)
    {
        gpio_put(WS_LED, led_state);
        led_state = !led_state;
    }
}

void tbd_init()
{
    printf("Initializing TBD SPI...\n");

    // This example will use SPI0 at 0.5MHz.
    // SPISettings spiSettings(SPI_SPEED, MSBFIRST, SPI_MODE3);

    // // Make the SPI pins available to picotool
    // bi_decl(bi_3pins_with_func(PICO_DEFAULT_SPI_RX_PIN, PICO_DEFAULT_SPI_TX_PIN, PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI));

    // // Chip select is active-low, so we'll initialise it to a driven-high state
    // gpio_init(PICO_DEFAULT_SPI_CSN_PIN);
    // gpio_set_dir(PICO_DEFAULT_SPI_CSN_PIN, GPIO_OUT);
    // gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);

    // // Make the CS pin available to picotool
    // bi_decl(bi_1pin_with_name(PICO_DEFAULT_SPI_CSN_PIN, "SPI CS"));

    // // See if SPI is working - interrograte the device for its I2C ID number, should be 0x60
    // uint8_t id;
    // read_registers(0xD0, &id, 1);
    // printf("Chip ID is 0x%x\n", id);

    // read_compensation_parameters();

    // write_register(0xF2, 0x1); // Humidity oversampling register - going for x1
    // write_register(0xF4, 0x27);// Set rest of oversampling modes and run mode to normal

    // int32_t humidity, pressure, temperature;

    // WS sync to codec
    //   pinMode(WS_PIN, INPUT);  // Configure button pin with pull-up resistor
    //   pinMode(LED_BUILTIN, OUTPUT);
    //   attachInterrupt(digitalPinToInterrupt(WS_PIN), ws_sync_cb, FALLING);
    gpio_init(WS_PIN);
    gpio_init(WS_LED);
    gpio_set_dir(WS_LED, GPIO_OUT);
    gpio_set_dir(WS_LED, GPIO_OUT);
    gpio_set_irq_enabled_with_callback(WS_PIN, GPIO_IRQ_EDGE_FALL, true, &ws_sync_cb);
    // gpio_put(SPI_CS, 1);

    spi_trans[0].magic1 = &spi_trans[0].out_buf[0];
    spi_trans[0].magic2 = &spi_trans[0].out_buf[1];
    spi_trans[0].wpos = &spi_trans[0].out_buf[2];
    *spi_trans[0].magic1 = 0xCA;
    *spi_trans[0].magic2 = 0xFE;
    *spi_trans[0].wpos = 0x00;
    spi_trans[1].magic1 = &spi_trans[1].out_buf[0];
    spi_trans[1].magic2 = &spi_trans[1].out_buf[1];
    spi_trans[1].wpos = &spi_trans[1].out_buf[2];
    *spi_trans[1].magic1 = 0xCA;
    *spi_trans[1].magic2 = 0xFE;
    *spi_trans[1].wpos = 0x00;

    spi_init(spi0, SPI_SPEED);
    gpio_set_function(SPI_MISO, GPIO_FUNC_SPI);
    gpio_set_function(SPI_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(SPI_SCLK, GPIO_FUNC_SPI);
    gpio_set_function(SPI_CS, GPIO_FUNC_SPI);
    spi_set_format(spi0, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);

    gpio_init(SPI_CS);
    gpio_set_dir(SPI_CS, GPIO_OUT);
    gpio_put(SPI_CS, 1);

    //   SPI.setMISO(SPI_MISO);
    //   SPI.setMOSI(SPI_MOSI);
    //   SPI.setCS(SPI_CS);
    //   SPI.setSCK(SPI_SCLK);
    //   SPI.begin(true);  // hw CS assertion
}

void tbd_tick()
{
   static uint32_t lasttick = 0;

   uint32_t T = time_us_32();
   uint32_t DT = T - lasttick;
   if (DT < 1000000)
   {
      return;
   }

   lasttick = T;

   printf("ws counter: %d\n", ws_counter);

    // while (1) {
    //     bme280_read_raw(&humidity, &pressure, &temperature);

    // reg |= READ_BIT;
    // cs_select();
    // spi_write_blocking(spi_default, &reg, 1);
    // sleep_ms(10);
    // spi_read_blocking(spi_default, 0, buf, len);
    // cs_deselect();
    // sleep_ms(10);

    //     // These are the raw numbers from the chip, so we need to run through the
    //     // compensations to get human understandable numbers
    //     temperature = compensate_temp(temperature);
    //     pressure = compensate_pressure(pressure);
    //     humidity = compensate_humidity(humidity);

    //     printf("Humidity = %.2f%%\n", humidity / 1024.0);
    //     printf("Pressure = %dPa\n", pressure);
    //     printf("Temp. = %.2fC\n", temperature / 100.0);

    //     sleep_ms(1000);
    // }
}

void tbd_send_midi(uint8_t *buffer, uint8_t length)
{
}
