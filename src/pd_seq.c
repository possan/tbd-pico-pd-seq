#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include <Heavy_sequencerpatch.h>
#include <HvLightPipe.h>
#include <HvMessage.h>

#include "pico/stdlib.h"
#include "pd_seq.h"
#include "leds.h"
#include "tbd.h"

HeavyContextInterface *hvy;
float inputbuffer[2][100];
float outputbuffer[2][100];
uint32_t lastpotvalue[4] = {0, 0, 0, 0};

void sendhook(HeavyContextInterface *context, const char *sendName, hv_uint32_t sendHash, const HvMessage *msg)
{
    double timestampMs = 1000.0 * ((double)hv_msg_getTimestamp(msg)) / hv_getSampleRate(context);

    // // only react to messages sent to receivers named "hello"
    if (!strcmp(sendName, "__hv_noteout"))
    {
        int note = (int)hv_msg_getFloat(msg, 0);
        int vel = (int)hv_msg_getFloat(msg, 1);
        int chan = (int)hv_msg_getFloat(msg, 2);

        printf("> received note out \"%s\" (%f %f %f).\n", sendName, note, vel, chan);

        uint8_t midibuf[10] = {
            0,
        };

        if (vel > 0)
        {
            midibuf[0] = 0x90 | chan;
            midibuf[1] = note;
            midibuf[2] = vel;
        }
        else
        {
            midibuf[0] = 0x80 | chan;
            midibuf[1] = note;
            midibuf[2] = 0;
        }

        tbd_send_midi(&midibuf, 3);

        // send to SPI outbox
    }
    else
        // // only react to messages sent to receivers named "hello"
        if (!strcmp(sendName, "tbd_stepled"))
        {
            int num = hv_msg_getNumElements(msg);
            const char *c0 = hv_msg_getSymbol(msg, 0);
            // float f0 = hv_msg_getFloat(msg, 0);
            // float f1 = hv_msg_getFloat(msg, 1);
            // float f2 = hv_msg_getFloat(msg, 2);

            if (strcmp(c0, "rgb") == 0 && num == 5)
            {
                int i1 = (int)hv_msg_getFloat(msg, 1);
                int i2 = (int)hv_msg_getFloat(msg, 2);
                int i3 = (int)hv_msg_getFloat(msg, 3);
                int i4 = (int)hv_msg_getFloat(msg, 4);
                // printf("> received led rgb %d = [%d %d %d]\n", i1, i2, i3, i4);
                leds_set_one(i1, i3 + (i2 << 8) + (i4 << 16)); // GRB
            }
            else if (strcmp(c0, "all-rgb") == 0 && num == 4)
            {
                int i1 = (int)hv_msg_getFloat(msg, 1);
                int i2 = (int)hv_msg_getFloat(msg, 2);
                int i3 = (int)hv_msg_getFloat(msg, 3);
                // printf("> received all led rgb [%d %d %d]\n", i1, i2, i3);
                leds_set_all(i2 + (i1 << 8) + (i3 << 16)); // GRB
            }
            else if (strcmp(c0, "off") == 0 && num == 2)
            {
                int i1 = (int)hv_msg_getFloat(msg, 1);
                // printf("> received led rgb %d = off\n", i1);
                leds_set_one(i1, 0);
            }
            else if (strcmp(c0, "all-off") == 0 && num == 1)
            {
                // printf("> received all led rgb off\n");
                leds_set_all(0);
            }
            else
            {
                printf("> received unknown led message: %s (%d args)\n", c0, num);
            }

            // send to SPI outbox
        }
        else
        {
            printf("message[%.3fms]: send to \"%s\"\n", timestampMs, sendName);
        }
}

void printhook(HeavyContextInterface *context, const char *printName, const char *str, const HvMessage *msg)
{
    double timestampMs = 1000.0 * ((double)hv_msg_getTimestamp(msg)) / hv_getSampleRate(context);
    printf("print[%.3fms]: %s %s\n", timestampMs, printName, str);
}

void pd_init()
{
    printf("Initializing heavy patch.\n");

    hvy = hv_sequencerpatch_new_with_options(8000.0f, 10, 2, 2);

    hv_setPrintHook(hvy, printhook);
    hv_setSendHook(hvy, sendhook);

    printf("Running self-tests...\n");

    HvLightPipe lp1;
    hLp_init(&lp1, 1000);
    for (int k = 0; k < 300; k++)
    {
        printf("  %d\n", k);
        if ((rand() % 6) < 4)
        {
            const uint32_t size = 4 + (4 * (rand() % 30));
            const uint8_t *ptr = malloc(size);
            const hv_uint32_t numBytes = sizeof(ReceiverMessagePair) + size - sizeof(HvMessage);
            const uint8_t *p = hLp_getWriteBuffer(&lp1, numBytes);
            if (p != NULL)
            {
                // p->receiverHash = sendHash;
                // msg_copyToBuffer(msg, (char *)&p->msg, msg_getSize(msg));
                printf("    produced %d bytes at 0x%X\n", numBytes, p);
                hLp_produce(&lp1, numBytes);
            }
            else
            {
                printf("    hLp_getWriteBuffer returned NULL\n");
            }
        }
        if ((rand() % 6) < 2)
        {
            uint32_t avail = hLp_hasData(&lp1);
            if (avail)
            {
                hv_uint32_t numBytes = 0;
                uint8_t *p = hLp_getReadBuffer(&lp1, &numBytes);
                printf("    consumed %d/%d bytes at 0x%X\n", numBytes, avail, p);
                hLp_consume(&lp1);
            }
            else
            {
                printf("    hLp_hasData returned nothing\n");
            }
        }
    }
    hLp_free(&lp1);

    printf("Sending loadbang...\n");

    uint32_t hash33 = hv_stringToHash("__hv_init");
    hv_sendBangToReceiver(hvy, hash33);

    uint32_t hash = hv_stringToHash("set-tempo");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(1));
    hv_msg_init(msg1, 1, 0);
    hv_msg_setFloat(msg1, 0, 300);
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
};

