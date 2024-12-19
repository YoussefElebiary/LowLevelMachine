// This header contains the Register class

#ifndef _REGISTER_H
#define _REGISTER_H

#include <string>

class Register
{
private:
    // Represents the Register
    std::string registers[16];
public:
    // Default Constructor
    Register();
    /**
     * @brief Takes the index of the register and adds `value` in it
     * @param address Represents the index of the register in decimal form
     * @param value Represents the value to be added in the register
     */
    void setValue(const int& address, const std::string& value);
    /**
     * @brief Takes the `address` of the register and adds `value` in it
     * @param address Represents the address of the register in hexa form
     * @param value Represents the value to be added in the register
     */
    void setValue(const std::string& address, const std::string& value);
    /**
     * @brief Returns the value in the register at the given index
     * @param address Represents the index of the register in decimal form
     * @return Returns the value in the register in hex form
     */
    std::string getValue(const int& address);
    /**
     * @brief Returns the value in the register at the given index
     * @param address Represents the address of the register in hexa form
     * @return Returns the value in the register in hex form
     */
    std::string getValue(const std::string& address);
};

#endif