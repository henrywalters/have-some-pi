#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0

int main(void) {
    printf("Starting program... \n");

    wiringPiSetup();

    pinMode(ledPin, OUTPUT);

    while(1) {
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
        delay(1000);
    }

    return 0;
}