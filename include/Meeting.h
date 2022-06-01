#ifndef _MEETING_H_

#define _MEETING_H_

#include <string>
#include <fstream>

class Meeting
{
    //Members
    std::string club_name;
    std::string meeting_venue;
    std::string meeting_date;//in DD/MM/YYYY
    std::string meeting_time;//in HH:MM AM/PM
    std::string meeting_about;

    public:
    //Constructor
    Meeting(std::fstream &input);

    void display_name();
};




#endif