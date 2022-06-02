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

Meeting::Meeting(std::string name,std::string venue,std::string date,std::string time,std::string about)
{
    this->club_name=name;
    this->meeting_venue=venue;
    this->meeting_date=date;
    this->meeting_time=time;
    this->meeting_about=about;
}

void Meeting::display_name() const
{
    std::cout<<this->club_name<<'\n';
}

void Meeting::display_venue() const
{
    std::cout<<this->meeting_venue<<'\n';
}

void Meeting::display_date() const
{
    std::cout<<this->meeting_date<<'\n';
}

void Meeting::display_time() const
{
    std::cout<<this->meeting_time<<'\n';
}

void Meeting::display_about() const
{
    std::cout<<this->meeting_about<<'\n';
}

std::string Meeting::get_name() const
{
    return this->club_name;
}

std::string Meeting::get_venue() const
{
    return this->meeting_venue;
}

std::string Meeting::get_date() const
{
    return this->meeting_date;
}

std::string Meeting::get_time() const
{
    return this->meeting_time;
}

std::string Meeting::get_about() const
{
    return this->meeting_about;
}