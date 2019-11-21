#ifndef DATAMEMORY_H
#define DATAMEMORY_H


class datamemory
{
    int address;
    int writeData;
    bool memWrite;
    bool memRead;
    int readData;
    int data[32];
public:
    datamemory();
    void set(int add,int wd, bool mw, bool mr);
    void execute();
    int getReadData();

};

#endif // DATAMEMORY_H
