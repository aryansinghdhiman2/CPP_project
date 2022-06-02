#ifndef _EVENT_HELPER_FUNCTION_

#define _EVENT_HELPER_FUNCTION_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Event.h"

#else

#include "..\include\Event.h"

#endif

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

void add_event(std::vector<Event>& event_holder,std::fstream &input)
{
    std::string heading,date,description;
    int day,month,year;
    bool has_error=0;
    
    std::cout<<"Enter Heading for new Event: ";
    std::getline(std::cin,heading);
    std::cout<<"**Enter Numeric Values only for Date of Event**\n";
    std::cout<<"Enter Year of Event: ";
    for(has_error=1;has_error;)
    {
        std::cin>>year;
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else 
            has_error=0;
    }
    std::cout<<"Enter Month of Event: ";
    for(has_error=1;has_error;)
    {
        std::cin>>month;
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
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
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
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

    if(day<10 && month<10)
    {
        date='0'+std::to_string(day)+'/'+'0'+std::to_string(month)+'/'+std::to_string(year);
    }
    else if(day>9 && month <10)
    {
        date=std::to_string(day)+'/'+'0'+std::to_string(month)+'/'+std::to_string(year);
    }
    else if(day<10 && month>9)
    {
        date='0'+std::to_string(day)+'/'+std::to_string(month)+'/'+std::to_string(year);
    }
    else
    {
        date=std::to_string(day)+'/'+std::to_string(month)+'/'+std::to_string(year);
    }


    std::cout<<"Enter Description: ";
    std::cin.ignore(500,'\n');
    std::getline(std::cin,description);
    
    Event new_event(heading,date,description);
    event_holder.push_back(new_event);

    try
    {
        input.close();
        if(input.is_open())
        {
            throw -1;
        }
        else
        {
            input.clear();
            input.open("event.txt", std::ios::out | std::ios::in | std::ios::trunc);

            if (!input.is_open())
            {
                throw '1';
            }
            else
            {
                input << event_holder;
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"Problem Closing File\n";
    }
    catch (const char x)
    {
        std::cout << "Problem Opening File after Closing\n";
        throw '1';
    }
}

void delete_event(std::vector<Event>& event_holder,std::fstream &input)
{
    int to_be_deleted;
    std::cout<<"Enter Number corresponding to Event to be deleted: ";

    for (;;)
    {
        std::cin >> to_be_deleted;
        if (std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(to_be_deleted<0 || to_be_deleted>((int)event_holder.size()-1))
        {
            std::cout<<"Invalid Event Number\nPlease Enter Again: ";
        }
        else 
            break;
    }
    
    std::vector<Event> temp_holder;
    for(int i=0;i<(int)event_holder.size();i++)
    {
        if(i!=to_be_deleted)
            temp_holder.push_back(event_holder.at(i));
    }

    event_holder.clear();
    event_holder=temp_holder;

    try
    {
        input.close();
        if(input.is_open())
            throw -1;
        else
        {
            input.open("event.txt",std::ios::out|std::ios::trunc|std::ios::in);
            if(!input.is_open())
            {
                throw '1';
            }
            else
            {
                input<<event_holder;
            }
        }
    }
    catch(const int x)
    {
        std::cout<<"Problem Closing File\n";
    }
    catch(const char x)
    {
        std::cout<<"Problem opening file after closing\n";
        throw '1';
    }

}

void edit_event(std::vector<Event>& event_holder,std::fstream &input)
{
    int to_be_edited=0;
    std::cout<<"Enter Event to be Edited: ";
    for (;;)
    {
        std::cin >> to_be_edited;
        if (std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(to_be_edited<0 || to_be_edited>((int)event_holder.size()-1))
        {
            std::cout<<"Invalid Event Number\nPlease Enter Again: ";
        }
        else 
            break;
    }
    std::cin.ignore(500,'\n');
    int day,month,year;
    bool has_error=0;

    std::cout<<"Enter Heading for Event: ";
    std::getline(std::cin,event_holder.at(to_be_edited).heading);

    std::cout<<"**Enter Numeric Values only for Date of Event**\n";
    std::cout<<"Enter Year of Event: ";
    for(has_error=1;has_error;)
    {
         std::cin>>year;
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else 
            has_error=0;
    }
    std::cout<<"Enter Month of Event: ";
    for(has_error=1;has_error;)
    {
        std::cin>>month;
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
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
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
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

    std::string date;
    if(day<10 && month<10)
    {
        date='0'+std::to_string(day)+'/'+'0'+std::to_string(month)+'/'+std::to_string(year);
    }
    else if(day>9 && month <10)
    {
        date=std::to_string(day)+'/'+'0'+std::to_string(month)+'/'+std::to_string(year);
    }
    else if(day<10 && month>9)
    {
        date='0'+std::to_string(day)+'/'+std::to_string(month)+'/'+std::to_string(year);
    }
    else
    {
        date=std::to_string(day)+'/'+std::to_string(month)+'/'+std::to_string(year);
    }

    event_holder.at(to_be_edited).date=date;


    std::cout<<"Enter Description: ";
    std::cin.ignore(500,'\n');
    std::getline(std::cin,event_holder.at(to_be_edited).description);

    try
    {
        input.close();
        if(input.is_open())
        {
            throw -1;
        }
        else
        {
            input.clear();
            input.open("event.txt", std::ios::out | std::ios::in | std::ios::trunc);

            if (!input.is_open())
            {
                throw '1';
            }
            else
            {
                input << event_holder;
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"Problem Closing File\n";
    }
    catch (const char x)
    {
        std::cout << "Problem Opening File after Closing\n";
        throw '1';
    }
    

}
#endif