// This class represents the CPU

#ifndef _CPU_H
#define _CPU_H

#include "ALU.h"
#include "CU.h"
#include "Memory.h"
#include "Register.h"

class CPU
{
private:
    Register reg;
    ALU alu;
    CU cu;
    std::string instruction;
    int programCounter;
    
    /**
     * @brief Gets the instruction to be executed from the memory using the
     *        program counter and puts it in the instruction register
     * @param mem The memory of the machine
     */
    void fetch(Memory& mem);

    /**
     * @brief Executes the decoded instruction from the instruction register
     * @param reg The register of the CPU
     * @param mem The memory of the machine
     */
    void execute(Memory& mem);

public:
    CPU();
    void runInstruction(Memory& mem);
    std::string getFromReg(const int& address);
    void setPC(const int& idx);
    int getPC();
};

#endif