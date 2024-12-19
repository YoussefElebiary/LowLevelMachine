#include "Machine.h"
#include "LowLevelMachine.h"
#include "Colors.h"

#include <iostream>
#include <fstream>

void Machine::loadProgram(const std::string& fileName, const int& start)
{
    std::ifstream fin(fileName);
    if (!fin.is_open())
    {
        throw std::runtime_error(std::string(RED) + std::string(BOLD) +\
                                 "Couldn't open file " + std::string(RESET));
    }
    std::string str;
    int ln = 0, c = start;
    str.reserve(4);
    while (fin >> str)
    {
        ++ln;
        if (str.length() != 4)
        {
            throw std::runtime_error(std::string(RED) + std::string(BOLD) + "Invalid Instruction at line " +\
                                     std::to_string(ln) + std::string(RESET));
        }
        this->memory.setCell(c, str.substr(0, 2));
        ++c;
        this->memory.setCell(c, str.substr(2, 2));
        ++c;
    }
    this->cpu.setPC(start);
}

void Machine::printState()
{
    std::cout << BLUE << BOLD << "\nRegisters: \n" << RESET;
    for (size_t i = 0; i < 16; ++i)
    {
        std::cout << GREEN << this->cpu.getFromReg(i) << "  " << RESET;
        if ((i+1) % 4 == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << "\n\n";
    std::cout << BLUE << BOLD << "Memory: \n" << RESET;
    for (size_t i = 0; i < 256; ++i)
    {
        std::cout << GREEN << this->memory.getCell(i) << "  " << RESET;
        if ((i+1) % 16 == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << "\n\n";
    std::cout << BLUE << BOLD << "Screen: \n" << RESET;
    std::cout << screen << "\n\n";
}