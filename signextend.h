#ifndef SIGNEXTEND_H
#define SIGNEXTEND_H

#include <iostream>
using namespace std;

class signExtend
{
    unsigned int saida;
public:
    signExtend();
    void set(unsigned int imediato);
    unsigned int getSaida();
};

#endif // SIGNEXTEND_H
