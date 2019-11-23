#ifndef ADD_H
#define ADD_H
#include <iostream>
using namespace std;

class add
{
    unsigned int entrada1;
    unsigned int entrada2;
    unsigned int saida;
public:
    add();
    void set(unsigned int ent1, unsigned int ent2);
    void execute();
    unsigned int getSaida();
};

#endif // ADD_H
