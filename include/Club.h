#ifndef _CLUB_H_

#define _CLUB_H_

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
class Club
{
    std::string name;
    std::string convener;
    std::string co_convener;
    std::string social_media_id;
    std::string description;
    public:
    Club(std::fstream &);
    void display_name() const;
    void display_convener() const;
    void display_co_convener() const;
    void display_social_media_id() const;
    void display_description() const;
    Club(std::string name,std::string convener,std::string co_convener,std::string social_media_id,std::string description);
    friend void edit_club(std::vector<Club>& club_info ,std::fstream& club_file );
    std::string get_name();
    std::string get_convener();
    std::string get_co_convener();
    std::string get_social_media_id();
    std::string get_description();
};

#endif