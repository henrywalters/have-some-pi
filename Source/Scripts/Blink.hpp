#ifndef BLINK_SCRIPT_HPP
#define BLINK_SCRIPT_HPP
#include <wiringPi.h>
#include "../BaseScript.hpp"
#include "../Components/LED.hpp"

class BlinkScript : public BaseScript {

    LED* _led;

public:

    BlinkScript() : BaseScript("Blink LED") {
        _led = NULL;
    }

    void OnCreate() {
        wiringPiSetup();
        _led = new LED(0);
    }

    void OnUpdate() {
        _led->on();
        delay(1000);
        _led->off();
        delay(1000);
    }
};

#endif