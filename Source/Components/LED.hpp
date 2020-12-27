#ifndef LED_HPP
#define LED_HPP
#include <wiringPi.h>
#include <softPwm.h>

class LED {
    int _pin;
    bool _on;

public:

    LED (int pin): _pin(pin) {
        pinMode(_pin, OUTPUT);
        _on = false;
    }

    void enableSoftwarePwm(int min, int max) {
        softPwmCreate(_pin, min, max);
    }

    void setPwm(int val) {
        softPwmWrite(_pin, val);
    }

    void on() { 
        digitalWrite(_pin, HIGH);
        _on = true;
    }

    void off() {
        digitalWrite(_pin, LOW);
        _on = false;
    }

    void toggle() {
        if (_on) {
            off();
        } else {
            on();
        }
    }

    bool isOn() {
        return _on;
    }
};

#endif