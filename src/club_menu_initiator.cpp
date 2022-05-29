#ifndef _CLUB_MENU_INITIATOR_

#define _CLUB_MENU_INITIATOR_

#include <iostream>
#include "../include/ClubMenu.h"
#include "club_meeting_menu.cpp"
#include "club_recruitment_menu.cpp"
#include "clubs_info_menu.cpp"

//Random Change

void club_menu_initiator()
{
    ClubMenu menu;
    std::cout<<"Going to Club Menu";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    menu.clear();
    menu.display();
    
    char input;
    bool should_quit=0;
    bool has_invalid_input=0;
    for(;;)
    {
        std::cin>>input;
        std::cin.ignore(500,'\n');
        /*ignores any extra input given .Skips over atmost 500 characters until it finds a newline.
        If not used and then if user types "qq" program will quit ClubMenu and then quit MainMenu too.*/
        switch (input)
        {
        /*ALl these menu functions will have a Club class object vector passed to them
        Remove this comment after ensuring this*/
        case '1':
            clubs_info_menu();
            break;
        case '2':
            club_recruitment_menu();
            break;
        case '3':
            club_meeting_menu();
            break;
        case 'Q':
        case 'q':
            should_quit=1;
            break;
        default:
            std::cout<<"Invalid Input\nPlease enter again:";
            has_invalid_input=1;
        }
        if(should_quit)
        {
            std::cout<<"Returning to Main Menu";
            for(int i=0;i<4;i++)
                menu.slow_dots_display();
            break;
        }
        if(!has_invalid_input)
            menu.display();
    }
    
}

#endif