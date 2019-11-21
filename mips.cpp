#include "mips.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

MIPS::MIPS(int inst[]){
    for(int i=0;i<16;i++){
        instructions[i]=inst[i];
    }
    instructionMemory::instructionMemory(instructions);
}

void MIPS::setInstructions(ifstream mipsFile)
{
    mipsFile.open("E:/Documentos/UFRN/Atividades/MIPS/MIPS/testar.txt");
    vector<string> linhas;      //O vetor recebe todas as linhas do arquivo
    string linhaAtual, comando;
    if(mipsFile.is_open()){
        while(getline(mipsFile, linhaAtual)){
            linhas.push_back( linhaAtual);
        }
    }
    else{
        cout << "Erro ao abrir o arquivo" << endl;
        exit(0);
    }
    for(int i=0; i<linhas.size(); i++){
        int op,rd,rs,rt,shamt,funct,imediato,endereco;
        memoria mem;
        stringstream instrucao(linhas[i]);
        instrucao >> comando; //Cada instrução lida pela linha irá para uma string comandoMIPS que selecionará a ação.
        if (comando == "add"){
            op=0;
            funct = 0x100000;
            shamt = 0;
            instrucao >> comando;
            // Passar bin de rd,rs,rt
            //combinar pra formar uma instrucao binaria
            //passar para instructionMemory

        }else if(comando == "addi"){
            op = 0x001000;
            //pegar rd,rs,imediato;
            //mesma coisa acima

        }else if(comando == "sub"){
            op = 0;
            shamt = 0;
            funct = 0x100010;
            //pegar rd,rs,rt
            //mesma coisa acima
        }
    }
}

void MIPS::executar()
{
    add1.set(pc.getSaida(),1);
    add1.execute();

    instmem.set(pc.getSaida());
    instmem.execute();

    control.set(instmem.getOp());
    control.execute();

    m1.set(instmem.getRt(),instmem.getRd(),control.getRegDst());
    m1.execute();

    registers.set(instmem.getRs(),instmem.getRt(),m1.getSaida(),m3.getSaida(),control.getregWrite());
    registers.execute();

    signExtend.set(instmem.getRt(),instmem.getShamt(),instmem.getFunct());

    m2.set(registers.getData2(),signExtend.getSaida(),control.getALUsrc());
    m2.execute();

    AluControl.set(control.getALUop1(),control.getALUop2(),instmem.getFunct());
    AluControl.execute();

    alu.set(registers.getData1(),m2.getSaida(),AluControl.getSaida());
    alu.execute();

    DataMem.set(alu.getSaida(),registers.getData2(),control.getmemWrite(),control.getmemRead());
    DataMem.execute();

    m3.set(alu.getSaida(),DataMem.getReadData(),control.getmemtoReg());
    m3.execute();

    registers.set(instmem.getRs(),instmem.getRt(),m1.getSaida(),m3.getSaida(),control.getregWrite()); //caso precise escrever algo
    registers.execute();

    add2.set(add1.getSaida(),signExtend.getSaida());
    add2.execute();

    m4.set(add1.getSaida(),add2.getSaida(),control.getBranch()&&alu.getZero());
    m4.execute();

    pc.set(m4.getSaida());
}




