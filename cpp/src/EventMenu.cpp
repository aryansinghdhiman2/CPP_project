#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/EventMenu.h"

#else

#include "..\include\EventMenu.h"

#endif

#include <iostream>
#include <iomanip>

void EventMenu::display(const std::vector<Event> &event_holder)
{
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";
    std::cout<<"Upcoming Events: \n";
    int i=0;
    for(auto t = event_holder.begin();t!=event_holder.end();t++,i++)
    {
        std::cout<<"Event Name :";
        t->display_heading();
        std::cout<<"Event Date :";
        t->display_date();
        std::cout<<"Event Description :";
        t->display_description();
        std::cout<<std::endl;
    }
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";

}