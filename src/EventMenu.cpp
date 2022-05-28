#include "..\include\EventMenu.h"

#include <iostream>
#include <iomanip>

void EventMenu::display(const std::vector<Event> &event_holder)
{
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";
    std::cout<<"Upcoming Events: \n";
    for(size_t i=0;i<event_holder.size();i++)
    {
        std::cout<<"Event Name :";
        event_holder.at(i).display_heading();
        std::cout<<"Event Date :";
        event_holder.at(i).display_date();
        std::cout<<"Event Description :";
        event_holder.at(i).display_description();
        std::cout<<std::endl;
    }
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";

}