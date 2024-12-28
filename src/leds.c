#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#include "leds.h"

#define RMT_LED_STRIP_RESOLUTION_HZ 10000000

#define LED_COUNT 17
#define LED_PIN 12

PIO pio;
uint sm;
uint offset;

uint32_t colors[20];
uint8_t leds_dirty;

static inline void put_pixel(PIO pio, uint sm, uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio, sm, pixel_grb << 8u);
}

void leds_init()
{
    printf("Initializing leds.\n");

    bool success = pio_claim_free_sm_and_add_program_for_gpio_range(&ws2812_program, &pio, &sm, &offset, LED_PIN, 1, true);
    hard_assert(success);

    ws2812_program_init(pio, sm, offset, LED_PIN, 800000, false);

    sleep_us(1000000);

    put_pixel(pio, sm, 0x00FFFF); // first led is on main pcb

    put_pixel(pio, sm, 0x00FF00); // GRB color order
    put_pixel(pio, sm, 0xFF0000);
    put_pixel(pio, sm, 0x0000FF);
    put_pixel(pio, sm, 0x000000);
    put_pixel(pio, sm, 0x202020);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x101010);

    put_pixel(pio, sm, 0x202020);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x202020);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x101010);
    put_pixel(pio, sm, 0x101010);

    // put_pixel(pio, sm, urgb_u32(0xff, 0, 0));
}

void leds_tick()
{
    // send update every now and then
    if (!leds_dirty)
    {
        return;
    }

    leds_dirty = 0;

    put_pixel(pio, sm, 0xFF0000); // first led is on main pcb
    for (int k = 0; k < 16; k++)
    {
        put_pixel(pio, sm, colors[k]);
    }
}

void leds_set_one(uint8_t index, uint32_t color)
{
    // printf("Leds: Set one %d = #%06X\n", index, color);
    colors[index] = color;
    leds_dirty = 1;
}

void leds_set_all(uint32_t color)
{
    // printf("Leds: Set all #%06X\n", color);
    for (int k = 0; k < 16; k++)
    {
        colors[k] = color;
    }
    leds_dirty = 1;
}
