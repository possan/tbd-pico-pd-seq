#pragma once

#include <stdint.h>

enum pd_buttonevent {
    button_press = 1,
    button_longpress = 2,
    button_release = 3,
};

enum pd_eventtype {
    eventtype_knob = 10,
    eventtype_knobbutton = 11,
    eventtype_stepbutton = 20,
    eventtype_navbutton = 30,
    eventtype_navknob = 31,
    eventtype_funcbutton = 40,
    eventtype_midiinput = 50,
};

struct pd_inputevent {
    enum pd_eventtype type;
    enum pd_buttonevent buttonevent;
    uint16_t index; // knob #, button # etc.
    int16_t knobdelta;
    uint8_t mididata[4];
    uint16_t midilength;
};

extern void pd_init();
extern void pd_tick();

extern bool pd_handle_event(struct pd_inputevent *src);

extern void pd_send_knobturn(uint8_t index, int16_t delta);
extern void pd_send_knobbutton(uint8_t index, enum pd_buttonevent event);
extern void pd_send_stepbutton(uint8_t index, enum pd_buttonevent event);
extern void pd_send_funcbutton(uint8_t index, enum pd_buttonevent event);
extern void pd_send_navturn(int16_t delta);
extern void pd_send_navbutton(enum pd_buttonevent event);
extern void pd_send_midiin(uint8_t *buffer, uint8_t length);
