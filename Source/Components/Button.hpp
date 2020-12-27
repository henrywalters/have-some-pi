#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <wiringPi.h>

class Button {
    int _pin;

public:
    Button(int pin) : _pin(pin) {
        pinMode(_pin, INPUT);
        pullUpDnControl(_pin, PUD_UP);
    }

    bool isPressed() {
        return digitalRead(_pin) == LOW;
    }
};

#endif