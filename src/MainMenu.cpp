#include "../include/MainMenu.h"

#include <iomanip>
#include <iostream>



void MainMenu::display()
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    std::cout<<std::setw(24)<<"Main Menu"<<'\n';
    std::cout<<std::setw(6)<<" "<<"[1] Club"<<std::setw(20)<<std::setfill(' ')<<"[2] Events"<<'\n';
    std::cout<<std::setw(6)<<" "<<"[0] Admin"<<std::setw(17)<<std::setfill(' ')<<"[Q] Quit"<<'\n';
    std::cout<<"\n"<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ')<<"\n";
    std::cout<<"Enter corresponding value for Sub-Menu: ";
}