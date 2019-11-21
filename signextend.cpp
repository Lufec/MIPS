#include "signextend.h"

signExtend::signExtend()
{
    saida=0;
}

void signExtend::set(int imediato)
{
    saida = imediato;
    cout<<"SignExtend extendeu sinal, valor = "<<saida<<endl;
}

int signExtend::getSaida()
{
    return saida;
}
