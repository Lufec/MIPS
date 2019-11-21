#ifndef ALUCONTROL_H
#define ALUCONTROL_H

#include <iostream>
using namespace std;

class alucontrol
{
    bool chave1;
    bool chave2;
    int funct;
    int AluChave;
public:
    alucontrol();
    void set(bool ALUop1, bool ALUop2, int fun);
    void execute();
    int getSaida();
};

#endif // ALUCONTROL_H
