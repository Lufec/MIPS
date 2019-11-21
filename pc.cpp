#include "pc.h"

pc::pc()
{
    saida=0;
}

void pc::set(int ent)
{
    saida = ent;
}

int pc::getSaida()
{
    return saida;
}
