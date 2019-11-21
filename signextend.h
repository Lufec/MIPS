#ifndef SIGNEXTEND_H
#define SIGNEXTEND_H

#include <iostream>
using namespace std;

class signExtend
{
    int saida;
public:
    signExtend();
    void set(int rt, int shamt, int funct);
    int getSaida();
};

#endif // SIGNEXTEND_H
