#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/ClubMenu.h"

#else

#include "../include/ClubMenu.h"

#endif

#include <iomanip>
#include <iostream>

void ClubMenu::display()
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    std::cout<<std::setw(24)<<"Club Menu"<<'\n';
    std::cout<<"[1] Club Information"<<std::setw(25)<<std::setfill(' ')<<"[2] Club Recruitment"<<'\n';
    std::cout<<"[3] Club Meeting Menu"<<std::setw(27)<<std::setfill(' ')<<"[Q] Return to Main Menu"<<'\n';
    std::cout<<"\n"<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ')<<"\n";
    std::cout<<"Enter corresponding value for Sub-Menu: ";
}