#ifndef BUTTON_LED_HPP
#define BUTTON_LED_HPP
#include <iostream>
#include "./../BaseScript.hpp"
#include "./../Components/Button.hpp"
#include "./../Components/DigitalOutput.hpp"

class ButtonLED : public BaseScript {
    Button* btn;
    DigitalOutput* led;

public:
    ButtonLED() : BaseScript("Button controlled LED") {
        btn = NULL;
        led = NULL;
    }

    void OnCreate() {
        wiringPiSetup();
        btn = new Button(2);
        led = new DigitalOutput(1);
        btn->onPress([this]() {
            led->toggle();
        });
    }

    void OnUpdate() {
        btn->poll();
    }

    void OnDestroy() {
        delete led;
        delete btn;
    }
};

#endif