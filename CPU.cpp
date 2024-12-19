#include "CPU.h"
#include "Colors.h"

#include <string>
#include <iostream>

CPU::CPU()
{
    this->programCounter = 0;
    this->instruction = "";
}

void CPU::fetch(Memory& mem)
{
    this->instruction = mem.getCell(this->programCounter) + mem.getCell(this->programCounter + 1);
    this->programCounter += 2;
    if (programCounter > 255)
    {
        throw std::overflow_error(std::string(RED) + std::string(BOLD) +\
        "The program counter overflowed the memory" + std::string(RESET));
    }
}

void CPU::execute(Memory& mem)
{
    char func = this->instruction[0];
    std::string add = "";
    if (func == '1')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        int memIdx = alu.HexToDec(instruction.substr(2, 2));
        cu.loadRegMem(this->reg, regIdx, mem, memIdx);
    }
    else if (func == '2')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        int val = alu.HexToDec(instruction.substr(2, 2));
        cu.loadRegVal(this->reg, regIdx, val);
    }
    else if (func == '3')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        int memIdx = alu.HexToDec(instruction.substr(2, 2));
        cu.store(this->reg, regIdx, mem, memIdx);
    }
    else if (func == '4')
    {
        int regIdx1 = alu.HexToDec(instruction.substr(2, 1));
        int regIdx2 = alu.HexToDec(instruction.substr(3, 1));
        cu.move(this->reg, regIdx1, regIdx2);
    }
    else if (func == '5')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        add = alu.addHexInt(reg.getValue(instruction.substr(2, 1)), reg.getValue(instruction.substr(3, 1)));
        cu.loadRegVal(this->reg, regIdx, alu.HexToDec(add));
    }
    else if (func == '6')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        add = alu.addHexFloat(reg.getValue(instruction.substr(2, 1)), reg.getValue(instruction.substr(3, 1)));
        cu.loadRegVal(this->reg, regIdx, alu.HexToDec(add));
    }
    else if (func == '7')
    {
        int R = alu.HexToDec(instruction.substr(1, 1));
        int S = alu.HexToDec(instruction.substr(2, 1));
        int T = alu.HexToDec(instruction.substr(3, 1));
        std::string result = alu.OR(reg.getValue(S), reg.getValue(T));
        reg.setValue(R, result);
    }
    else if (func == '8')
    {
        int R = alu.HexToDec(instruction.substr(1, 1));
        int S = alu.HexToDec(instruction.substr(2, 1));
        int T = alu.HexToDec(instruction.substr(3, 1));
        std::string result = alu.AND(reg.getValue(S), reg.getValue(T));
        reg.setValue(R, result);
    }
    else if (func == '9')
    {
        int R = alu.HexToDec(instruction.substr(1, 1));
        int S = alu.HexToDec(instruction.substr(2, 1));
        int T = alu.HexToDec(instruction.substr(3, 1));
        std::string result = alu.XOR(reg.getValue(S), reg.getValue(T));
        reg.setValue(R, result);
    }
    else if (func == 'A')
    {
        int R = alu.HexToDec(instruction.substr(1, 1));
        std::string result = alu.rotate(reg.getValue(R), instruction.substr(3, 1));
        reg.setValue(R, result);
    }
    else if (func == 'B')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        int memIdx = alu.HexToDec(instruction.substr(2));
        cu.jump(this->reg, regIdx, memIdx, this->programCounter);
    }
    else if (func == 'C')
    {
        CU::halt();
    }
    else if (func == 'D')
    {
        int regIdx = alu.HexToDec(instruction.substr(1, 1));
        if (reg.getValue(0) < reg.getValue(regIdx))
        {
            this->programCounter = alu.HexToDec(instruction.substr(2));
        }
    }
    else
    {
    }
}

void CPU::runInstruction(Memory& mem)
{
    this->fetch(mem);
    this->execute(mem);
}

std::string CPU::getFromReg(const int& address)
{
    return this->reg.getValue(address);
}

void CPU::setPC(const int& idx)
{
    this->programCounter = idx;
}

int CPU::getPC()
{
    return this->programCounter;
}
