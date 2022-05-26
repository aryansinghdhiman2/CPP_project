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
        int t=input.tellg();//gets rid of the bug which causes getline to read last line twice.
        //for getting rid of unused variable warning by the compiler
        if(t==-2)
            std::cout<<"This should not be possible\n";
    }
}

void Event::display() const
{
    std::cout<<this->heading<<"\n"<<this->date<<"\n"<<this->description<<"\n";
}

void Event::display_heading() const
{
    std::cout<<this->heading<<"\n";
}

void Event::display_date() const
{
    std::cout<<this->date<<"\n";
}

void Event::display_description() const
{
    std::cout<<this->description<<"\n";
}