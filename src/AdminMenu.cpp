#include "..\include\AdminMenu.h"
#include <iomanip>

void AdminMenu::display()
{
    std::cout<<"Going to Admin Menu";
    for(int i=0;i<4;i++)
    {
        this->slow_dots_display();
    }

    this->clear();

    std::cout<<std::setw(55)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    std::cout<<std::setw(27)<<"Admin Menu"<<"\n\n";
    std::cout<<std::setw(2)<<" "<<"[1] Club Information"<<std::setw(23)<<std::setfill(' ')<<"[2] Club Recruitment"<<'\n';
    std::cout<<std::setw(2)<<" "<<"[3] Club Meeting"<<std::setw(17)<<std::setfill(' ')<<"[4] Events"<<'\n';
    std::cout<<"\n"<<std::setw(19)<<" "<<"[Q] Quit"<<"\n";
    std::cout<<"\n"<<std::setw(55)<<std::setfill('*')<<"\n"<<std::setfill(' ')<<"\n";
    std::cout<<"Enter corresponding value for Sub-Menu: ";
}