#include "mips.h"

MIPS::MIPS(pc pc1, instructionMemory im, control ct, mux mux1, registers reg, signExtend sgn, mux mux2, alucontrol alct, alu al, datamemory dm, mux mux3, add addd1, add addd2, mux mux4, mux mux5)
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
   m5 = mux5;
}

void MIPS::setInstructions(unsigned int *inst)
{
    instmem.insertInstructions(inst);
}

bool MIPS::checkSC(unsigned int op, unsigned int funct)
{
    if (op == 0 && funct == 0b1100){
        cout<<"syscall"<<endl<<endl;
        return 1;
    }
    else return 0;
}

bool MIPS::executar()
{
    ///////FETCH///////////
    add1.set(Pc.getSaida(),1);  ///Somador PC
    add1.execute();
    instmem.set(Pc.getSaida()); ///Pega saída de PC
    instmem.execute();
    if(checkSC(instmem.getOp(),instmem.getFunct())){   ////Confere se a instrução chamada é syscall, retorna 0 se sim
        return 0;
    }
    ///////DECODE////////////
    Control.set(instmem.getOp()); ///Recebe OP
    Control.execute();           /// Aciona sinais de comando
    m1.set(instmem.getRt(),instmem.getRd(),Control.getRegDst());  ///Seleciona entrada de registrador
    m1.execute();
    Registers.set(instmem.getRs(),instmem.getRt(),m1.getSaida(),m3.getSaida(),Control.getregWrite());
    Registers.execute();                          ///Recebe as entradas rs,rd,rt e acionador de escrita
    SignExtend.set(instmem.getImediato());        ///Estende sinal imediato (neste código apenas une rd,shamt e imediato
    ///////EXECUTE//////////
    m2.set(Registers.getData2(),SignExtend.getSaida(),Control.getALUsrc());
    m2.execute();                                ///Entrada da ALU entre registrador e imediato
    AluControl.set(Control.getALUop1(),Control.getALUop2(),Control.getALUI(),instmem.getFunct());
    AluControl.execute();                       ///Controlador da ALU decide qual operação dado controlador e funct
    Alu.set(Registers.getData1(),m2.getSaida(),AluControl.getSaida());
    Alu.execute();                              ///ALU realiza operação dado entradas e ALUcontrol
    //////MEMORY ACCESS/////
    DataMem.set(Alu.getSaida(),Registers.getData2(),Control.getmemWrite(),Control.getmemRead());
    DataMem.execute();                          ///Memória é lida ou escrita , dependendo do controle
    m3.set(Alu.getSaida(),DataMem.getReadData(),Control.getmemtoReg());
    m3.execute();                               ///Decisão entre Saída da ALU e da Memória para armazenar no registrador
    Registers.set(instmem.getRs(),instmem.getRt(),m1.getSaida(),m3.getSaida(),Control.getregWrite()); ///caso precise escrever algo
    Registers.execute();                    /// repete execução do registrador, mas com intenção de escrever
    add2.set(add1.getSaida(),SignExtend.getSaida());
    add2.execute();                         ///Realiza a soma do imediato e do end da próxima instrução (branch)
    bool And = Control.getBranch()&&Alu.getZero();  ///Porta AND
    m4.set(add1.getSaida(),add2.getSaida(),And);    ///Decisão entre a soma do BRANCH e a soma do PC
    m4.execute();
    //////WRITE BACK///////
    m5.set(m4.getSaida(),instmem.getJump(),Control.getJump()); ///Decisão entre Soma do PC e endereço de JUMP
    m5.execute();
    Pc.set(m5.getSaida());                  ///PC recebe o que foi decidido anteriormente

    return 1;
}

void MIPS::printRegs()
{
    Registers.printRegs();
}

void MIPS::printDataMem()
{
    DataMem.printDataMem();
}


