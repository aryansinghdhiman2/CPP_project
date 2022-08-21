#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Recruitment.h"

#else

#include "..\include\Recruitment.h"

#endif
#include<iostream>

Recruitment::Recruitment(std::fstream &input)
{
    std::getline(input,this->club_name);
    std::getline(input,this->recruitment_venue);
    std::getline(input,this->recruitment_date);
    std::getline(input,this->recruitment_time);

    int t=input.tellg();//see comment in Event.cpp
    if(t==-2)
            std::cout<<"This should not be possible\n";
}
Recruitment::Recruitment(std::string name,std::string venue,std::string date,std::string time)
{
    this->club_name=name;
    this->recruitment_venue=venue;
    this->recruitment_date=date;
    this->recruitment_time=time;
}

void Recruitment::display_name() const
{
    std::cout<<this->club_name<<'\n';
}

void Recruitment::display_venue() const
{
    std::cout<<this->recruitment_venue<<'\n';
}

void Recruitment::display_date() const
{
    std::cout<<this->recruitment_date<<'\n';
}

void Recruitment::display_time() const
{
    std::cout<<this->recruitment_time<<'\n';
}

std::string Recruitment::get_name() const
{
    return this->club_name;
}

std::string Recruitment::get_venue() const
{
    return this->recruitment_venue;
}

std::string Recruitment::get_date() const
{
    return this->recruitment_date;
}

std::string Recruitment::get_time() const
{
    return this->recruitment_time;
}