#include "datamemory.h"
#include <iostream>
using namespace std;

datamemory::datamemory()
{
    for(int i=0;i<32;i++){
        data[i]=0;
    }
}

void datamemory::set(int add, int wd, bool mw, bool mr)
{
    address = add;
    writeData = wd;
    memWrite = mw;
    memRead = mr;
}

void datamemory::execute()
{
    if(memWrite){
        cout<<"DataMemory escreveu dados add:"<<address<<" W"<<writeData<<endl;
        data[address] = writeData;
    }

    if(memRead){
        cout<<"DataMemory leu dados"<<endl;
        readData = data[address];
    }
}

void datamemory::printDataMem()
{
    for(int i=0;i<32;i++){
        cout<<"D["<<i<<"] : "<<data[i]<<endl;
    }
}

int datamemory::getReadData()
{
    return readData;
}
