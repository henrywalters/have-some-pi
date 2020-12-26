#ifndef LED_HPP
#define LED_HPP
#include <wiringPi.h>
#include <softPwm.h>

class LED {
    int _pin;

public:

    LED (int pin): _pin(pin) {
        pinMode(_pin, OUTPUT);
    }

    void enableSoftwarePwm(int min, int max) {
        softPwmCreate(_pin, min, max);
    }

    void setPwm(int val) {
        softPwmWrite(_pin, val);
    }

    void on() { 
        digitalWrite(_pin, HIGH);
    }

    void off() {
        digitalWrite(_pin, LOW);
    }
};

#endif