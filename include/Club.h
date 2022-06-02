#ifndef _CLUB_H_

#define _CLUB_H_

#include<iostream>
#include<string>
#include<fstream>
class Club
{
    std::string name;
    std::string convener;
    std::string co_convener;
    std::string social_media_id;
    std::string description;
    public:
    Club(std::fstream &);
    std::string get_name() const
    {
        return name;
    }
    void display_name() const;
    void display_convener() const;
    void display_co_convener() const;
    void display_social_media_id() const;
    void display_description() const;
    
};

#endif