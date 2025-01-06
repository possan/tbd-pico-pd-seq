#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include "hardware/exception.h"
#include "hardware/watchdog.h"

#include "display.h"
#include "i2c.h"
#include "leds.h"
#include "pd_seq.h"
#include "tbd.h"
#include "ui_board.h"
#include "usb_host.h"
#include "m0FaultDispatch.h"

// arduino example core0 runs: tbd-spi, usb host, serial1
// arduino example core1 runs: ui board i2c polling, led strip, display updates

//
// CORE 0 runs:
// * TBD communication
// * USB Host
//
// CORE 1 runs:
// * UI Polling
// * Led updates
// * Display updates
// * Sequencer
//

void core1_entrypoint()
{
    printf("Core 1 starting...\n");
    timer_hw->dbgpause = 0;

    sleep_us(1000);


    printf("Core 1 started.\n");
    
    uint32_t lasttick = 0;
    while (true)
    {
        uint32_t T = time_us_32();
        uint32_t DT = T - lasttick;
        if (DT > 2000000)
        {
            lasttick = T;
            printf("Core 1 alive.\n");
        }


        sleep_us(1);
        __asm volatile("nop\n");
    }
}

void core0_entrypoint()
{
    printf("Core 0 starting...\n");
    timer_hw->dbgpause = 0;

    sleep_us(100);

    tbd_init();
    uartmidi_init();

    ui_init();
    leds_init();
    display_init();
    pd_init();

    usbhost_init();

    printf("Core 0 started.\n");
 
    uint32_t lasttick = 0;

    while (true)
    {
        uint32_t T = time_us_32();
        uint32_t DT = T - lasttick;
        if (DT > 2000000)
        {
            lasttick = T;
            printf("Core 0 alive.\n");
        }

        tbd_tick();
        usbhost_tick();
        uartmidi_tick();

        ui_tick();
        pd_tick();
        leds_tick();
        display_tick();

        sleep_us(1);
        __asm volatile("nop\n");
    }
}

void faultHandlerWithExcFrame(struct CortexExcFrame *exc, uint32_t cause, uint32_t extraData, struct CortexPushedRegs *pushedRegs)
{
	static const char *names[] = {
		[EXC_m0_CAUSE_MEM_READ_ACCESS_FAIL] = "Memory read failed",
		[EXC_m0_CAUSE_MEM_WRITE_ACCESS_FAIL] = "Memory write failed",
		[EXC_m0_CAUSE_DATA_UNALIGNED] = "Data alignment fault",
		[EXC_m0_CAUSE_BAD_CPU_MODE] = "Bad CPU Mode",
		[EXC_m0_CAUSE_CLASSIFIER_ERROR] = "Classifier error",
		[EXC_m0_CAUSE_UNDEFINSTR16] = "Undef 16-bit instr",
		[EXC_m0_CAUSE_UNDEFINSTR32] = "Undef 32-bit instr",
		[EXC_m0_CAUSE_BKPT_HIT] = "Breakpoint hit",
		[EXC_m0_CAUSE_UNCLASSIFIABLE] = "Unclassified fault",
	};
	uint32_t i;

	printf("%s sr = 0x%08x\n", (cause < sizeof(names) / sizeof(*names) && names[cause]) ? names[cause] : "????", exc->sr);
	printf("R0  = 0x%08x  R8  = 0x%08x\n", exc->r0_r3[0], pushedRegs->regs8_11[0]);
	printf("R1  = 0x%08x  R9  = 0x%08x\n", exc->r0_r3[1], pushedRegs->regs8_11[1]);
	printf("R2  = 0x%08x  R10 = 0x%08x\n", exc->r0_r3[2], pushedRegs->regs8_11[2]);
	printf("R3  = 0x%08x  R11 = 0x%08x\n", exc->r0_r3[3], pushedRegs->regs8_11[3]);
	printf("R4  = 0x%08x  R12 = 0x%08x\n", pushedRegs->regs4_7[0], exc->r12);
	printf("R5  = 0x%08x  SP  = 0x%08x\n", pushedRegs->regs4_7[1], (exc + 1));
	printf("R6  = 0x%08x  LR  = 0x%08x\n", pushedRegs->regs4_7[2], exc->lr);
	printf("R7  = 0x%08x  PC  = 0x%08x\n", pushedRegs->regs4_7[3], exc->pc);

	switch (cause) {
		case EXC_m0_CAUSE_MEM_READ_ACCESS_FAIL:
			printf(" -> failed to read 0x%08x\n", extraData);
			break;
		case EXC_m0_CAUSE_MEM_WRITE_ACCESS_FAIL:
			printf(" -> failed to write 0x%08x\n", extraData);
			break;
		case EXC_m0_CAUSE_DATA_UNALIGNED:
			printf(" -> unaligned access to 0x%08x\n", extraData);
			break;
		case EXC_m0_CAUSE_UNDEFINSTR16:
			printf(" -> undef instr16: 0x%04x\n", ((uint16_t*)exc->pc)[0]);
			break;
		case EXC_m0_CAUSE_UNDEFINSTR32:
			printf(" -> undef instr32: 0x%04x 0x%04x\n", ((uint16_t*)exc->pc)[0], ((uint16_t*)exc->pc)[1]);
			break;
	}

	while(1);
}

int main()

{
    stdio_init_all();
    exception_set_exclusive_handler(HARDFAULT_EXCEPTION, HardFault_Handler);
    // debugger fix: https://github.com/raspberrypi/pico-sdk/issues/1152
    timer_hw->dbgpause = 0;

    shared_i2c_init(); // i2c used by both ui and display

    printf("Pico started.\n");

    // multicore_reset_core1(); // debugger fix: https://github.com/raspberrypi/debugprobe/issues/62
    // sleep_ms(100);
    // multicore_launch_core1(core1_entrypoint);
    // timer_hw->dbgpause = 0;
    // sleep_ms(500);
    core0_entrypoint();

    return 0;
}
