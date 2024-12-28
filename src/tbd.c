#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/util/queue.h"
// #include "bsp/board_api.h"
// #include "pico/binary_info.h"
#include "hardware/spi.h"
#include "hardware/dma.h"

#include "tbd.h"

// #include <SPI.h>

#define SPI_PORT spi0
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

uint dma_tx_spi;
uint dma_rx_spi;

dma_channel_config ctx_spi;
dma_channel_config crx_spi;

queue_t ws_irq_msg_q_sync_spi;
queue_t ws_irq_msg_q_sync_i2c;

int midi_counter_tx = 0;

unsigned long previousMillis = 0;

void ws_callback(uint gpio, uint32_t events)
{
    ws_counter++;

    // sync to word clock of codec i2s @ 44100Hz
    // divider 32 is block size of TBD
    static uint32_t cnt = 0;
    cnt++;
    if (cnt % 32 == 0){
        // is 44100Hz / 32 = 1378,125Hz or 725,62us
        queue_try_add(&ws_irq_msg_q_sync_spi, &cnt);
    }
    if (cnt % 441 == 0){
        // is 44100Hz / 441 -> 10ms
        queue_try_add(&ws_irq_msg_q_sync_i2c, &cnt);
    }
    // toggle indicator LED
    static bool led_state = false;
    if (cnt % 44100 == 0){
        board_led_write(led_state);
        led_state = !led_state;
    }
}

void init_spi() {

    // printf("spi configure\n");

    // init global spi dma buffers
    // protocol is magic number 0xCAFE, 1 byte for length of message
    // max message length is 64 - 3 bytes
    current_trans = 0;
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

    dma_tx_spi = dma_claim_unused_channel(true);
    dma_rx_spi = dma_claim_unused_channel(true);

    ctx_spi = dma_channel_get_default_config(dma_tx_spi);
    channel_config_set_transfer_data_size(&ctx_spi, DMA_SIZE_8);
    channel_config_set_dreq(&ctx_spi, spi_get_dreq(SPI_PORT, true));
    channel_config_set_read_increment(&ctx_spi, true);
    channel_config_set_write_increment(&ctx_spi, false);

    crx_spi = dma_channel_get_default_config(dma_rx_spi);
    channel_config_set_transfer_data_size(&crx_spi, DMA_SIZE_8);
    channel_config_set_dreq(&crx_spi, spi_get_dreq(SPI_PORT, false));
    channel_config_set_read_increment(&crx_spi, false);
    channel_config_set_write_increment(&crx_spi, true);

    // Enable SPI0
    spi_init(SPI_PORT, SPI_SPEED);
    gpio_set_function(SPI_MISO, GPIO_FUNC_SPI);
    gpio_set_function(SPI_SCLK, GPIO_FUNC_SPI);
    gpio_set_function(SPI_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(SPI_CS, GPIO_FUNC_SPI);
    // this mode allows to assert CS for entire transfer by spi hw peripheral
    spi_set_format(SPI_PORT, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);
    // bi_decl(bi_4pins_with_func(SPI_MISO, SPI_MOSI, SPI_SCLK, SPI_CS, GPIO_FUNC_SPI));
}

void tbd_init()
{
    printf("Initializing TBD SPI...\n");

    printf("enabling ws sync\r\n");
    queue_init(&ws_irq_msg_q_sync_spi, sizeof(uint8_t), 1);
    queue_init(&ws_irq_msg_q_sync_i2c, sizeof(uint8_t), 1);
    gpio_set_irq_enabled_with_callback(WS_PIN, GPIO_IRQ_EDGE_FALL, true, &ws_callback);

    init_spi();
}

void do_spi_dma() {
    // check if it is time to send something, depends on WS sync
    if(queue_is_empty(&ws_irq_msg_q_sync_spi)) return;

    // clear queue
    uint8_t tmp;
    queue_remove_blocking(&ws_irq_msg_q_sync_spi, &tmp);

    // check if previous DMA is done
    while(dma_channel_is_busy(dma_tx_spi) || dma_channel_is_busy(dma_rx_spi)){}

    // configure DMA
    dma_channel_configure(dma_tx_spi, &ctx_spi,
                          &spi_get_hw(SPI_PORT)->dr, // write address
                          spi_trans[current_trans].out_buf, // read address
                          SPI_BUFFER_LEN, // element count (each element is of size transfer_data_size)
                          false); // don't start yet
    dma_channel_configure(dma_rx_spi, &crx_spi,
                          spi_trans[current_trans].in_buf, // write address
                          &spi_get_hw(SPI_PORT)->dr, // read address
                          SPI_BUFFER_LEN, // element count (each element is of size transfer_data_size)
                          false); // don't start yet

    // start DMA
    dma_start_channel_mask((1u << dma_tx_spi) | (1u << dma_rx_spi));
    // swap buffers
    current_trans ^= 0x1;
    // reset buffer state
    *(spi_trans[current_trans].wpos) = 0;
}

void tbd_tick()
{
    static uint32_t lasttick = 0;

    do_spi_dma();

    uint32_t T = time_us_32();
    uint32_t DT = T - lasttick;
    if (DT < 200000)
    {
        return;
    }

    lasttick = T;

    printf("ws counter %d, midi tx counter %d\n", ws_counter, midi_counter_tx);
}

void tbd_send_midi(uint8_t *buffer, uint8_t length)
{
    midi_counter_tx += length;

    printf("tbd_send_midi %d bytes: %02X %02X %02X ...\n", length, buffer[0], buffer[1], buffer[2]);
    spi_trans_t *current_trans_ptr = &spi_trans[current_trans];
    uint8_t *wpos = current_trans_ptr->wpos;
    // safety check for buffer size
    if (*wpos > 32 + 3)
    {
        // 32 is max buffer size for USB HOST MIDI data, 3 is magic numbers and length
        printf("usb midi message too long %d!\r\n", *wpos);
    }
    else
    {
        uint8_t *out_buf = current_trans_ptr->out_buf + *wpos + 3; // add 3 for magic numbers and length
        memcpy(out_buf, buffer, length);
        *wpos += (uint8_t)length;
    }
}
