#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
using namespace std;

class control
{
    unsigned int instruction;
    unsigned int op;
    unsigned int funct;
    bool RegDst;
    bool Jump;
    bool Branch;
    bool memRead;
    bool memtoReg;
    bool ALUop1;
    bool ALUop2;
    unsigned int ALUI;
    bool memWrite;
    bool ALUSrc;
    bool RegWrite;
public:
    control();
    void set(unsigned int oper);
    void execute();
    bool getRegDst();
    bool getBranch();
    bool getmemRead();
    bool getmemtoReg();
    bool getALUop1();
    bool getALUop2();
    bool getmemWrite();
    bool getALUsrc();
    bool getregWrite();
    unsigned int getALUI();
    bool getJump();
};

#endif // CONTROL_H
