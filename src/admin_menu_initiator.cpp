#ifndef _ADMIN_MENU_INITIATOR_

#define _ADMIN_MENU_INITIATOR_

#include <fstream>
#include <iostream>

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/AdminMenu.h"
#include "/Users/gourav/Documents/CPP_project/src/admin_event_menu.cpp"

#else

#include "..\include\AdminMenu.h"
#include "admin_event_menu.cpp"

#endif

void admin_menu_initiator()
{
    AdminMenu menu;
 
    std::cout<<"Going to Admin Menu";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    menu.clear();
    menu.display();

    char input;
    bool should_quit=0;
    for(;;)
    {
        std::cin>>input;
        std::cin.ignore(500,'\n');
        //see comment in club_menu_initiator.cpp under cin.ignore that is there.
        switch (input)
        {
        /*ALl these menu functions will have a Club class object vector passed to them(except admin_event_menu)
        Remove this comment after ensuring this*/
        case '1':
            //admin_club_info_menu();
            break;
        case '2':
            //admin_club_recruitment();
            break;
        case '3':
            //admin_club_meeting();
            break;
        case '4':
            admin_event_menu();
            break;
        case 'q':
        case 'Q':
            should_quit=1;
            break;
        default:
            break;
        }

        if(should_quit)
        {
            std::cout<<"Returning to Main Menu";
            for(int i=0;i<4;i++)
                menu.slow_dots_display();
            break;
        }
        menu.clear();
        menu.display();
    }
}

#endif