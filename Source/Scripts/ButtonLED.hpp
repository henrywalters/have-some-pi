#ifndef BUTTON_LED_HPP
#define BUTTON_LED_HPP
#include <iostream>
#include "./../BaseScript.hpp"
#include "./../Components/Button.hpp"

class ButtonLED : public BaseScript {
    Button* btn;
    LED* led;

public:
    ButtonLED() : BaseScript("Button controlled LED") {
        btn = NULL;
        led = NULL;
    }

    void OnCreate() {
        wiringPiSetup();
        btn = new Button(2);
        led = new LED(1);
    }

    void OnUpdate() {
        if (btn->isPressed()) {
            led->on();
        } else {
            led->off();
        }
    }

    void OnDestroy() {
        delete led;
        delete btn;
        std::cout << "Ending Test Script\n";
    }
};

#endif