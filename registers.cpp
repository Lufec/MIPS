#include "registers.h"
#include <iostream>
using namespace std;

registers::registers()
{
    for(unsigned int i=0;i<32;i++){
        regs[i] = 0;
    }
    readData1=0;
    readData2=0;
}

string decode(unsigned int reg){
    switch(reg){
    case 0:
        return "$zero";
    case 1:
        return "$r1";
    case 2:
        return "$v0";
    case 3:
        return "$v1";
    case 4:
        return "$a0";
    case 5:
        return "$a1";
    case 6:
        return "$a2";
    case 7:
        return "$a3";
    case 8:
        return "$t0";
    case 9:
        return "$t1";
    case 10:
        return "$t2";
    case 11:
        return "$t3";
    case 12:
        return "$t4";
    case 13:
        return "$t5";
    case 14:
        return "$t6";
    case 15:
        return "$t7";
    case 16:
        return "$s0";
    case 17:
        return "$s1";
    case 18:
        return "$s2";
    case 19:
        return "$s3";
    case 20:
        return "$s4";
    case 21:
        return "$s5";
    case 22:
        return "$s6";
    case 23:
        return "$s7";
    case 24:
        return "$t8";
    case 25:
        return "$t9";
    case 26:
        return "$k0";
    case 27:
        return "$k1";
    case 28:
        return "$gp";
    case 29:
        return "$sp";
    case 30:
        return "$fp";
    case 31:
        return "$ra";
    }
}

void registers::set(unsigned int entr1, unsigned int entr2, unsigned int entwr, unsigned int entwd, bool chave)
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
        cout<<"Registrador realizou operacao de escrita no endereco "<<writeReg<<endl;
        regs[writeReg] = writeData;
    }
    cout<<"Registrador recebeu rd = "<<readReg1<<", rs = "<<readReg2<<endl;
    cout<<"Registrador leu entradas, D1 = "<<regs[readReg1]<<", D2 = "<<regs[readReg2]<<endl;
    readData1 = regs[readReg1];
    readData2 = regs[readReg2];
}

void registers::printRegs()
{
    for(unsigned int i=0;i<32;i++){
        cout<<"Reg "<<decode(i)<<" : "<<regs[i]<<endl;
    }
}

unsigned int registers::getData1()
{
    return readData1;
}

unsigned int registers::getData2()
{
    return readData2;
}

