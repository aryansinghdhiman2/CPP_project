#ifndef _ADMIN_CLUB_MEETING_

#define _ADMIN_CLUB_MEETING_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/AdminClubInfoMenu.h"
#include "/Users/gourav/Documents/CPP_project/include/Meeting.h"
#include "/Users/gourav/Documents/CPP_project/include/Club.h"
#include "/Users/gourav/Documents/CPP_project/src/admin_club_meeting_helper_functions.cpp"

#else

#include "..\include\AdminClubMeetingMenu.h"
#include "..\include\Meeting.h"
#include "..\include\Club.h"
#include "admin_club_meeting_helper_functions.cpp"

#endif

#include <fstream>
#include <vector>

void admin_club_meeting()
{
    AdminClubMeetingMenu menu;
    std::cout<<"Going to Club Meeting";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }

    menu.clear();

    std::fstream meeting_file("meeting.txt",std::ios::in|std::ios::app|std::ios::out);
    std::fstream club_file("club.txt",std::ios::in);
    try
    {
        if(!meeting_file.is_open())
        {
            throw -1;
        }
        if(!club_file.is_open())
        {
            throw -1;
        }
        else
        {
            std::vector<Meeting> meeting_holder;
            std::vector<Club> club_holder;
            for(;meeting_file;)
            {
                Meeting temp_meeting(meeting_file);
                meeting_holder.push_back(temp_meeting);
            }

            for(;club_file;)
            {
                Club temp_club(club_file);
                club_holder.push_back(temp_club);
            }

            menu.display(meeting_holder);
            menu.display();

            char input;
            bool should_quit = 0;
            bool has_invalid_input = 0;
            for (;;)
            {
                std::cin >> input;
                std::cin.ignore(500, '\n');

                switch (input)
                {
                case '1':
                    add_meeting(meeting_holder,meeting_file,club_holder);
                    break;
                case '2':
                    edit_meeting(meeting_holder,meeting_file,club_holder);
                    break;
                case '3':
                    delete_meeting(meeting_holder,meeting_file);
                    break;
                case 'q':
                case 'Q':
                    should_quit = 1;
                    break;
                default:
                    std::cout << "Invalid Input\nPlease Enter Character Again: ";
                    has_invalid_input = 1;
                }
                if (should_quit)
                {
                    std::cout << "Returning to Admin Menu";
                    for (int i = 0; i < 4; i++)
                        menu.slow_dots_display();
                    break;
                }

                meeting_file.seekp(0);
                meeting_file.seekg(0);

                if (!has_invalid_input)
                {
                    menu.clear();
                    menu.display(meeting_holder);
                    menu.display();
                }
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
    
}



#endif