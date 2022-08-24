#ifndef _MEETING_HELPER_FUNCTIONS_

#define _MEETING_HELPER_FUNCTIONS_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Meeting.h"
#include "/Users/gourav/Documents/CPP_project/include/Club.h"

#else

#include "..\include\Meeting.h"
#include "..\include\Club.h"

#endif

#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

void operator<<(std::fstream &input,std::vector<Meeting> meeting_holder)
{
    for (auto t = meeting_holder.begin(); t !=meeting_holder.end(); t++)
    {
        input << t->get_name() << std::endl;
        input << t->get_venue() << std::endl;
        input << t->get_date() << std::endl;
        input << t->get_time() << std::endl;
        if (t==(meeting_holder.end()-1))
        {
            input << t->get_about();
            input.flush();
        }
        else
            input << t->get_about() << std::endl;
    }
}

void display_club_names(const std::vector<Club> &club_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    int i=0;
    for(auto t = club_holder.begin(); t !=club_holder.end(); t++,i++)
    {
        std::cout<<"["<<i<<"]";
        t->display_name();
    }
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}

void admin_meeting_clear()
{
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        system("cls");

    #else
        system("clear"); // for UNIX systems
    #endif
}

void add_meeting(std::vector<Meeting> &meeting_holder,std::fstream &input,const std::vector<Club> &club_holder)
{
    std::string name,venue,about,date,time;
    int day,month,year,hour,minute;

    admin_meeting_clear();
    display_club_names(club_holder);
    std::cout<<"Enter Club for which Meeting has to be scheduled: ";
    int club_selected;
    bool has_error=0;
    for(has_error=1;has_error;)
    {
        std::cin>>club_selected;
        if(std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(club_selected<0 || club_selected>=int(club_holder.size()))
        {
            std::cout<<"Invalid Club selected\nPlease Enter Again: ";
        }
        else
            has_error=0;
        
    }

    name=club_holder.at(club_selected).get_name();
    std::cout<<"Enter Venue for Meeting : ";
    for(has_error=1;has_error;)
    {
        std::cin.ignore(500,'\n');
        std::getline(std::cin,venue);
        if(std::cin.fail())
        {
            std::cout<<"Some error occurred\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else
            has_error=0;

    }

    std::cout<<"**Enter Numeric Values only for Date of Meeting**\n";
    std::cout<<"Enter Year of Meeting: ";
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
    std::cout<<"Enter Month of Meeting: ";
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

    std::cout<<"Enter Day of Meeting: ";
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
            if(!(year%4))
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

    std::cout<<"**Enter Numeric Values in 24 Hour Format Only**\n";
    std::cout<<"Enter Hours: ";
    for(has_error=1;has_error;)
    {
        std::cin>>hour;
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else if(hour<0 || hour>24)
        {
            std::cout<<"Hours should be between 00 and 24\nPlease Enter Again: ";
        }
        else
            has_error=0;
    }
    std::cout<<"Enter Minutes: ";
    for(has_error=1;has_error;)
    {
        std::cin>>minute;
        if(std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(minute<0 || minute>59)
        {
            std::cout<<"Minutes should be between 00 and 59\nPlease Enter Again: ";
        }
        else 
            has_error=0;
    }

    if(hour<10 && minute<10)
    {
        time='0'+std::to_string(hour)+':'+'0'+std::to_string(minute);
    }
    if(hour>9 && minute<10)
    {
        time=std::to_string(hour)+':'+'0'+std::to_string(minute);
    }
    if(hour>9 && minute>9)
    {
        time=std::to_string(hour)+':'+std::to_string(minute);
    }
    if(hour<10 && minute>9)
    {
        time='0'+std::to_string(hour)+':'+std::to_string(minute);
    }

    std::cout<<"Enter Description of the Meeting: ";
    std::cin.ignore(500,'\n');
    std::getline(std::cin,about);
    if(std::cin.fail())
    {
        std::cout << "Invalid Input\nPlease Enter Again: ";
        std::cin.clear();
        std::cin.ignore(500, '\n');
    }

    Meeting temp_meeting(name,venue,date,time,about);
    meeting_holder.push_back(temp_meeting);

    try
    {
        input.close();
        if(input.is_open())
        {
            throw -1;
        }
        else
        {
            input.open("meeting.txt",std::ios::trunc|std::ios::out|std::ios::in);
            if(!input.is_open())
            {
                throw '1';
            }
            else
            {
                input << meeting_holder;
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"An Error Occurred Opening File"<< '\n';
    }
    catch(const char c)
    {
        std::cout<<"An Error Occurred Opening File after closing\n";
    }
    

}

void edit_meeting(std::vector<Meeting> &meeting_holder,std::fstream &input,const std::vector<Club> &club_holder)
{
    std::string venue,about,date,time;
    int day,month,year,hour,minute,to_be_edited;

    bool has_error=0;

    std::cout<<"Enter number corresponding to Meeting to be edited: ";
    for(has_error=1;has_error;)
    {
        std::cin>>to_be_edited;
        if(std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else
        {
            has_error=0;
        }
    }

    std::cout<<"Enter Venue for Meeting : ";
    std::cin.ignore(500, '\n');
    for(has_error=1;has_error;)
    {
        std::getline(std::cin,venue);
        if(std::cin.fail())
        {
            std::cout<<"Some error occurred\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else
            has_error=0;

    }

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
    std::cout<<"Enter Month of Meeting: ";
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

    std::cout<<"Enter Day of Meeting: ";
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
            if(!(year%4))
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

    std::cout<<"**Enter Numeric Values in 24 Hour Format Only**\n";
    std::cout<<"Enter Hours: ";
    for(has_error=1;has_error;)
    {
        std::cin>>hour;
        if(std::cin.fail())
        {
            std::cout<<"Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else if(hour<0 || hour>24)
        {
            std::cout<<"Hours should be between 00 and 24\nPlease Enter Again: ";
        }
        else
            has_error=0;
    }
    for(has_error=1;has_error;)
    std::cout<<"Enter Minutes: ";
    {
        std::cin>>minute;
        if(std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(minute<0 || minute>59)
        {
            std::cout<<"Minutes should be between 00 and 59\nPlease Enter Again: ";
        }
        else 
            has_error=0;
    }

    if(hour<10 && minute<10)
    {
        time='0'+std::to_string(hour)+':'+'0'+std::to_string(minute);
    }
    if(hour>9 && minute<10)
    {
        time=std::to_string(hour)+':'+'0'+std::to_string(minute);
    }
    if(hour>9 && minute>9)
    {
        time=std::to_string(hour)+':'+std::to_string(minute);
    }
    if(hour<10 && minute>9)
    {
        time='0'+std::to_string(hour)+':'+std::to_string(minute);
    }

    std::cout<<"Enter Description of the Meeting: ";
    std::cin.ignore(500, '\n');
    for(has_error=1;has_error;)
    {
        std::getline(std::cin,about);
        if(std::cin.fail())
        {
            std::cout<<"Some error occurred\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500,'\n');
        }
        else
            has_error=0;
    }


    try
    {
        input.close();
        if(input.is_open())
        {
            throw -1;
        }
        else
        {
            input.open("meeting.txt",std::ios::trunc|std::ios::out|std::ios::in);
            if(!input.is_open())
            {
                throw '1';
            }
            else
            {
                input << meeting_holder;
            }
        }
    }
    catch(const int x)
    {
        std::cout <<"An Error Occurred Opening File"<< '\n';
    }
    catch(const char c)
    {
        std::cout<<"An Error Occurred Opening File after closing\n";
    }
    

}

void delete_meeting(std::vector<Meeting>& meeting_holder,std::fstream &input)
{
    int to_be_deleted;
    std::cout<<"Enter Number corresponding to Meeting to be deleted: ";

    for (;;)
    {
        std::cin >> to_be_deleted;
        if (std::cin.fail())
        {
            std::cout << "Invalid Input\nPlease Enter Again: ";
            std::cin.clear();
            std::cin.ignore(500, '\n');
        }
        else if(to_be_deleted<0 || to_be_deleted>((int)meeting_holder.size()-1))
        {
            std::cout<<"Invalid Event Number\nPlease Enter Again: ";
        }
        else 
            break;
    }
    
    auto iterator_to_deleted=meeting_holder.begin()+to_be_deleted;
    meeting_holder.erase(iterator_to_deleted);

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
                input<<meeting_holder;
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
#endif