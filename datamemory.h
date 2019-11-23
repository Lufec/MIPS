#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <iostream>
using namespace std;

class datamemory
{
    unsigned int address;
    unsigned int writeData;
    bool memWrite;
    bool memRead;
    unsigned int readData;
    unsigned int data[32];
public:
    datamemory();
    void set(unsigned int add,unsigned int wd, bool mw, bool mr);
    void execute();
    void printDataMem();
    unsigned int getReadData();

};

#endif // DATAMEMORY_H
