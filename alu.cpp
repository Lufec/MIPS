#include "alu.h"

alu::alu()
{

}

void alu::set(int ent1, int ent2, unsigned int op)
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
        break;
    case 4: //beq --
        cout<<"Alu selecionou comparar igualdade"<<endl;
        zero = (entrada1==entrada2)?1:0;
        break;
    case 10: //bne
        cout<<"Alu selecionou comparar desigualdade"<<endl;
        zero = (entrada1!=entrada2)?1:0;
        break;
    case 11: //bgez
        cout<<"Alu selecionou maior igual"<<endl;
        zero = (entrada1>=entrada2)?1:0;
        break;
    case 13: //blez
        cout<<"Alu selecionou menor igual"<<endl;
        zero = (entrada1<=entrada2)?1:0;
        break;
    case 14: //bgtz
        cout<<"Alu selecionou maior"<<endl;
        zero = (entrada1>entrada2)?1:0;
        break;
    case 15: //bltz
        cout<<"Alu selecionou menor"<<endl;
        zero = (entrada1>entrada2)?1:0;
        break;
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
