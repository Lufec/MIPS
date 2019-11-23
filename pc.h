#ifndef PC_H
#define PC_H

#include <iostream>
using namespace std;

class pc
{
    unsigned int saida;
public:
    pc();
    void set(unsigned int ent);
    unsigned int getSaida();
};

#endif // PC_H
