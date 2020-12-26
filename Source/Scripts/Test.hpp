#ifndef TEST_SCRIPT_HPP
#define TEST_SCRIPT_HPP
#include <iostream>
#include "./../BaseScript.hpp"

class TestScript : public BaseScript {
public:
    TestScript() : BaseScript("test") {}

    void OnCreate() {
        std::cout << "Created Test Script\n";
    }

    void OnUpdate() {
        std::cout << "Update Test\n";
        _running = false;
    }

    void OnDestroy() {
        std::cout << "Ending Test Script\n";
    }
};

#endif