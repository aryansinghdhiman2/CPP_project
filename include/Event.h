#ifndef _EVENT_

#define _EVENT_
#include <string>
#include <fstream>

class Event
{
    private:
        //Members
        std::string heading;
        std::string date;//in DD/MM/YYYY format
        std::string description;
    public:
        //Constructor
        Event(std::fstream &input);
        //Methods
        void display() const;
        void display_heading() const;
        void display_date() const;
        void display_description() const;

};

#endif