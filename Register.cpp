#include "Register.h"
#include "ALU.h"
#include "Colors.h"

#include <stdexcept>

Register::Register()
{
    for (size_t i = 0; i < 16; ++i)
    {
        this->registers[i] = "00";
    }
}

void Register::setValue(const int& address, const std::string& value)
{
    if (15 < address < 0)
    {
        throw std::out_of_range(std::string(RED) + std::string(BOLD) +\
                                "Register address is out of range" + std::string(RESET));
    }
    this->registers[address] = value;
}

void Register::setValue(const std::string& address, const std::string& value)
{
    ALU* alu = new ALU();
    int dec = alu->HexToDec(address);
    this->setValue(dec, value);
    delete alu;
}

std::string Register::getValue(const int& address)
{
    if (15 < address < 0)
    {
        throw std::out_of_range(std::string(RED) + std::string(BOLD) +\
                                "Register address is out of range" + std::string(RESET));
    }
    return this->registers[address];
}

std::string Register::getValue(const std::string& address)
{
    ALU* alu = new ALU();
    int dec = alu->HexToDec(address);
    delete alu;
    return this->getValue(dec);
}