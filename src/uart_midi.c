#include <stdio.h>
#include <string.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#include "ui_board.h"
#include "usb_host.h"
#include "pd_seq.h"
#include "tbd.h"

// UART MIDI
#define UART_ID uart1
#define BAUD_RATE 31250
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY    UART_PARITY_NONE
#define UART_TX_PIN 8
#define UART_RX_PIN 9

void init_uart_midi(){
    printf("uart midi init\n");
    uart_init(UART_ID, 2400);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
    gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));

    // Actually, we want a different speed
    int actual = uart_set_baudrate(UART_ID, BAUD_RATE);
    printf("uart midi baud rate %d\n", actual);

    // Set UART flow control CTS/RTS, we don't want these, so turn them off
    uart_set_hw_flow(UART_ID, false, false);

    // Set our data format
    uart_set_format(UART_ID, DATA_BITS, STOP_BITS, PARITY);

    uart_set_fifo_enabled(UART_ID, true);
}

 void uartmidi_init() {
    init_uart_midi();
 }

 void uartmidi_tick() {
    // some data here?
    uint8_t buf[20] = { 0, };
    uint8_t bp = 0;
    while(uart_is_readable(UART_ID)){
        // TODO is this guaranteed to be a complete midi message? -> no
        // place the message in the SPI buffer
        // spi_trans_t *current_trans_ptr = &spi_trans[current_trans];
        // uint8_t *wpos = current_trans_ptr->wpos;
        // uint8_t *out_buf = current_trans_ptr->out_buf + *wpos + 3; // add 3 for magic numbers and length
        // *out_buf =
        if (bp < 20) {
            buf[bp] = uart_getc(UART_ID);
            printf("uart midi got: 0x2X\n", buf[bp]);
            bp ++;
        }
        // (*wpos)++;
        // if(*wpos > SPI_BUFFER_LEN - 3){
        //     printf("uart midi message too long %d!\n", *wpos);
        // }
    };

    if (bp > 0) {
        tbd_send_midi(&buf, bp);
    }
 }

