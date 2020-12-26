#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8574.h>
#include <stdio.h>
#include <lcd.h>
#include <time.h>
#include <stdlib.h>
#include <string>

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

class LCD1602 {
    int _lcd = 0;
    int _address = 0x27;

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
                printf("UM?");
                return 1;
            }
        }
    }

public:
    LCD1602() {
        printf("Detecting address\n");
        if (detectI2C(0x27)) {
            printf("Setting address variable\n");
            _address = 0x27;
        } else if (detectI2C(0x3F)) {
            _address = 0x3F;
        } else {
            printf("Failedf to find address. run i2cdetect -y l");
        }

        printf("Setting up pcf8574\n");

        pcf8574Setup(BASE, _address);

        printf("Setup pcf8574\n");
        
        digitalWrite(LED, HIGH);
        printf("Set backlight\n");
        digitalWrite(RW, LOW);
        printf("Set IO\n");
        _lcd = lcdInit(2, 16, 4, RS, EN, D4, D5, D6, D7, 0, 0, 0, 0);
        printf("Init lcd\n");
        if (_lcd == -1) {
            printf("Failed to initialize lcd\n");
        } else {
            printf("LCD Initialized\n");
        }

    }

    void setCursorPos(int x, int y) {
        lcdPosition(_lcd, x, y);
    }

    void print(std::string str) {
        lcdPrintf(_lcd, str.c_str());
    }

};