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
    cout<<"ALU: ";
    switch (operacao) {
    case 2: //add
        cout<<"alu selecionou adicao de entradas "<<entrada1<<" e "<<entrada2<<endl;
        saida = entrada1+entrada2;
        break;
    case 6: //sub
        cout<<"alu selecionou subtracao de entradas "<<entrada1<<" e "<<entrada2<<endl;
        saida = entrada1-entrada2;
        break;
    case 0: //and
        cout<<"alu selecionou AND"<<endl;
        saida = entrada1&entrada2;
        break;
    case 1: //or
        cout<<"alu selecionou OR"<<endl;
        saida = entrada1|entrada2;
        break;
    case 9: //xor
        cout<<"alu selecionou XOR"<<endl;
        saida = entrada1^entrada2;
        break;
    case 12: //nor
        cout<<"alu selecionou NOR"<<endl;
        saida = ~(entrada1|entrada2);
        break;
    case 7: //slt
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