void pd_send_knobturn(uint8_t index, int16_t delta)
{
    uint32_t hash = hv_stringToHash("tbd_knob");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(3));
    hv_msg_init(msg1, 3, 0);
    hv_msg_setSymbol(msg1, 0, "turn");
    hv_msg_setFloat(msg1, 1, index);
    // if (index == 0)
    // {
    //     hv_msg_setSymbol(msg1, 1, "knob0");
    // }
    // else if (index == 1)
    // {
    //     hv_msg_setSymbol(msg1, 1, "knob1");
    // }
    // else if (index == 2)
    // {
    //     hv_msg_setSymbol(msg1, 1, "knob2");
    // }
    // else // if (index == 3)
    // {
    //     hv_msg_setSymbol(msg1, 1, "knob3");
    // }
    hv_msg_setFloat(msg1, 2, delta);
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_send_knobbutton(uint8_t index, enum pd_buttonevent event)
{
    uint32_t hash = hv_stringToHash("tbd_knob");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(2));
    hv_msg_init(msg1, 2, 0);
    if (event == button_press)
    {
        hv_msg_setSymbol(msg1, 0, "press");
    }
    else if (event == button_longpress)
    {
        hv_msg_setSymbol(msg1, 0, "longpress");
    }
    else
    {
        hv_msg_setSymbol(msg1, 0, "release");
    }
    hv_msg_setFloat(msg1, 1, index);
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_send_stepbutton(uint8_t index, enum pd_buttonevent event)
{
    uint32_t hash = hv_stringToHash("tbd_knob");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(2));
    printf("msg1=%X\n", msg1);
    hv_msg_init(msg1, 2, 0);
    if (event == button_press)
    {
        hv_msg_setSymbol(msg1, 0, "press");
    }
    else if (event == button_longpress)
    {
        hv_msg_setSymbol(msg1, 0, "longpress");
    }
    else
    {
        hv_msg_setSymbol(msg1, 0, "release");
    }
    // hv_msg_setFloat(msg1, 0, index);
    hv_msg_setFloat(msg1, 1, index);
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_send_funcbutton(uint8_t index, enum pd_buttonevent event)
{
    uint32_t hash = hv_stringToHash("tbd_func");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(2));
    hv_msg_init(msg1, 2, 0);
    if (event == button_press)
    {
        hv_msg_setSymbol(msg1, 0, "press");
    }
    else if (event == button_longpress)
    {
        hv_msg_setSymbol(msg1, 0, "longpress");
    }
    else
    {
        hv_msg_setSymbol(msg1, 0, "release");
    }
    hv_msg_setFloat(msg1, 1, index);
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_send_navturn(int16_t delta)
{
    uint32_t hash = hv_stringToHash("tbd_nav");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(2));
    hv_msg_init(msg1, 2, 0);
    hv_msg_setSymbol(msg1, 0, "turn");
    hv_msg_setFloat(msg1, 1, delta);
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_send_navbutton(enum pd_buttonevent event)
{
    uint32_t hash = hv_stringToHash("tbd_nav");
    HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(1));
    hv_msg_init(msg1, 1, 0);
    if (event == button_press)
    {
        hv_msg_setSymbol(msg1, 0, "press");
    }
    else if (event == button_longpress)
    {
        hv_msg_setSymbol(msg1, 0, "longpress"); // doesn't exist on nav button
    }
    else
    {
        hv_msg_setSymbol(msg1, 0, "release");
    }
    hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_send_midiin(uint8_t *buffer, uint8_t length)
{
    // uint32_t hash = hv_stringToHash("__hv_notein");
    // HvMessage *msg1 = (HvMessage *)hv_alloca(hv_msg_getByteSize(3));
    // hv_msg_init(msg1, 3, 0);
    // hv_msg_setFloat(msg1, 0, 36);
    // hv_msg_setFloat(msg1, 1, 42);
    // hv_msg_setFloat(msg1, 2, 0);
    // hv_sendMessageToReceiver(hvy, hash, 0, msg1);
}

void pd_tick()
{
    static uint32_t lasttick = 0;

    uint32_t T = time_us_32();
    uint32_t DT = T - lasttick;
    if (DT < 8000) // 1000000us / (8000hz / 64samples)
    {
        return;
    }

    lasttick = T;

    hv_process(hvy, &inputbuffer, &outputbuffer, 64);
};
