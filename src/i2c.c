#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "display.h"

#define I2C_SDA 26
#define I2C_SCL 27
#define I2C_SPEED 1000000

// I2C reserves some addresses for special purposes. We exclude these from the scan.
// These are any addresses of the form 000 0xxx or 111 1xxx
bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

void shared_i2c_init()
{
    printf("Initializing I2C.\n");

    i2c_init(i2c1, I2C_SPEED);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    // printf("\nI2C Bus Scan\n");
    // printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    // for (int addr = 0; addr < (1 << 7); ++addr) {
    //     if (addr % 16 == 0) {
    //         printf("%02x ", addr);
    //     }
    //     // Perform a 1-byte dummy read from the probe address. If a slave
    //     // acknowledges this address, the function returns the number of bytes
    //     // transferred. If the address byte is ignored, the function returns
    //     // -1.
    //     // Skip over any reserved addresses.
    //     int ret;
    //     uint8_t rxdata;
    //     if (reserved_addr(addr))
    //         ret = PICO_ERROR_GENERIC;
    //     else
    //         ret = i2c_read_blocking(i2c1, addr, &rxdata, 1, false);
    //     printf(ret < 0 ? "." : "@");
    //     printf(addr % 16 == 15 ? "\n" : "  ");
    // }
    // printf("Done.\n");
    // return 0;
}
