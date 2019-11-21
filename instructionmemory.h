#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H


class instructionMemory
{
    int readAdress;
    int op;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
    int memory[16];
public:
    instructionMemory();
    void insertInstructions(int inst[]);
    void set(int readAd);
    void execute();
    int getOp();
    int getRs();
    int getRt();
    int getRd();
    int getShamt();
    int getFunct();
};

#endif // INSTRUCTIONMEMORY_H
