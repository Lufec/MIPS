#ifndef ALU_H
#define ALU_H

#include <iostream>
using namespace std;

class alu
{
    unsigned int entrada1;
    unsigned int entrada2;
    unsigned int operacao;
    unsigned int saida;
    bool zero = 0;
public:
    alu();
    void set(unsigned int ent1, unsigned int ent2, unsigned int op);
    void execute();
    unsigned int getSaida();
    bool getZero();
};

#endif // ALU_H
