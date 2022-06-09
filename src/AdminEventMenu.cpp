#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/AdminEventMenu.h"

#else

#include "..\include\AdminEventMenu.h"

#endif

#include <iomanip>

void AdminEventMenu::display(std::vector<Event> event_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    int i=0;
    for(auto t=event_holder.begin();t!=event_holder.end();t++,i++)
    {
        std::cout<<'['<<i<<']'<<' ';
        t->display_heading();
    }
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}

void AdminEventMenu::display()
{
    std::cout<<"[1] New Event"<<std::setw(18)<<"[2] Edit Event"<<std::setw(28)<<'\n';
    std::cout<<"[3] Delete Event"<<std::setw(25)<<"[Q] Return to Admin Menu"<<'\n';
    std::cout<<"Enter Input corresponding to Action to be performed: ";
}