// This header contains the Memory class

#ifndef _MEMORY_H
#define _MEMORY_H

#include <string>

class Memory
{
private:
    std::string cells[256];
public:
    Memory();
    std::string getCell(const int& address);
    std::string getCell(const std::string& address);
    void setCell(const int& address, const std::string& value);
    void setCell(const std::string& address, const std::string& value);
};

#endif