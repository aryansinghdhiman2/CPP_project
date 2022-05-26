#ifndef _ADMIN_MENU_INITIATOR_

#define _ADMIN_MENU_INITIATOR_

#include <iostream>
#include "..\include\AdminMenu.h"

void admin_menu_initiator()
{
    AdminMenu menu;
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
            //admin_event_menu();
            break;
        case 'q':
        case 'Q':
            should_quit=1;
            break;
        default:
            break;
        }

        if(should_quit)
            break;
        
        menu.display();
    }
}

#endif