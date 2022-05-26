#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

class Interface
{
    public:
    virtual void display()=0;
    virtual void clear() {system("cls");}
    virtual void slow_dots_display(){
        std::this_thread::sleep_for(std::chrono::milliseconds {350});
        std::cout<<".";
    }
    virtual void slow_dots_display(int milli){
        std::this_thread::sleep_for(std::chrono::milliseconds {milli});
        std::cout<<".";
    }
    virtual ~Interface(){};
};

#endif