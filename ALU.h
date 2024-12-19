// This header contains the ALU class

#ifndef _ALU_H
#define _ALU_H

#include <string>
#include <unordered_map>

class ALU
{
private:
    std::unordered_map<std::string, char> lookupTableToHex;
    std::unordered_map<char, std::string> lookupTableToDec;
public:
    // Default Constructor
    ALU();
    std::string DecToHex(int num);
    int HexToDec(const std::string& num);
    std::string addHexInt(const std::string& n1, const std::string& n2);
    
    std::string FloatToHex(float num);
    float HexToFloat(const std::string& num);
    std::string addHexFloat(const std::string& n1, const std::string& n2);

    std::string OR(const std::string& n1, const std::string& n2);
    std::string AND(const std::string& n1, const std::string& n2);
    std::string XOR(const std::string& n1, const std::string& n2);
    std::string rotate(const std::string& n1, const std::string& n2);
};

#endif