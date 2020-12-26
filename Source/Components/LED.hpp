#ifndef LED_HPP
#define LED_HPP
#include <wiringPi.h>

class LED {
    int _pin;

public:

    LED (int pin): _pin(pin) {
        pinMode(_pin, OUTPUT);
    }

    void on() { 
        digitalWrite(_pin, HIGH);
    }

    void off() {
        digitalWrite(_pin, LOW);
    }
};

#endif