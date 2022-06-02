#ifndef _MEETING_HELPER_FUNCTIONS_

#define _MEETING_HELPER_FUNCTIONS_

#include "..\include\Meeting.h"
#include "..\include\Club.h"
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

void display_club_names(const std::vector<Club> &club_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    for(unsigned int i=0;i<club_holder.size();i++)
    {
        club_holder.at(i).display_name();
    }
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}

void admin_meeting_clear()
{
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        system("cls");

    #else
        system("clear"); // for UNIX systems
    #endif
}

void add_meeting(std::vector<Meeting> &meeting_holder,std::fstream &input,const std::vector<Club> &club_holder)
{
    std::string name,venue,about;
    int day,month,year,hour,minute;

    //std::cout<<"Enter "
}



#endif