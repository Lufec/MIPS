#include "mux.h"

mux::mux()
{
    entrada1 = 0;
    entrada2 = 0;
    saida = 0;
    chave = 0;
}

void mux::set(unsigned int ent1, unsigned int ent2, bool dec)
{
    entrada1 = ent1;
    entrada2 = ent2;
    chave = dec;
}

void mux::execute()
{
    if(!chave){
        cout<<"Mux selecionou entrada 0"<<endl;
        saida = entrada1;
    }
    else{
        cout<<"Mux selecionou entrada 1"<<endl;
        saida = entrada2;
    }
}

unsigned int mux::getSaida()
{
    return saida;
}
