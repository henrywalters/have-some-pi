#ifndef BUTTON_BEEP_HPP
#define BUTTON_BEEP_HPP
#include <iostream>
#include "./../BaseScript.hpp"
#include "./../Components/Button.hpp"
#include "./../Components/DigitalOutput.hpp"

class ButtonBeep : public BaseScript {
    Button* btn;
    DigitalOutput *beep;

public:
    ButtonBeep() : BaseScript("Button controlled LED") {
        btn = NULL;
        beep = NULL;
    }

    void OnCreate() {
        wiringPiSetup();
        btn = new Button(2);
        beep = new DigitalOutput(3);

        btn->onPress([this]() {
            beep->on();
            std::cout << "Button pressed\n";
        });

        btn->onRelease([this]() {
            beep->off();
            std::cout << "Button released\n";
        });
    }

    void OnUpdate() {
        btn->poll();
    }

    void OnDestroy() {
        delete beep;
        delete btn;
    }
};

#endif