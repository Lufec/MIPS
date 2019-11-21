#include "registers.h"
#include <iostream>
using namespace std;

registers::registers()
{
    for(int i=0;i<32;i++){
        regs[i] = 0;
    }
    readData1=0;
    readData2=0;
}

void registers::set(int entr1, int entr2, int entwr, int entwd, bool chave)
{
    readReg1 = entr1;
    readReg2 = entr2;
    writeReg = entwr;
    writeData = entwd;
    regWrite = chave;
}

void registers::execute()
{
    if(regWrite){
        regs[writeReg] = writeData;
    }
    readData1 = regs[readReg1];
    readData2 = regs[readReg2];
}

void registers::printRegs()
{
    for(int i=0;i<32;i++){
        cout<<"Reg["<<i<<"] : "<<regs[i]<<endl;
    }
}

int registers::getData1()
{
    return readData1;
}

int registers::getData2()
{
    return readData2;
}

