#include "control.h"

control::control()
{

}

void control::set(int inst)
{
    instruction = inst;
    op = instruction >> 26;
    funct = instruction%32;
}

void control::execute()
{
    switch(op){
    case 0b000000:   //R
        cout<<"Controle recebeu instrucao R"<<endl;
        RegDst = 1;
        ALUSrc = 0;
        memtoReg = 0;
        RegWrite = 1;
        memRead = 0;
        memWrite =1;
        Branch = 0;
        ALUop1 = 1;
        ALUop2 = 0;

        break;
    case 0b001000:  //addi
        cout<<"Controle recebeu instrucao ADDI"<<endl;
        RegDst = 0;
        ALUSrc = 1;
        memtoReg = 0;
        RegWrite = 1;
        memRead = 0;
        memWrite =1;
        Branch = 0;
        ALUop1 = 1;
        ALUop2 = 1;

        break;
    /*case 0b001001: //addiu

        break;
    case 0b001100: //andi

        break;
    case 0b000100: //beq

        break;
    case 0b000001: //bgez|bgezal|bltz|bltzal

        break;
    case 0b000111: //bgtz

        break;
    case 0b000110: //blez

        break;
    case 0b000101: //bne

        break;
    case 0b000010: //j

        break;
    case 0b000011: //jal

        break;
    case 0b100000: //lb

        break;
    case 0b001111: //lui

        break;
    case 0b100011: //lw

        break;
    case 0b001101: //ori

        break;
    case 0b001010: //slti

        break;
    case 0b001011: //sltiu

        break;
    case 0b101011: //sw

        break;
    case 0b001110: //xori

        break; */
    }
}

bool control::getRegDst()
{
    return RegDst;
}

bool control::getBranch()
{
    return Branch;
}

bool control::getmemRead()
{
    return memRead;
}

bool control::getmemtoReg()
{
    return memtoReg;
}

bool control::getALUop1()
{
    return ALUop1;
}

bool control::getALUop2()
{
    return ALUop2;
}

bool control::getmemWrite()
{
    return memWrite;
}

bool control::getALUsrc()
{
    return ALUSrc;
}

bool control::getregWrite()
{
    return RegWrite;
}







