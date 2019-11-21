#include "alu.h"

alu::alu()
{

}

void alu::set(int ent1, int ent2, int op)
{
    entrada1=ent1;
    entrada2=ent2;
    operacao = op;
}

void alu::execute()
{
    switch (operacao) {
    case 0x0010: //add
        saida = entrada1+entrada2;
        break;
    case 0x0110: //sub
        saida = entrada1-entrada2;
        break;
    case 0x0000: //and
        saida = entrada1&entrada2;
        break;
    case 0x0001: //or
        saida = entrada1|entrada2;
        break;
    case 0x1001: //xor
        saida = entrada1^entrada2;
        break;
    case 0x1100: //nor
        saida = ~(entrada1|entrada2);
        break;
    case 0x0111: //slt
        saida = (entrada1<entrada2)?1:0;
    }
}

int alu::getSaida()
{
    return saida;
}

bool alu::getZero()
{
    return zero;
}
