#pragma once

#include <stdint.h>

extern void tbd_init();
extern void tbd_tick();
extern void tbd_send_midi(uint8_t *buffer, uint8_t length);
