#ifndef _EVENT_MENU_INITIATOR_

#define _EVENT_MENU_INITIATOR_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Event.h"
#include "/Users/gourav/Documents/CPP_project/include/EventMenu.h"

#else
#include "..\include\Event.h"
#include "..\include\EventMenu.h"

#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
void event_menu_initiator()
{
    EventMenu menu;
    std::cout<<"Going to Events";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    try
    {
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
        menu.clear();
        menu.display(event_holder);
        std::cout<<"Input any character to go back to Main Menu"<<std::endl;
        char ch;
        std::cin>>ch;//for holding screen
        event_file.close();

        if(event_file.is_open())
            throw '1';

        std::cout<<"Returning to Main Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
    }
    catch(const int x )
    {
        menu.clear();
        std::cout<<"File could not be opened\n";
        std::cout<<"Returning to Main Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();

    }
    catch(const char c)
    {
        std::cout<<"File could not be closed\n";
        std::cout<<"Returning to Main Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
    }
    

}

#endif