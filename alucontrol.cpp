#include "alucontrol.h"

alucontrol::alucontrol()
{
    AluChave = 0;
}

void alucontrol::set(bool ALUop1, bool ALUop2, unsigned int ALUi, unsigned int fun)
{
    chave1 = ALUop1;
    chave2 = ALUop2;
    ALUI = ALUi;
    funct = fun;
}

void alucontrol::execute()
{
      cout<<"ALUControl: ";
      if(chave1&&!chave2){ //R aritmetico
          switch (funct) {
          case 0b100000: //add
              cout<<"AluControl selecionou adicao"<<endl;
              AluChave = 0b0010;
              break;

          case 0b100010: //sub
              cout<<"AluControl selecionou subtracao"<<endl;
              AluChave = 0b0110;
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
          if(ALUI == 0){
              cout<<"Addi"<<endl;
              AluChave = 0b0010;
          }
          else if(ALUI == 1){
              cout<<"Subi"<<endl;

          }
          else if(ALUI == 2){
              cout<<"ANDI"<<endl;

          }
          else if(ALUI == 3){
              cout<<"ORI"<<endl;

          }
          else if(ALUI ==4){
              cout<<"XORI"<<endl;

          }
          else if(ALUI == 5){
              cout<<"BEQ"<<endl;
              AluChave = 4;
          }
          else if(ALUI == 6){
              cout<<"BNE"<<endl;
              AluChave = 10;
          }
          else if(ALUI == 7){
              cout<<"BGEZ"<<endl;
              AluChave = 11;
          }
          else if(ALUI == 8){
              cout<<"BLEZ"<<endl;
              AluChave = 13;
          }
          else if(ALUI == 9){
              cout<<"BGTZ"<<endl;
              AluChave = 14;
          }
          else if(ALUI == 10){
              cout<<"BLTZ"<<endl;
              AluChave = 15;
          }
      }

}

unsigned int alucontrol::getSaida()
{
    return AluChave;
}

