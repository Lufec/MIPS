#ifndef MIPS_H
#define MIPS_H
#include <iostream>
#include <fstream>
#include <add.h>
#include <alu.h>
#include <alucontrol.h>
#include <control.h>
#include <datamemory.h>
#include <instructionmemory.h>
#include <mux.h>
#include <pc.h>
#include <registers.h>
#include <shift2.h>
#include <signextend.h>

enum memoria{
    $zero = 0,$r1 = 1,$v0 = 2, $v1 = 3, $a0=4, $a1=5, $a2=6, $a3=7,
    $t0 = 8,$t1 = 9,$t2 = 10,$t3 = 11,$t4 = 12,$t5 = 13,$t6 = 14,$t7 = 15,
    $s0 = 16,$s1 = 17,$s2 = 18,$s3 = 19,$s4 = 20,$s5 = 21,$s6 = 22,$s7 = 23,
    $t8 = 24, $t9 = 25, $k0 = 26, $k1 = 27, $gp = 28, $sp = 29, $fp = 30, $ra = 31
};

using namespace std;
class MIPS{
    pc pc;
    instructionMemory instmem;
    control control;
    mux m1;
    registers registers;
    signExtend signExtend;
    mux m2;
    shift2 shift2;
    alucontrol AluControl;
    alu alu;
    datamemory DataMem;
    mux m3;
    add add1;
    add add2;
    mux m4;
    int instructions[16];
public:
  MIPS(int inst[]);
  void setInstructions(std::ifstream instrucoes);
  void executar();

};
#endif // MIPS_H
