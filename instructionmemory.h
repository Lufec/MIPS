#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <iostream>
using namespace std;

class instructionMemory
{
    unsigned int readAdress;
    unsigned int op;
    unsigned int rs;
    unsigned int rt;
    unsigned int rd;
    unsigned int shamt;
    unsigned int funct;
    unsigned int imediato;
    unsigned int jump;
    unsigned int memory[16];
public:
    instructionMemory();
    void insertInstructions(unsigned int inst[]);
    void set(unsigned int readAd);
    void execute();
    unsigned int getOp();
    unsigned int getRs();
    unsigned int getRt();
    unsigned int getRd();
    unsigned int getShamt();
    unsigned int getFunct();
    unsigned int getImediato();
    unsigned int getJump();
};

#endif // INSTRUCTIONMEMORY_H
