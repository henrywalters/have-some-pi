#include <iostream>
#include <string>
#include <vector>
#include "./Source/BaseScript.hpp"
#include "./Source/Components/LCD1602.hpp"
#include "./Source/Scripts/Test.hpp"
#include "./Source/Scripts/Blink.hpp"
#include "./Source/Scripts/BreathingLED.hpp"
#include "./Source/Scripts/ButtonLED.hpp"

const std::vector<BaseScript*> scripts = {
    new TestScript(),
    new BlinkScript(),
    new BreathingLED(),
    new ButtonLED(),
};

int main(int argc, char *argv[]) {
    std::cout << "Time to have some pi ;)" << std::endl;

    bool running = true;
    int script = 0;
    int scriptCount = scripts.size();

    while (running) {

        std::cout << "Select a script to run" << std::endl;

        for (int i = 0; i < scriptCount; i++) {
            std::cout << (i + 1) << ") " << scripts[i]->getName() << std::endl;
        }

        std::cout << (scriptCount + 1) << ") Quit" << std::endl;

        std::cout << std::endl;

        std::cin >> script;

        script -= 1;

        if (script >= 0 && script < scriptCount) {
            std::cout << "Running " << scripts[script]->getName() << std::endl;
            scripts[script]->run();
        } else if (script == scriptCount) {
            running = false;
        } else {
            std::cout << "Invalid input provided" << std::endl;
        }
    }

    return 1;
}