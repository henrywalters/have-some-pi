#ifndef BASE_SCRIPT_H
#define BASE_SCRIPT_H
#include <string>


class BaseScript {
    std::string _name;

protected:
    bool _running;

public:
    BaseScript(std::string name): _name(name), _running(false) {}

    virtual void OnCreate() {}
    virtual void OnUpdate() {}
    virtual void OnDestroy() {}

    std::string getName() {
        return _name;
    }

    void run() {
        _running = true;
        OnCreate();
        while (_running) {
            OnUpdate();
        }
        OnDestroy();
    }
};

#endif