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
          case 0x100000: //add
              AluChave = 0x0010;
              break;

          case 0x100010: //sub
              AluChave = 0110;
              break;

          case 0x100100: //and
              AluChave = 0;
              break;

          case 0x100101: //add
              AluChave = 1;
              break;

          case 0x101100: //xor
              AluChave = 0x1001;
              break;

          case 0x101010: //slt
              AluChave = 0x0111;
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

