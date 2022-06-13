#ifndef _CLUB_MEET_MENU_

#define _CLUB_MEET_MENU_
#include "..\include\ClubMeetingMenu.h"
#include "..\include\Meeting.h"
void club_meeting_menu()
{
    
    ClubMeetingMenu menu;
    std::cout<<"Going to Meeting";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    try
    {
        std::vector<Meeting> meeting_holder;

        std::fstream meeting_file("meeting.txt",std::ios::in);
        if(!meeting_file.is_open())
        {
            throw -1;
        }
        for(;meeting_file;)
        {
            Meeting temp_meeting(meeting_file);
            meeting_holder.push_back(temp_meeting);
        }
        menu.clear();
        menu.display(meeting_holder);
        std::cout<<"Input any character to go back to Main Menu"<<std::endl;
        char ch;
        std::cin>>ch;//for holding screen
        meeting_file.close();

        if(meeting_file.is_open())
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
