#ifndef ALU_H
#define ALU_H

#include <iostream>
using namespace std;

class alu
{
    int entrada1;
    int entrada2;
    unsigned int operacao;
    int saida;
    bool zero = 0;
public:
    alu();
    void set(int ent1, int ent2, unsigned int op);
    void execute();
    int getSaida();
    bool getZero();
};

#endif // ALU_H
