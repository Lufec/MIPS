#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
using namespace std;

class registers
{
    int readReg1;
    int readReg2;
    unsigned int writeReg;
    int writeData;
    bool regWrite;
    int regs[32]; //r0, r1, v0-1,a0-3,t0-7,s0-7,t8-9,k0-1,gp,sp,fp,ra
    unsigned int readData1;
    unsigned int readData2;
public:
    registers();
    void set(unsigned int entr1, unsigned int entr2,unsigned int entwr, unsigned int entwd, bool chave);
    void execute();
    void printRegs();
    unsigned int getData1();
    unsigned int getData2();
};

#endif // REGISTERS_H
