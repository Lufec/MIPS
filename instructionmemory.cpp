#include "instructionmemory.h"

instructionMemory::instructionMemory()
{
    for(int i=0;i<16;i++){
        memory[i] = 0;
    }
    op=0;
    rd=0;
    rs=0;
    rt=0;
    shamt=0;
    funct=0;
}

void instructionMemory::insertInstructions(int inst[])
{
    for(int i=0;i<16;i++){
        memory[i] = inst[i];
    }
}

void instructionMemory::set(int readAd)
{
    readAdress = readAd;
}

void instructionMemory::execute()
{
    cout<<"InstructionMemory decodificou instrucao"<<endl;
    int inst = memory[readAdress];
    funct = inst%64;
    int aux = inst>>6;
    shamt = aux%32;
    inst = inst>>11;
    rd = inst%32;
    inst = inst>>5;
    rt = inst%32;
    inst = inst>>5;
    rs = inst%32;
    inst = inst>>5;
    op = inst;
}

int instructionMemory::getOp()
{
    return op;
}

int instructionMemory::getRd(){
    return rd;
}

int instructionMemory::getRs(){
    return rs;
}

int instructionMemory::getRt(){
    return rt;
}

int instructionMemory::getShamt(){
    return shamt;
}

int instructionMemory::getFunct(){
    return funct;
}
