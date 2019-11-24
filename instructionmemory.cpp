#include "instructionmemory.h"

instructionMemory::instructionMemory()
{
    for(unsigned int i=0;i<32;i++){
        memory[i] = 0;
    }
    op=0;
    rd=0;
    rs=0;
    rt=0;
    shamt=0;
    funct=0;
    jump = 0;
    imediato = 0;
}

void instructionMemory::insertInstructions(unsigned int inst[])
{
    for(unsigned int i=0;i<32;i++){
        memory[i] = inst[i];
    }
}

void instructionMemory::set(unsigned int readAd)
{
    readAdress = readAd;
}

void instructionMemory::execute()
{
    cout<<"InstructionMemory decodificou instrucao"<<endl;
    unsigned int inst = memory[readAdress];
    imediato = inst%32768; //15 bits
    jump = inst%33554432; //25 bits
    funct = inst%64;
    unsigned int aux = inst>>6;
    shamt = aux%32;
    inst = inst>>11;
    rd = inst%32;
    inst = inst>>5;
    rt = inst%32;
    inst = inst>>5;
    rs = inst%32;
    inst = inst>>5;
    op = inst;
    cout<<" op = "<<op<<", rs = "<<rs<<", rt = "<<rt<<", rd = "<<rd<<", shamt = "<<shamt<<", funct = "<<funct<<", imediato = "<<imediato<<endl;
}

unsigned int instructionMemory::getOp()
{
    return op;
}

unsigned int instructionMemory::getRd(){
    return rd;
}

unsigned int instructionMemory::getRs(){
    return rs;
}

unsigned int instructionMemory::getRt(){
    return rt;
}

unsigned int instructionMemory::getShamt(){
    return shamt;
}

unsigned int instructionMemory::getFunct(){
    return funct;
}

unsigned int instructionMemory::getImediato()
{
    return imediato;
}
unsigned int instructionMemory::getJump()
{
    return jump;
}
