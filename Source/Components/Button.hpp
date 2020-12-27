#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <functional>
#include <wiringPi.h>

class Button {
    int _pin;
    bool _pressed;
    std::function<void()> _onPress;
    std::function<void()> _onRelease;

public:
    Button(int pin) : _pin(pin) {
        _onPress = []() {};
        _onRelease = []() {};
        pinMode(_pin, INPUT);
        pullUpDnControl(_pin, PUD_UP);
    }

    void onPress(std::function<void()> onPressFn) {
        _onPress = onPressFn;
    }

    void onRelease(std::function<void()> onReleaseFn) {
        _onRelease = onReleaseFn;
    }

    void poll() {
        bool pressed = isPressed();
        if (pressed && !_pressed) {
            _onPress();
        }

        if (!pressed && _pressed) {
            _onRelease();
        }

        _pressed = pressed;
    }

    bool isPressed() {
        return digitalRead(_pin) == LOW;
    }
};

#endif