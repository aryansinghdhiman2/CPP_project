#ifndef _ADMIN_EVENT_MENU_

#define _ADMIN_EVENT_MENU_

#include "..\include\AdminEventMenu.h"
#include <fstream>
#include <vector>

void admin_event_menu()
{
    AdminEventMenu menu;
    std::cout<<"Going to Events";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }

    menu.clear();

    std::fstream event_file("event.txt",std::ios::in|std::ios::app|std::ios::out);
    try
    {
        if(!event_file.is_open())
        {
            throw -1;
        }

        std::vector<Event> event_holder;

        for(;event_file;)
        {
            Event temp_event(event_file);
            event_holder.push_back(temp_event);
        }
        

    }
    catch(const int x)
    {
        menu.clear();
        std::cout<<"File could not be opened\n";
        std::cout<<"Returning to Admin Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
    }
    
}

#endif