#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8574.h>
#include <stdio.h>
#include <lcd.h>
#include <time.h>
#include <stdlib.h>

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

void printCpuTemp() {
    FILE *fp;
    char str_temp[15];
    float temp;

    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    fgets(str_temp, 15, fp);
    temp = atof(str_temp) / 1000.0;

    lcdPosition(lcdhd, 0, 0);
    lcdPrintf(lcdhd, "CPU: %.2fC", temp);
    fclose(fp);
}

void printDateTime() {
    time_t raw;
    struct tm* timeinfo;
    time(&raw);
    timeinfo = localtime(&raw);
    printf("%s \n", asctime(timeinfo));
    lcdPosition(lcdhd, 0, 1);

    lcdPrintf(lcdhd, "Time: %02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
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

    while (1) {
        printCpuTemp();
        printDateTime();
        delay(1000);
    }

    return 1;
}