#include "datamemory.h"

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
        data[address] = writeData;
    }
    if(memRead){
        readData = data[address];
    }
}

int datamemory::getReadData()
{
    return readData;
}
