#include "pc.h"

pc::pc()
{
    saida=0;
}

void pc::set(int ent)
{
    saida = ent;

    cout<<"PC possui endereco armazenado igual a "<<saida<<endl;
}

int pc::getSaida()
{
    return saida;
}
