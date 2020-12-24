#include <wiringPi.h>
#include <stdio.h>
#include <bitset>
#include <string>
#include <vector>
#include <math.h>

const int LED_COUNT = 10;
int pins[LED_COUNT] = {0,1,2,3,4,5,6,8,9,10};

std::string get_binary(int num) {
    return std::bitset<LED_COUNT>(num).to_string();
}

void display_binary(int num) {
    std::string bin = get_binary(num);
    for (int i = 0; i < LED_COUNT; i++) {
        if (bin[i] == '1') {
            digitalWrite(pins[i], LOW);
        } else {
            digitalWrite(pins[i], HIGH);
        }
    }
}

int main(void) {
    wiringPiSetup();

    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(pins[i], OUTPUT);
    }

    int num = 0;
    int max_num = pow(2, LED_COUNT);

    while (1) {
        printf("printing %i\n", num % max_num);
        display_binary(num % max_num);
        delay(200);
        num++;
    }

    return 1;
}