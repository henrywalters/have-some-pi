#ifndef DIGITAL_OUTPUT_HPP
#define DIGITAL_OUTPUT_HPP
#include <wiringPi.h>

class DigitalOutput {
    int _pin;
    bool _on;

    bool checkPinIsOn() {
        return digitalRead(_pin) == HIGH;
    }

    void write(int val) {
        digitalWrite(_pin, val);
    }

public:
    DigitalOutput(int pin) {
        _on = checkPinIsOn();
        _pin = pin;
    }

    void on() {
         write(HIGH);
        _on = true;
    }

    void off() {
        write(LOW);
        _on = false;
    }

};

#endif