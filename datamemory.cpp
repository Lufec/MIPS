#include "datamemory.h"
#include <iostream>
using namespace std;

datamemory::datamemory()
{
    for(unsigned int i=0;i<32;i++){
        data[i]=0;
    }
}

void datamemory::set(unsigned int add, unsigned int wd, bool mw, bool mr)
{
    address = add;
    writeData = wd;
    memWrite = mw;
    memRead = mr;
}

void datamemory::execute()
{
    if(memWrite){
        cout<<"DataMemory escreveu dados em end:"<<address<<", valor "<<writeData<<endl;
        data[address] = writeData;
    }

    if(memRead){
        cout<<"DataMemory leu dados de end "<<address<<", valor "<<data[address]<<endl;
        readData = data[address];
    }
}

void datamemory::printDataMem()
{
    for(unsigned int i=0;i<32;i++){
        cout<<"D["<<i<<"] : "<<data[i]<<endl;
    }
}

unsigned int datamemory::getReadData()
{
    return readData;
}
