#include "alucontrol.h"

alucontrol::alucontrol()
{
    AluChave = 0;
}

void alucontrol::set(bool ALUop1, bool ALUop2, int fun)
{
    chave1 = ALUop1;
    chave2 = ALUop2;
    funct = fun;
}

void alucontrol::execute()
{
      if(chave1&&!chave2){ //R aritmetico
          switch (funct) {
          case 0b100000: //add
              cout<<"AluControl selecionou adicao"<<endl;
              AluChave = 0b0010;
              break;

          case 0b100010: //sub
              cout<<"AluControl selecionou subtracao"<<endl;
              AluChave = 0110;
              break;

          case 0b100100: //and
              AluChave = 0;
              break;

          case 0b100101: //add
              AluChave = 1;
              break;

          case 0b101100: //xor
              AluChave = 0b1001;
              break;

          case 0b101010: //slt
              AluChave = 0b0111;
              break;
          //caso nor tem q achar
          }
      }
      if(chave1&&chave2){

      }

}

int alucontrol::getSaida()
{
    return AluChave;
}

