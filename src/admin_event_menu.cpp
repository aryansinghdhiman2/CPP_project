#ifndef _ADMIN_EVENT_MENU_

#define _ADMIN_EVENT_MENU_

#include "..\include\AdminEventMenu.h"
#include "admin_event_helper_functions.cpp"
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

        menu.display(event_holder);
        menu.display();
        
        char input;
        bool should_quit=0;
        for (;;)
        {
            std::cin >> input;
            std::cin.ignore(500, '\n');

            switch (input)
            {
            case '1':
                menu.clear();
                add_event(event_holder,event_file);
                break;
            case '2':
                menu.clear();
                // edit_event(event_holder);
                break;
            case 'q':
            case 'Q':
                should_quit=1;
                break;
            }
            if(should_quit)
            {
                std::cout<<"Returning to Admin Menu";
                for(int i=0;i<4;i++)
                    menu.slow_dots_display();
                break;
            }
            menu.clear();
            menu.display(event_holder);
            menu.display();
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