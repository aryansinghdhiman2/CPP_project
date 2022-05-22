#include "..\include\Event.h"
#include <string>
#include <iostream>
Event::Event(std::fstream &input)
{
    if(input)
    {
        std::getline(input,this->heading);
        std::getline(input,this->date);
        std::getline(input,this->description);
        int t=input.tellg();
    }
}

void Event::display()
{
    std::cout<<this->heading<<"\n"<<this->date<<"\n"<<this->description<<"\n";
}