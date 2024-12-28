#pragma once

#include <stdint.h>

extern void leds_init();
extern void leds_tick();
extern void leds_set_one(uint8_t index, uint32_t color);
extern void leds_set_all(uint32_t color);
