#include "..\include\Meeting.h"
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