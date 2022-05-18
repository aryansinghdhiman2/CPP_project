#include <cstdlib>
#include <iostream>

class Interface
{
    public:
    virtual void display()=0;
    virtual void clear() {system("cls");}

};