#ifndef _EVENT_

#define _EVENT_
#include <string>
#include <fstream>
#include <vector>

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
        Event(std::string,std::string,std::string);
        //Methods
        void display() const;
        void display_heading() const;
        void display_date() const;
        void display_description() const;
        std::string get_heading();
        std::string get_date();
        std::string get_description();
        //friends
        friend void edit_event(std::vector<Event> event_holder,std::fstream &input);
};

#endif