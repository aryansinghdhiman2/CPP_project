#ifndef _CLUBS_INFO_MENU_

#define _CLUBS_INFO_MENU_
#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Club.h"
#include "/Users/gourav/Documents/CPP_project/include/ClubInfoMenu.h"

#else
#include "..\include\Club.h"
#include "..\include\ClubInfoMenu.h"

#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
void clubs_info_menu()
{
ClubInfoMenu menu;
    std::cout<<"Going to Club Information Menu";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }
    try
    {
        std::vector<Club> club_holder;

        std::fstream club_file("club.txt",std::ios::in);
        if(!club_file.is_open())
        {
            throw -1;
        }
        for(;club_file;)
        {
            Club temp_club(club_file);
            club_holder.push_back(temp_club);
        }
        menu.clear();
        menu.display(club_holder);
        std::cout<<"Input any character to go back to Club Menu"<<std::endl;
        char ch;
        std::cin>>ch;
        club_file.close();

        if(club_file.is_open())
            throw '1';

        std::cout<<"Returning to Main Menu";
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
        std::cout<<"Returning to Main Menu";
        for(int i=0;i<4;i++)
            menu.slow_dots_display();
    }
    


}

#endif