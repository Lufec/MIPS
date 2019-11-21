#ifndef ADD_H
#define ADD_H
#include <iostream>
using namespace std;

class add
{
    int entrada1;
    int entrada2;
    int saida;
public:
    add();
    void set(int ent1, int ent2);
    void execute();
    int getSaida();
};

#endif // ADD_H
