#include "hm3301.h"
#include <stdio.h>

int main() {

    int pm10, pm25, pm100;
    int error_code = measure_concentration("/dev/i2c-1", &pm10, &pm25, &pm100);
    if (error_code < 0) {
        printf("Error when reading from sensor");
    } else {
        printf("pm1.0: %d\n", pm10);
        printf("pm2.5: %d\n", pm25);
        printf("pm10.0: %d\n", pm100);
    }

    return 0;
}
