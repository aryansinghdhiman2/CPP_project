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
    virtual void clear()
    {
        #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
            system("cls");

        #else
            system("clear");//for UNIX systems
        #endif
    }
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