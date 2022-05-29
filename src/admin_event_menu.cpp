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
        bool has_invalid_input=0;
        for (;;)
        {
            std::cin >> input;
            std::cin.ignore(500, '\n');

            switch (input)
            {
            case '1':
                add_event(event_holder,event_file);
                break;
            case '2':
                edit_event(event_holder,event_file);
                break;
            case '3':
                delete_event(event_holder,event_file);
                break;
            case 'q':
            case 'Q':
                should_quit=1;
                break;
            default:
                std::cout<<"Invalid Input\nPlease Enter Character Again: ";
                has_invalid_input=1;
            }
            if(should_quit)
            {
                std::cout<<"Returning to Admin Menu";
                for(int i=0;i<4;i++)
                    menu.slow_dots_display();
                break;
            }

            event_file.seekp(0);
            event_file.seekg(0);

            event_holder.clear();
            for (;event_file;)
            {
                Event temp_event(event_file);
                event_holder.push_back(temp_event);
            }

            if (!has_invalid_input)
            {
                menu.clear();
                menu.display(event_holder);
                menu.display();
            }
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
    catch(const char x)
    {
        std::cout<<"Returning to Admin Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
    }

    event_file.close();
    
}

#endif