#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8574.h>
#include <stdio.h>
#include <lcd.h>

int pcf8754_address =0x27;
#define BASE 64

#define RS BASE + 0
#define RW BASE + 1
#define EN BASE + 2
#define LED BASE + 3
#define D4 BASE + 4
#define D5 BASE + 5
#define D6 BASE + 6
#define D7 BASE + 7

int lcdhd;

int detectI2C(int addr) {
    int fd = wiringPiI2CSetup(addr);
    if (fd < 0) {
        printf("ERROR ADDRESS :0x%x \n", addr);
        return 0;
    } else {
        if (wiringPiI2CWrite(fd, 0) < 0) {
            printf("Not found device at address 0x%x \n", addr);
            return 0;
        } else {
            printf("Found device at 0x%x \n", addr);
            return 1;
        }
    }
}

int main(void) {
    wiringPiSetup();

    if (detectI2C(0x27)) {
        pcf8754_address = 0x27;
    } else if (detectI2C(0x3F)) {
        pcf8754_address = 0x3F;
    } else {
        printf("Failedf to find address. run i2cdetect -y l");
    }

    pcf8574Setup(BASE, pcf8754_address);

    digitalWrite(LED, HIGH);
    digitalWrite(RW, LOW);
    lcdhd = lcdInit(2, 16, 4, RS, EN, D4, D5, D6, D7, 0, 0, 0, 0);

    lcdPrintf(lcdhd, "Hello World!");

    return 1;
}