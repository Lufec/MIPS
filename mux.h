#ifndef MUX_H
#define MUX_H

#include <iostream>
using namespace std;

class mux
{
    unsigned int entrada1;
    unsigned int entrada2;
    unsigned int saida;
    bool chave;
public:
    mux();
    void set(unsigned int ent1, unsigned int ent2, bool dec);
    void execute();
    unsigned int getSaida();
};

#endif // MUX_H
