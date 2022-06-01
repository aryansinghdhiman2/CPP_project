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
    std::string get_name()
    {
        return name;
    }
    void display_name();
    
    
};

