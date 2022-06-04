#ifndef _CLUB_INFO_HELPER_FUNCTION_

#define _CLUB_INFO_HELPER_FUNCTION_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Club.h"

#else

#include "..\include\Club.h"
#include "Club.cpp"

#endif

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
void add_club(std::vector<Club>& club_info ,std::fstream& club_file )
{
    std::string name,convener,co_convener,social_media_id,description;
    std::cout<<"Enter the name of the new club :";
    std::getline(std::cin,name);
    std::cout<<"Enter name of the convener of the new club :\n";
    std::getline(std::cin,convener);
    std::cout<<"Enter names of the co_convener/core team of the new club :\n";
    std::getline(std::cin,co_convener);
    std::cout<<"Enter the social media id of the new club :\n";
    std::getline(std::cin,social_media_id);
    std::cout<<"Enter the description of the new club :\n";
    std::getline(std::cin,description);

    Club new_club(name,convener,co_convener,social_media_id,description);
    club_info.push_back(new_club);


}
void edit_club(std::vector<Club>& club_info ,std::fstream& club_file )
{

}
void delete_club(std::vector<Club>& club_info ,std::fstream& club_file )
{

}


#endif