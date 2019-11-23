#ifndef ALUCONTROL_H
#define ALUCONTROL_H

#include <iostream>
using namespace std;

class alucontrol
{
    bool chave1;
    bool chave2;
    unsigned int ALUI;
    unsigned int funct;
    unsigned int AluChave;
public:
    alucontrol();
    void set(bool ALUop1, bool ALUop2,unsigned int ALUI, unsigned int fun);
    void execute();
    unsigned int getSaida();
};

#endif // ALUCONTROL_H
