#include "mips.h"

MIPS::MIPS(pc pc1, instructionMemory im, control ct, mux mux1, registers reg, signExtend sgn, mux mux2, alucontrol alct, alu al, datamemory dm, mux mux3, add addd1, add addd2, mux mux4)
{
   Pc = pc1;
   instmem = im;
   Control = ct;
   m1 = mux1;
   Registers = reg;
   SignExtend = sgn;
   m2 = mux2;
   AluControl = alct;
   Alu = al;
   DataMem = dm;
   m3 = mux3;
   add1 = addd1;
   add2 = addd2;
   m4 = mux4;
}

void MIPS::setInstructions(int *inst)
{
    instmem.insertInstructions(inst);
}
void MIPS::executar()
{
    add1.set(Pc.getSaida(),1);
    add1.execute();

    instmem.set(Pc.getSaida());
    instmem.execute();

    Control.set(instmem.getOp());
    Control.execute();

    m1.set(instmem.getRt(),instmem.getRd(),Control.getRegDst());
    m1.execute();

    Registers.set(instmem.getRs(),instmem.getRt(),m1.getSaida(),m3.getSaida(),Control.getregWrite());
    Registers.execute();

    SignExtend.set(instmem.getRt(),instmem.getShamt(),instmem.getFunct());

    m2.set(Registers.getData2(),SignExtend.getSaida(),Control.getALUsrc());
    m2.execute();

    AluControl.set(Control.getALUop1(),Control.getALUop2(),instmem.getFunct());
    AluControl.execute();

    Alu.set(Registers.getData1(),m2.getSaida(),AluControl.getSaida());
    Alu.execute();

    DataMem.set(Alu.getSaida(),Registers.getData2(),Control.getmemWrite(),Control.getmemRead());
    DataMem.execute();

    m3.set(Alu.getSaida(),DataMem.getReadData(),Control.getmemtoReg());
    m3.execute();

    Registers.set(instmem.getRs(),instmem.getRt(),m1.getSaida(),m3.getSaida(),Control.getregWrite()); //caso precise escrever algo
    Registers.execute();

    add2.set(add1.getSaida(),SignExtend.getSaida());
    add2.execute();

    m4.set(add1.getSaida(),add2.getSaida(),Control.getBranch()&&Alu.getZero());
    m4.execute();

    Pc.set(m4.getSaida());
}



