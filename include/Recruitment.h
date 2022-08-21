#ifndef _RECRUITMENT_H_

#define _RECRUITMENT_H_

#include <string>
#include <fstream>
#include <vector>

class Recruitment
{
    std::string club_name;
    std::string recruitment_venue;
    std::string recruitment_date;//in DD/MM/YYYY
    std::string recruitment_time;//in HH:MM (24 hours format)

    public:
    //Constructor
    Recruitment(std::fstream &input);
    Recruitment(std::string name,std::string venue,std::string date,std::string time);
    //Methods
    void display_name() const;
    void display_venue() const;
    void display_date() const;
    void display_time() const;
    std::string get_name() const;
    std::string get_venue() const;
    std::string get_date() const;
    std::string get_time() const;
};




#endif