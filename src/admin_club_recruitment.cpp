#ifndef _ADMIN_CLUB_RECRUITMENT_

#define _ADMIN_CLUB_RECRUITMENT_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/AdminClubRecruitmentMenu.h"
#include "/Users/gourav/Documents/CPP_project/include/Recruitment.h"
#include "/Users/gourav/Documents/CPP_project/include/Club.h"
#include "/Users/gourav/Documents/CPP_project/src/admin_club_recruitment_helper_functions.cpp"

#else

#include "..\include\AdminClubRecruitmentMenu.h"
#include "..\include\Recruitment.h"
#include "..\include\Club.h"
#include "admin_club_recruitment_helper_functions.cpp"

#endif

#include <fstream>
#include <vector>

void admin_club_recruitment()
{
    AdminClubRecruitmentMenu menu;
    std::cout<<"Going to Club Recruitment";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }

    menu.clear();

    std::fstream recruitment_file("recruitment.txt",std::ios::in|std::ios::app|std::ios::out);
    std::fstream club_file("club.txt",std::ios::in);
    try
    {
        if(!recruitment_file.is_open())
        {
            throw -1;
        }
        if(!club_file.is_open())
        {
            throw -1;
        }
        else
        {
            std::vector<Recruitment> recruitment_holder;
            std::vector<Club> club_holder;
            for(;recruitment_file;)
            {
                Recruitment temp_recruitment(recruitment_file);
                recruitment_holder.push_back(temp_recruitment);
            }

            for(;club_file;)
            {
                Club temp_club(club_file);
                club_holder.push_back(temp_club);
            }

            menu.display(recruitment_holder);
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
                    add_recruitment(recruitment_holder,recruitment_file,club_holder);
                    break;
                case '2':
                    edit_recruitment(recruitment_holder,recruitment_file,club_holder);
                    break;
                case '3':
                    delete_recruitment(recruitment_holder,recruitment_file);
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

                recruitment_file.seekp(0);
                recruitment_file.seekg(0);

                if (!has_invalid_input)
                {
                    menu.clear();
                    menu.display(recruitment_holder);
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