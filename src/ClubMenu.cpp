#include "../include/ClubMenu.h"

#include <iomanip>
#include <iostream>

void ClubMenu::display()
{
    std::cout<<"Going to Club Menu";
    for(int i=0;i<4;i++)
    {
        this->slow_dots_display();
    }

    this->clear();
    
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    std::cout<<std::setw(24)<<"Club Menu"<<'\n';
    std::cout<<"[1] Club Information"<<std::setw(25)<<std::setfill(' ')<<"[2] Club Recruitment"<<'\n';
    std::cout<<"[3] Club Meeting Menu"<<std::setw(27)<<std::setfill(' ')<<"[Q] Return to Main Menu"<<'\n';
    std::cout<<"\n"<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ')<<"\n";
    std::cout<<"Enter corresponding value for Sub-Menu: ";
}