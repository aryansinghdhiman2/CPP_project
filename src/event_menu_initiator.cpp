#ifndef _EVENT_MENU_INITIATOR_

#define _EVENT_MENU_INITIATOR_
#include "..\include\Event.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
void event_menu_initiator()
{
    try
    {
        system("cls");
        std::vector<Event> event_holder;

        std::fstream event_file("event.txt",std::ios::in);
        if(!event_file.is_open())
        {
            throw -1;
        }
        for(;event_file;)
        {
            Event temp_event(event_file);
            event_holder.push_back(temp_event);
        }
        for(size_t i=0;i<event_holder.size();i++)
        {
            event_holder.at(i).display();
        }

    }
    catch(const int x )
    {
        std::cout<<"File could not be opened\n";
        std::cout<<"Returning to Main Menu.";
        std::this_thread::sleep_for(std::chrono::milliseconds {250});
        std::cout<<".";
        std::this_thread::sleep_for(std::chrono::milliseconds {250});
        std::cout<<".\n";

    }
    

}

#endif