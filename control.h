#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
using namespace std;

class control
{
    int instruction;
    int op;
    int funct;
    bool RegDst;
    bool Branch;
    bool memRead;
    bool memtoReg;
    bool ALUop1;
    bool ALUop2;
    int ALUI;
    bool memWrite;
    bool ALUSrc;
    bool RegWrite;
public:
    control();
    void set(int oper);
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
    int getALUI();
};

#endif // CONTROL_H
