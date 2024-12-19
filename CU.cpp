#include "CU.h"
#include "LowLevelMachine.h"
#include "Colors.h"

void CU::loadRegMem(Register& reg, const int& regIdx, Memory& mem, const int& memIdx)
{
    reg.setValue(regIdx, mem.getCell(memIdx));
}

void CU::loadRegVal(Register& reg, const int& regIdx, const int& val)
{
    ALU* alu = new ALU();
    reg.setValue(regIdx, alu->DecToHex(val));
    delete alu;
}

void CU::store(Register& reg, const int& regIdx, Memory& mem, const int& memIdx)
{
    mem.setCell(memIdx, reg.getValue(regIdx));
}

void CU::move(Register& reg, const int& regIdx1, const int& regIdx2)
{
    reg.setValue(regIdx2, reg.getValue(regIdx1));
}

void CU::jump(Register& reg, const int& regIdx, const int& memIdx, int& PC)
{
    if (reg.getValue(0) == reg.getValue(regIdx))
    {
        PC = memIdx;
    }
}

void CU::halt()
{
    isHalt = true;
}