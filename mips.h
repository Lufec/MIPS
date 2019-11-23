#ifndef MIPS_H
#define MIPS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <add.h>
#include <alu.h>
#include <alucontrol.h>
#include <control.h>
#include <datamemory.h>
#include <instructionmemory.h>
#include <mux.h>
#include <pc.h>
#include <registers.h>
#include <signextend.h>

using namespace std;

class MIPS{
    pc Pc;
    instructionMemory instmem;
    control Control;
    mux m1;
    registers Registers;
    signExtend SignExtend;
    mux m2;
    alucontrol AluControl;
    alu Alu;
    datamemory DataMem;
    mux m3;
    add add1;
    add add2;
    mux m4;
    mux m5;
    unsigned int instrucao;
public:
  MIPS(pc pc1,instructionMemory im,control ct, mux mux1, registers reg, signExtend sgn, mux mux2, alucontrol alct, alu al, datamemory dm,mux mux3, add addd1, add addd2, mux mux4, mux mux5);
  void setInstructions(unsigned int *inst);
  bool executar();
  void printRegs();
  void printDataMem();
  bool checkSC(unsigned int op, unsigned int jmp);
};
#endif // MIPS_H
