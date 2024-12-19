// This class represents the CU

#ifndef _CU_H
#define _CU_H

#include "Register.h"
#include "Memory.h"
#include "ALU.h"

class CU
{
public:
    CU() {}

    /**
     * @brief Loads the value of the memory at the cell `memIdx` into the register at the index `regIdx`
     * @param reg The register of the CPU
     * @param regIdx The index of the register
     * @param mem The memory of the machine
     * @param memIdx The index of the memory cell
     */
    void loadRegMem(Register& reg, const int& regIdx, Memory& mem, const int& memIdx);

    /**
     * @brief Loads the value `val` in the register at the index `regIdx`
     * @param reg The resgister of the CPU
     * @param regIdx The index of the register
     * @param val The value to be stored in the register at index `regIdx`
     */
    void loadRegVal(Register& reg, const int& regIdx, const int& val);

    /**
     * @brief Stores the value of the register at index `regIDX` into the memory at the index `memIdx`
     * @param reg The register of the CPU
     * @param mem The memory of the machine
     * @param regIdx The index of the register
     * @param memIdx The index of the memory cell
     */
    void store(Register& reg, const int& regIDX, Memory& mem, const int& memIdx);
    
    /**
     * @brief Moves the value of the register at index `regIdx1` to the register at index `regIdx2`
     * @param reg The register of the CPU
     * @param regIdx1 The index of the first register
     * @param regIdx2 The index of the second register
     */
    void move(Register& reg, const int& regIdx1, const int& regIdx2);

    /**
     * @brief Checks the value of the register at index `regIdx` with the register index 0, if they are equal the
     *        execution of the program continues from the memory cell at index `memIdx`
     * @param reg The register of the CPU
     * @param regIdx The index of the register to be comapred with the register at index 0
     * @param memIdx The index of the memory cell that will be executed if the 2 registers are equal
     * @param PC The program counter of the CPU
     */
    void jump(Register& reg, const int& regIdx, const int& memIdx, int& PC);

    static void halt();
};

#endif