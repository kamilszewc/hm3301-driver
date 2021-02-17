#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>

int measure_concentration(char* i2c_adapter, int* pm10, int *pm25, int *pm100) {

    int addr = 0x40;
    int reg = 0x88;

    int file = open(i2c_adapter, O_RDWR);
    if (file < 0) {
        printf("Device file can not be opened");
        return -1;
    }

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        printf("Error, can not specify device address I want to communicate");
        return -1;
    }

    __u8 values[29];
    int res = i2c_smbus_read_i2c_block_data(file, reg, 29, values);
    if (res < 0) {
        printf("Can not read data from senor");
        return -1;
    } else {
        *pm10 = values[10] << 8 | values[11];
        *pm25 = values[12] << 8 | values[13];
        *pm100 = values[14] << 8 | values[15];
        return 0;
    }
}