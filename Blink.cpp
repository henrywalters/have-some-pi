#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0

int fibb(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        return fibb(n - 1) + fibb(n - 2);
    }
}

int main(void) {
    printf("Starting program... \n");

    int fibbs[20] = {};

    for (int i = 1; i < 20; i++) {
        fibbs[i - 1] = fibb(i);
    }

    wiringPiSetup();

    pinMode(ledPin, OUTPUT);

    int fIndex = 0;

    while(1) {
        digitalWrite(ledPin, HIGH);
        delay(fibbs[fIndex % 20]);
        digitalWrite(ledPin, LOW);
        delay(fibbs[fIndex % 20]);
        fIndex++;
    }

    return 0;
}