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
        cout<<"alu selecionou adicao"<<endl;
        saida = entrada1+entrada2;
        break;
    case 0x0110: //sub
        cout<<"alu selecionou subtracao"<<endl;
        saida = entrada1-entrada2;
        break;
    case 0x0000: //and
        cout<<"alu selecionou AND"<<endl;
        saida = entrada1&entrada2;
        break;
    case 0x0001: //or
        cout<<"alu selecionou OR"<<endl;
        saida = entrada1|entrada2;
        break;
    case 0x1001: //xor
        cout<<"alu selecionou XOR"<<endl;
        saida = entrada1^entrada2;
        break;
    case 0x1100: //nor
        cout<<"alu selecionou NOR"<<endl;
        saida = ~(entrada1|entrada2);
        break;
    case 0x0111: //slt
        cout<<"alu selecionou Shift Left"<<endl;
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
