#include "signextend.h"

signExtend::signExtend()
{
    saida=0;
}

void signExtend::set(int rt, int shamt, int funct)
{
    saida = (rt<<11) + (shamt<<6) + funct;
}

int signExtend::getSaida()
{
    return saida;
}
