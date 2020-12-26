#include <iostream>
#include <string>
#include <vector>
#include "./Source/BaseScript.hpp"
#include "./Source/Scripts/Test.hpp"
#include "./Source/Components/LCD1602.cpp"

const std::vector<BaseScript*> scripts = {
    new TestScript(),
};

int main(int argc, char *argv[]) {
    std::cout << "Time to have some pi ;)" << std::endl;

    bool running = true;
    int script = 0;
    int scriptCount = scripts.size();

    while (running) {
        for (int i = 0; i < scriptCount; i++) {

            std::cout << "Select a script to run" << std::endl;

            std::cout << (i + 1) << ") " << scripts[i]->getName() << std::endl;
            std::cout << (scriptCount + 1) << ") Quit" << std::endl;

            std::cout << std::endl;

            std::cin >> script;

            script -= 1;

            std::cout << "Script = " << script << "\n";

            if (script >= 0 && script < scripts.size()) {
                std::cout << "Running " << scripts[i]->getName() << std::endl;
                scripts[i]->run();
            } else if (script == scriptCount) {
                running = false;
            } else {
                std::cout << "Invalid input provided" << std::endl;
            }
        }
    }

    return 1;
}