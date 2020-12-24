#include <wiringPi.h>
#include <stdio.h>

const int LED_COUNT = 10;
int pins[LED_COUNT] = {0,1,2,3,4,5,6,7,8,9};

int main(void) {
    wiringPiSetup();

    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(pins[i], OUTPUT);
    }

    while(1) {
        for (int i = 0; i < LED_COUNT; i++) {
            digitalWrite(pins[i], LOW);
            delay(100);
            digitalWrite(pins[i], HIGH);
        }

        for (int i = 0; i < LED_COUNT; i++) {
            digitalWrite(pins[i], LOW);
            delay(100);
            digitalWrite(pins[i], HIGH);
        }
    }

    return 1;
}