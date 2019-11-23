#include "pc.h"

pc::pc()
{
    saida=0;
}

void pc::set(unsigned int ent)
{
    saida = ent;

    cout<<"PC possui endereco armazenado igual a "<<saida<<endl;
}

unsigned int pc::getSaida()
{
    return saida;
}
