#ifndef _MEETING_H_

#define _MEETING_H_

#include <string>
#include <fstream>
#include <vector>
#include "Club.h"

class Meeting
{
    //Members
    std::string club_name;
    std::string meeting_venue;
    std::string meeting_date;//in DD/MM/YYYY
    std::string meeting_time;//in HH:MM (24 hours format)
    std::string meeting_about;

    public:
    //Constructor
    Meeting(std::fstream &input);
    Meeting(std::string name,std::string venue,std::string date,std::string time,std::string about);
    //Methods
    void display_name() const;
    void display_venue() const;
    void display_date() const;
    void display_time() const;
    void display_about() const;
    std::string get_name() const;
    std::string get_venue() const;
    std::string get_date() const;
    std::string get_time() const;
    std::string get_about() const;
    //Friend
    friend void edit_meeting(std::vector<Meeting> &meeting_holder,std::fstream &input,const std::vector<Club> &club_holder);

};



#endif