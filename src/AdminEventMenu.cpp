#include "..\include\AdminEventMenu.h"
#include <iomanip>

void AdminEventMenu::display(std::vector<Event> event_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    for(unsigned int i=0;i<event_holder.size();i++)
    {
        std::cout<<'['<<i<<']'<<' ';
        event_holder.at(i).display_heading();
    }
    std::cout<<"[Q] Return to Admin Menu\n";
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}