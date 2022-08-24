#ifndef _CLUB_INFO_HELPER_FUNCTION_

#define _CLUB_INFO_HELPER_FUNCTION_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Club.h"

#else

#include "..\include\Club.h"

#endif

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
void operator<<(std::fstream &club_file,std::vector<Club> club_info)
{
    for (auto t=club_info.begin();t!=club_info.end();t++)
    {
        club_file<<t->get_name()<<std::endl;
        club_file<<t->get_convener()<<std::endl;
        club_file<<t->get_co_convener()<<std::endl;
        club_file<<t->get_social_media_id()<<std::endl;
        if (t==(club_info.end()-1))
        {
            club_file << t->get_description();
            club_file.flush();
        }
        else
            club_file << t->get_description() << std::endl;
    }
}

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
    try
    {
        club_file.close();
        if(club_file.is_open())
        {
            throw -1;
        }
        else
        {
            club_file.clear();
            club_file.open("club.txt", std::ios::out | std::ios::in | std::ios::trunc);

            if (!club_file.is_open())
            {
                throw '1';
            }
            else
            {
                club_file << club_info;
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"Problem Closing File\n";
    }
    catch (const char x)
    {
        std::cout << "Problem Opening File after Closing\n";
        throw '1';
    }

}
void edit_club(std::vector<Club>& club_info ,std::fstream& club_file )
{
    int to_be_edited=0;
    bool has_error = 0;
    std::cout<<"Enter club to be Edited: ";
    for (has_error=1;has_error;)
    {
        std::cin >> to_be_edited;
        if (std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if (to_be_edited<0 || to_be_edited>((int)club_info.size() - 1))
        {
            std::cout << "Invalid club Number\nPlease Enter Again: ";
        }
        else
            has_error = 0;
    }
    std::cin.ignore(500,'\n');
    std::cout<<"Enter name of the club ";
    std::getline(std::cin, club_info.at(to_be_edited).name);
    std::cout<<"Enter name of the convener of the club \n";
    std::getline(std::cin, club_info.at(to_be_edited).convener);
    std::cout<<"Enter names of the co_convener/core team of the club :\n";
    std::getline(std::cin, club_info.at(to_be_edited).co_convener);
    std::cout<<"Enter the social media id of the club :\n";
    std::getline(std::cin, club_info.at(to_be_edited).social_media_id);
    std::cout<<"Enter the description of the new club :\n";
    std::getline(std::cin, club_info.at(to_be_edited).description);
    try
    {
        club_file.close();
        if(club_file.is_open())
        {
            throw -1;
        }
        else
        {
            club_file.clear();
            club_file.open("club.txt", std::ios::out | std::ios::in | std::ios::trunc);

            if (!club_file.is_open())
            {
                throw '1';
            }
            else
            {
                club_file << club_info;
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"Problem Closing File\n";
    }
    catch (const char x)
    {
        std::cout << "Problem Opening File after Closing\n";
        throw '1';
    }
    


}
void delete_club(std::vector<Club>& club_info ,std::fstream& club_file )
{
    int to_be_deleted;
    std::cout<<"Enter Number corresponding to club to be deleted: ";

    for (;;)
    {
        std::cin >> to_be_deleted;
        if (std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(to_be_deleted<0 || to_be_deleted>((int)club_info.size()-1))
        {
            std::cout<<"Invalid club Number\nPlease Enter Again: ";
        }
        else 
            break;
    }
    auto iterator_to_deleted = club_info.begin()+to_be_deleted;
    club_info.erase(iterator_to_deleted);

    try
    {
        club_file.close();
        if(club_file.is_open())
            throw -1;
        else
        {
            club_file.clear();
            club_file.open("club.txt",std::ios::out|std::ios::trunc|std::ios::in);
            if(!club_file.is_open())
            {
                throw '1';
            }
            else
            {
                club_file<<club_info;
            }
        }
    }
    catch(const int x)
    {
        std::cout<<"Problem Closing File\n";
    }
    catch(const char x)
    {
        std::cout<<"Problem opening file after closing\n";
        throw '1';
    }

}


#endif