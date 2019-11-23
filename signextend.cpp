#include "signextend.h"

signExtend::signExtend()
{
    saida=0;
}

void signExtend::set(unsigned int imediato)
{
    saida = imediato;
    cout<<"SignExtend extendeu sinal, valor = "<<saida<<endl;
}

unsigned int signExtend::getSaida()
{
    return saida;
}
