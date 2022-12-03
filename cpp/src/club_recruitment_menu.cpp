#ifndef _CLUB_REC_MENU_

#define _CLUB_REC_MENU_

#ifdef __APPLE__
#include "/Users/gourav/Documents/CPP_project/include/ClubRecruitmentMenu.h"
#include "/Users/gourav/Documents/CPP_project/include/Recruitment.h"
#else

#include "..\include\ClubRecruitmentMenu.h"
#include "..\include\Recruitment.h"
#endif

void club_recruitment_menu()
{
    
    ClubRecruitmentMenu menu;
    std::cout<<"Going to Recruitments";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    try
    {
        std::fstream recruitment_file("recruitment.txt",std::ios::in);
        if(!recruitment_file.is_open())
        {
            throw -1;
        }

        std::vector<Recruitment> recruitment_holder;
        
        for(;recruitment_file;)
        {
            Recruitment temp_recruitment(recruitment_file);
            recruitment_holder.push_back(temp_recruitment);
        }
        menu.clear();
        menu.display(recruitment_holder);
        std::cout<<"Input any character to go back to Club Menu"<<std::endl;
        char ch;
        std::cin>>ch;//for holding screen
        recruitment_file.close();

        if(recruitment_file.is_open())
            throw '1';

        std::cout<<"Returning to Club Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
        menu.clear();
    }
    catch(const int x )
    {
        menu.clear();
        std::cout<<"File could not be opened\n";
        std::cout<<"Returning to Club Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();

    }
    catch(const char c)
    {
        std::cout<<"File could not be closed\n";
        std::cout<<"Returning to Club Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
    }

    

}

#endif