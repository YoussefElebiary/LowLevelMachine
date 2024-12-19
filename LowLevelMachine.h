#ifndef _LOWLEVELMACHINE_H
#define _LOWLEVELMACHINE_H

#include "Machine.h"

class LowLevelMachine
{
private:
    Machine machine{};
    void printMenu();
    int takeInput();
    void handleChoice(const int& choice);
public:
    // static std::string screen;
    // static bool isHalt;
    LowLevelMachine() {};
    void init();
};

extern std::string screen;
extern bool isHalt;

#endif