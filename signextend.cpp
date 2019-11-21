#include "signextend.h"

signExtend::signExtend()
{
    saida=0;
}

void signExtend::set(int rt, int shamt, int funct)
{
    saida = (rt<<11) + (shamt<<6) + funct;
    cout<<"SignExtend extendeu sinal"<<endl;
}

int signExtend::getSaida()
{
    return saida;
}
