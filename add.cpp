#include "add.h"

add::add()
{
    entrada1 = 0;
    entrada2 = 0;
    saida = 0;
}

void add::set(unsigned int ent1, unsigned int ent2)
{
    entrada1 = ent1;
    entrada2 = ent2;
}

void add::execute()
{
    cout<<"ADD de enderecos: Realizou soma "<<entrada1<<" + "<<entrada2<<endl;
    saida = entrada1+entrada2;
}

unsigned int add::getSaida()
{
    return saida;
}
