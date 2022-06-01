#ifndef _CLUB_INFO_MENU_
#define _CLUB_INFO_MENU_
#include"..\include\AdminClubInfoMenu.h"
#include"..\include\Club.h"
void admin_club_info_menu()
{
    AdminClubInfoMenu menu;
    std::cout<<"Going to Club Info Menu";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    menu.clear();
    std::fstream club_file("club.txt",std::ios::in|std::ios::app|std::ios::out);
    try
    {
        if(!club_file.is_open())
        {
            throw -1;
        }

        std::vector<Club> club_info;

        for(;club_file;)
        {
            Club temp_club(club_file);
            club_info.push_back(temp_club);
        }

        menu.display(club_info);
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
            //   add_club(club_info,club_file);
                break;
            case '2':
            //     edit_club(club_info,club_file);
                break;
            case '3':
          //      delete_club(club_info,club_file);
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

            club_file.seekp(0);
            club_file.seekg(0);

            club_info.clear();
            for (;club_file;)
            {
                Club temp_club(club_file);
                club_info.push_back(temp_club);
            }

            if (!has_invalid_input)
            {
                menu.clear();
                menu.display(club_info);
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

    club_file.close();
}
 #endif