#include "control.h"

control::control()
{

}

void control::set(unsigned int oper)
{
    op = oper;
}

void control::execute()
{
    cout<<"Controle: ";
    switch(op){
    case 0b000000:   //R
        cout<<"Controle recebeu operacao R"<<endl;
        RegDst = 1;
        Jump= 0;
        ALUSrc = 0;
        memtoReg = 0;
        RegWrite = 1;
        memRead = 0;
        memWrite =0;
        Branch = 0;
        ALUop1 = 1;
        ALUop2 = 0;
        ALUI = 0;

        break;
    case 0b001000:  //addi
        cout<<"Controle recebeu operacao ADDI"<<endl;
        RegDst = 0;
        Jump= 0;
        ALUSrc = 1;
        memtoReg = 0;
        RegWrite = 1;
        memRead = 0;
        memWrite =0;
        Branch = 0;
        ALUop1 = 1;
        ALUop2 = 1;
        ALUI = 0;

        break;

    case 0b000010: //j
        cout<<"Controle recebeu operacao JUMP"<<endl;
        RegDst = 0;
        Jump= 1;
        ALUSrc = 0;
        memtoReg = 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 0;
        ALUop1 = 0;
        ALUop2 = 0;
        ALUI = 0;
        break;

    case 0b000100: //beq
        cout<<"Controle recebeu operacao BEQ"<<endl;
        ALUSrc = 0;
        Jump= 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 1;
        ALUop1 = 1;
        ALUop2 = 1;
        ALUI = 5;
        break;

    case 0b000101: //bne
        cout<<"Controle recebeu operacao BNE"<<endl;
        ALUSrc = 0;
        Jump= 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 1;
        ALUop1 = 1;
        ALUop2 = 1;
        ALUI = 6;
        break;

    case 0b000001: //bgez
        cout<<"Controle recebeu operacao BGEZ"<<endl;
        ALUSrc = 0;
        Jump= 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 1;
        ALUop1 = 1;
        ALUop2 = 1;
        ALUI = 11;
        break;


    case 0b000110: //blez
        cout<<"Controle recebeu operacao BLEZ"<<endl;
        ALUSrc = 0;
        Jump= 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 1;
        ALUop1 = 1;
        ALUop2 = 1;
        ALUI = 13;
        break;

    /*case 0b000111: //bgtz
        cout<<"Controle recebeu operacao BGTZ"<<endl;
        ALUSrc = 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 1;
        ALUop1 = 1;
        ALUop2 = 0;
        ALUI = 14;
        break;

    case 0b000100: //bltz
        cout<<"Controle recebeu operacao BLTZ"<<endl;
        ALUSrc = 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =0;
        Branch = 1;
        ALUop1 = 1;
        ALUop2 = 0;
        ALUI = 15;
        break;
      */
    case 0b100011: //lw
        cout<<"Controle recebeu operacao LW"<<endl;
        RegDst = 0;
        Jump= 0;
        ALUSrc = 1;
        memtoReg = 1;
        RegWrite = 1;
        memRead = 1;
        memWrite =0;
        Branch = 0;
        ALUop1 = 1;
        ALUop2 = 1;
        ALUI = 0;
        break;

    case 43: //sw
        cout<<"Controle recebeu operacao SW"<<endl;
        RegDst = 0;
        ALUSrc = 1;
        Jump= 0;
        RegWrite = 0;
        memRead = 0;
        memWrite =1;
        Branch = 0;
        ALUop1 = 1;
        ALUop2 = 1;
        //ALUI = 0;
        break;

    /*case 0b001001: //addiu

        break;
    case 0b001100: //andi

        break;
    case 0b000001: //bgez|bgezal|bltz|bltzal

        break;
    case 0b000111: //bgtz

        break;
    case 0b000110: //blez

        break;

    case 0b000011: //jal

        break;
    case 0b100000: //lb

        break;
    case 0b001111: //lui

        break;
    case 0b001101: //ori

        break;
    case 0b001010: //slti

        break;
    case 0b001011: //sltiu

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

unsigned int control::getALUI()
{
    return ALUI;
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

bool control::getJump()
{
    return Jump;
}







