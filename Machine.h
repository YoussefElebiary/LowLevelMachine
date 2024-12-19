// This contains the machine class

#ifndef _MACHINE_H
#define _MACHINE_H

#include "CPU.h"
#include "Memory.h"

class Machine
{
public:
    CPU cpu;
    Memory memory;
    Machine() {}
    void loadProgram(const std::string& fileName, const int& start);
    void printState();
};

#endif