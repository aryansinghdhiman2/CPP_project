#ifndef _EVENT_HELPER_FUNCTION_

#define _EVENT_HELPER_FUNCTION_

#include "..\include\Event.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

void operator<<(std::fstream &input,std::vector<Event> event_holder)
{
    for (unsigned int i = 0; i < event_holder.size(); i++)
    {
        input << event_holder.at(i).get_heading() << std::endl;
        input << event_holder.at(i).get_date() << std::endl;
        if ((event_holder.size() - i) == 1)
        {
            input << event_holder.at(i).get_description();
            input.flush();
        }
        else
            input << event_holder.at(i).get_description() << std::endl;
    }
}

void add_event(std::vector<Event> event_holder,std::fstream &input)
{
    std::string heading,date,description;
    int day,month,year;
    bool has_error=0;
    std::vector<std::string> message{"Enter Day of Event: ","Enter Month of Event: ","Enter Year of Event"};
    
    std::cout<<"Enter Heading for new Event: ";
    std::getline(std::cin,heading);

    std::cout<<"**Enter Numeric Values only for Date of Event**\n";
    std::cout<<"Enter Year of Event: ";
    for(has_error=1;has_error;)
    {
        std::cin>>year;
        if(!bool(std::cin))
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
        }
        else 
            has_error=0;
    }
    std::cout<<"Enter Month of Event: ";
    for(has_error=1;has_error;)
    {
        std::cin>>month;
        if(!bool(std::cin))
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
        }
        else if(!(month>=1 && month<=12))
        {
            std::cout<<"Month should be between 1 and 12\nPlease Enter Again: ";
        }
        else
            has_error=0;
    }

    std::cout<<"Enter Day of Event: ";
    for(has_error=1;has_error;)
    {
        std::cin>>day;
        if(!bool(std::cin))
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
        }
        else if(!(day>=1 && day<=31))
        {
            std::cout<<"Incorrect Day Entered\nPlease Enter Again: ";
        }
        else if(month==2)
        {
            if(!year%4)
            {
                if(day>29){
                    std::cout<<"Incorrect Day Entered\nPlease Enter Again: ";
                }
            }
            else if(day>28){
                    std::cout<<"Incorrect Day Entered\nPlease Enter Again: ";
            }
            else 
                has_error=0;
        }
        else if(month==4 || month==6 || month==9 || month==11)
        {
            if(day>30)
            {
                std::cout<<"Incorrect Day entered\nPlease Enter Again: ";
            }
            else has_error=0;
        }
        else has_error=0;

    }

    if(day<10)
    {
        date='0'+std::to_string(day)+'/'+std::to_string(month)+'/'+std::to_string(year);
    }
    else
    {
        date=std::to_string(day)+'/'+std::to_string(month)+'/'+std::to_string(year);
    }


    std::cout<<"Enter Description: "<<std::endl;
    std::cin.ignore(500,'\n');
    std::getline(std::cin,description);
    
    Event new_event(heading,date,description);
    event_holder.push_back(new_event);

    input.close();
    try
    {
        if(input.is_open())
        {
            throw -1;
        }
        else
        {
            input.clear();
            input.open("event.txt", std::ios::out);

            try
            {
                if (!input.is_open())
                    throw -1;
                else{
                    input<<event_holder;
                }
            }
            catch (const int x)
            {
                std::cout << "Problem Opening File after it was closed\n";
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"Problem in fstream after closing"<< '\n';
    }
    
   
}

#endif