#include "Memory.h"
#include "ALU.h"
#include "LowLevelMachine.h"
#include "Colors.h"

#include <stdexcept>

Memory::Memory()
{
    for (size_t i = 0; i < 256; ++i)
    {
        this->cells[i] = "00";
    }
}

std::string Memory::getCell(const int& address)
{
    if (255 < address < 0)
    {
        throw std::out_of_range(std::string(RED) + std::string(BOLD) +\
                                "Memory address is out of range" + std::string(RESET));
    }
    return this->cells[address];
}

std::string Memory::getCell(const std::string& address)
{
    ALU* alu = new ALU();
    int dec = alu->HexToDec(address);
    delete alu;
    return this->getCell(dec);
}

void Memory::setCell(const int& address, const std::string& value)
{
    if (255 < address < 0)
    {
        throw std::out_of_range(std::string(RED) + std::string(BOLD) +\
                                "Memory address is out of range" + std::string(RESET));
    }
    if (address == 0)
    {
        ALU* alu = new ALU();
        screen += char(alu->HexToDec(value));
        delete alu;
    }
    this->cells[address] = value;
}

void Memory::setCell(const std::string& address, const std::string& value)
{
    ALU* alu = new ALU();
    int dec = alu->HexToDec(address);
    this->setCell(dec, value);
    delete alu;
}