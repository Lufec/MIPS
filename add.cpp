#include "add.h"

add::add()
{
    entrada1 = 0;
    entrada2 = 0;
    saida = 0;
}

void add::set(int ent1, int ent2)
{
    entrada1 = ent1;
    entrada2 = ent2;
}

void add::execute()
{
    saida = entrada1+entrada2;
}

int add::getSaida()
{
    return saida;
}
