# LowLevelMachine

## Description
___
This program simulates how a computer operates at a low level<br><br>

## Instruction Set
___
For a working example, check the provided .txt file that prints the first 6 numbers in the fibonacci sequence<br>
**1 *Load***
This instruction is provided with a register and memory address, and the value in the memory is **loaded into** the register
**2 *Load***
This instruction is provided with a register and a bit pattern in **hexa** format, the bit pattern is **loaded into** the register
**3 *Store***
This instruction is provided with a register and memory address, and the value of the register is **stored in** the memory, if the memory address given was 0, the value of the register is printed to the screen
**4 *Move***
This instruction is provided with two registers (R & S), and the value in R is **moved** into S
**5 *Add***
This instruction is provided with three registers(R, S & T), the result of **adding** S and T (int) is stored in R
**6 *Add***
This instruction is provided with three registers(R, S & T), the result of **adding** S and T (float) is stored in R
**7 *OR***
This instruction is provided with three registers(R, S & T), the result of **bitwise OR-ing** S and T is stored in R
**8 *AND***
This instruction is provided with three registers(R, S & T), the result of **bitwise AND-ing** S and T is stored in R
**9 *XOR***
This instruction is provided with three registers(R, S & T), the result of **bitwise XOR-ing** S and T is stored in R
**A *ROTATE***
This instruction is provided with a register and a bit pattern in **hexa**, the register is **bitwise rotated** according to the given bit pattern
**B *Jump***
This instruction is provided with a register and memory address, if the value in the register **equals** register 0, the program counter jumps to the given memory address
**C *Halt***
When reaching this instruction, the machine is signaled to **stop** executing the program
**D *Jump***
This instruction is provided with a register and memory address, if the value in the register is **strictly less than** register 0, the program counter jumps to the given memory address <br><br>

## Compilation
___
To compile with G++ use the following command `g++ -o main.exe *.cpp`
To compile with CMake, add all the .cpp file in the `CMakeLists.txt` then compile the program <br><br>

## How To Use
___
Once you run the `.exe` file you will be greated with the program menu
1) Load Program: Prompts you to enter the .txt file that contains the instructions
2) Run Program: Runs the whole program then displays the values in the registers, memory and the screen
3) Run Current Instruction: Runs the instruction in the memory address pointed to by the program counter
4) Print State: Prints the values in the registers, memory and the screen
5) Exit: Exits the program

**NOTE** This program uses ANSI escape codes to format the output, if you face any issue with the output switch to a different terminal <br><br>

## Author
___
This program was made by [Youssef Elebiary](https://github.com/YoussefElebiary) <br><br>

## Version
___
1.0