#ifndef REGISTERS_H
#define REGISTERS_H
#include <iostream>

class registers
{
    int readReg1;
    int readReg2;
    int writeReg;
    int writeData;
    bool regWrite;
    int regs[32]; //r0, r1, v0-1,a0-3,t0-7,s0-7,t8-9,k0-1,gp,sp,fp,ra
    int readData1;
    int readData2;
public:
    registers();
    void set(int entr1, int entr2,int entwr, int entwd, bool chave);
    void execute();
    void printRegs();
    int getData1();
    int getData2();
};

#endif // REGISTERS_H
