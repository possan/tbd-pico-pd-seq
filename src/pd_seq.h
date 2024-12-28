#pragma once

#include <stdint.h>

enum pd_buttonevent {
    button_press = 1,
    button_longpress = 2,
    button_release = 3,
};

extern void pd_init();
extern void pd_tick();
extern void pd_send_knobturn(uint8_t index, int16_t delta);
extern void pd_send_knobbutton(uint8_t index, enum pd_buttonevent event);
extern void pd_send_stepbutton(uint8_t index, enum pd_buttonevent event);
extern void pd_send_funcbutton(uint8_t index, enum pd_buttonevent event);
extern void pd_send_navturn(int16_t delta);
extern void pd_send_navbutton(enum pd_buttonevent event);
extern void pd_send_midiin(uint8_t *buffer, uint8_t length);
