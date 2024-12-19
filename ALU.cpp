#include "ALU.h"
#include "Colors.h"

#include <algorithm>
#include <bitset>
#include <cmath>

ALU::ALU()
{
    this->lookupTableToHex = {{"0000", '0'}, \
                              {"0001", '1'}, \
                              {"0010", '2'}, \
                              {"0011", '3'}, \
                              {"0100", '4'}, \
                              {"0101", '5'}, \
                              {"0110", '6'}, \
                              {"0111", '7'}, \
                              {"1000", '8'}, \
                              {"1001", '9'}, \
                              {"1010", 'A'}, \
                              {"1011", 'B'}, \
                              {"1100", 'C'}, \
                              {"1101", 'D'}, \
                              {"1110", 'E'}, \
                              {"1111", 'F'}};

    this->lookupTableToDec = {{'0', "0000"}, \
                              {'1', "0001"}, \
                              {'2', "0010"}, \
                              {'3', "0011"}, \
                              {'4', "0100"}, \
                              {'5', "0101"}, \
                              {'6', "0110"}, \
                              {'7', "0111"}, \
                              {'8', "1000"}, \
                              {'9', "1001"}, \
                              {'A', "1010"}, \
                              {'B', "1011"}, \
                              {'C', "1100"}, \
                              {'D', "1101"}, \
                              {'E', "1110"}, \
                              {'F', "1111"}};
}

std::string ALU::DecToHex(int num)
{
    std::bitset<8> b(num);
    std::string temp = "";
    std::string hex = "";

    for (int i = 7; i >= 4; --i)
    {
        char c;
        if (b[i])
        {
            c = '1';
        }
        else
        {
            c = '0';
        }
        temp += c;
    }

    hex += this->lookupTableToHex[temp];
    temp = "";

    for (int i = 3; i >= 0; --i)
    {
        char c;
        if (b[i])
        {
            c = '1';
        }
        else
        {
            c = '0';
        }
        temp += c;
    }

    hex += this->lookupTableToHex[temp];

    return hex;
}

int ALU::HexToDec(const std::string& num)
{
    std::string bits = "";
    bits += this->lookupTableToDec[num[0]];
    bits += this->lookupTableToDec[num[1]];

    std::bitset<8> b(bits);
    int dec = b.to_ulong();

    if (b[7] == 1)
    {
        dec -= (1 << 8);
    }

    return dec;
}

std::string ALU::addHexInt(const std::string& n1, const std::string& n2)
{
    int a = this->HexToDec(n1);
    int b = this->HexToDec(n2);
    return this->DecToHex(a + b);
}

std::string ALU::FloatToHex(float num)
{
    int S;
    if (num < 0.0)
    {
        S = 1;
    }
    else
    {
        S = 0;
    }
    if (num < 0.0)
    {
        num = -num;
    }
    int E = 0;
    while (num >= 2.0)
    {
        num /= 2.0;
        ++E;
    }
    while (num < 1.0)
    {
        num *= 2.0;
        --E;
    }
    num -= 1.0;
    E += 4;
    int M = static_cast<int>(num * 16);
    int ans = (S << 7) | (E << 4) | M;
    return this->DecToHex(ans);
}

float ALU::HexToFloat(const std::string& num)
{
    std::string bits = "";
    bits += this->lookupTableToDec[num[0]];
    bits += this->lookupTableToDec[num[1]];

    std::bitset<8> b(bits);
    int S;
    if (b[7])
    {
        S = -1;
    }
    else
    {
        S = 1;
    }
    int E = (b[6] << 2) | (b[5] << 1) | b[4];
    E -= 4;

    float M = 1.0;
    for (int i = 3; i >= 0; --i)
    {
        M += b[i] * std::pow(2, i - 4);
    }

    return S * M * std::pow(2, E);
}

std::string ALU::addHexFloat(const std::string& n1, const std::string& n2)
{
    float a = this->HexToFloat(n1);
    float b = this->HexToFloat(n2);
    return this->FloatToHex(a + b);
}

std::string ALU::OR(const std::string& n1, const std::string& n2)
{
    int a = HexToDec(n1);
    int b = HexToDec(n2);
    return DecToHex(a | b);
}

std::string ALU::AND(const std::string& n1, const std::string& n2)
{
    int a = HexToDec(n1);
    int b = HexToDec(n2);
    return DecToHex(a & b);
}

std::string ALU::XOR(const std::string& n1, const std::string& n2)
{
    int a = HexToDec(n1);
    int b = HexToDec(n2);
    return DecToHex(a ^ b);
}

std::string ALU::rotate(const std::string& n1, const std::string& n2)
{
    int num = ALU::HexToDec(n1);
    int x = ALU::HexToDec(n2);

    return ALU::DecToHex((num >> x) | (num << (8 - x)));
}
