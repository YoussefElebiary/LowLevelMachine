#include "LowLevelMachine.h"
#include "Colors.h"

#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>

std::string screen = "";
bool isHalt = false;

void LowLevelMachine::printMenu()
{
    std::cout << std::setw(20) << std::right << BLUE << BOLD << "Low Level Machine" << RESET << '\n';
    std::cout << "1) Load Program \n2) Run Program \n3) Run Current Instruction \
                  \n4) Print State \n5) Exit \nChoice: ";
}

int LowLevelMachine::takeInput()
{
    int choice;
    std::cin >> choice;
    while (std::cin.fail() || !(1 <= choice && choice <= 5))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << BOLD << "Invalid Input\n" << RESET;
        this->printMenu();
        std::cin >> choice;
    }
    return choice;
}

void LowLevelMachine::handleChoice(const int& choice)
{
    if (choice == 1)
    {
        ALU* alu = new ALU();
        std::string fileName;
        std::string address;
        std::cout << "Enter the file name: ";
        std::cin.ignore();
        std::getline(std::cin, fileName);
        std::cout << "Enter the memory address to start loading the program at ("<< RED << "Hexa" << RESET << "): ";
        std::cin.ignore();
        std::cin >> address;
        address[0] = std::toupper(address[0]);
        address[1] = std::toupper(address[1]);
        machine.loadProgram(fileName, alu->HexToDec(address));
        std::cout << "Program loaded successfully\n\n";
        delete alu;
    }
    else if (choice == 2)
    {
        if (isHalt)
        {
            std::cout << "Program already finished executing\n\n";
            return;
        }
        int start = machine.cpu.getPC();
        for (size_t i = start; i < 256; ++i)
        {
            if (isHalt)
            {
                break;
            }
            this->machine.cpu.runInstruction(this->machine.memory);
        }
        this->machine.printState();
    }
    else if (choice == 3)
    {
        if (isHalt)
        {
            std::cout << "Program already finished executing\n\n";
            return;
        }
        else
        {
            this->machine.cpu.runInstruction(this->machine.memory);
            this->machine.printState();
        }
    }
    else if (choice == 4)
    {
        this->machine.printState();
    }
    else if (choice == 5)
    {
        std::cout << "Exiting...\n";
        exit(0);
    }
}

void LowLevelMachine::init()
{
    while (true)
    {
        this->printMenu();
        int choice = this->takeInput();
        this->handleChoice(choice);
    }
}