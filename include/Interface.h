#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <cstdlib>
#include <iostream>

class Interface
{
    public:
    virtual void display()=0;
    virtual void clear() {system("cls");}
    virtual ~Interface(){};
};

#endif