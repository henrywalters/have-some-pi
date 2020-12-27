#ifndef BREATHING_LED_HPP
#define BREATHING_LED_HPP
#include <wiringPi.h>
#include "../BaseScript.hpp"
#include "../Components/LED.hpp"

class BreathingLED : public BaseScript {

    LED* _led;

    int blinks = 5;
    int blink = 0;

public:

    BreathingLED() : BaseScript("Breathing LED") {
        _led = NULL;
    }

    void OnCreate() {
        wiringPiSetup();
        _led = new LED(0);
        _led->enableSoftwarePwm(0, 100);
    }

    void OnUpdate() {
        if (blink == blinks) {
            _running = false;
        }

        for (int i = 0; i < 100; i++) {
            _led->setPwm(i);
            delay(20);
        }

        delay(300);

        for (int i = 100; i >= 0; i--) {
            _led->setPwm(i);
            delay(20);
        }

        delay(300);

        blink++;
    }

    void OnDestroy() {
        delete _led;
    }
};

#endif