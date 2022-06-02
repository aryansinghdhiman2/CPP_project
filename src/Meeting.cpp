#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Meeting.h"

#else

#include "..\include\Meeting.h"

#endif
#include<iostream>

Meeting::Meeting(std::fstream &input)
{
    std::getline(input,this->club_name);
    std::getline(input,this->meeting_venue);
    std::getline(input,this->meeting_date);
    std::getline(input,this->meeting_time);
    std::getline(input,this->meeting_about);

    int t=input.tellg();//see comment in Event.cpp
    if(t==-2)
            std::cout<<"This should not be possible\n";
}

void Meeting::display_name() const
{
    std::cout<<this->club_name<<'\n';
}