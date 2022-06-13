
#include "..\include\ClubMeetingMenu.h"

#endif

#include <iostream>
#include <iomanip>

void ClubMeetingMenu::display(const std::vector<Meeting> &meeting_holder)
{
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";
    std::cout<<"Upcoming Meetings: \n";
    int i=0;
    for(auto t = meeting_holder.begin();t!= meeting_holder.end();t++,i++)
    {
        std::cout<<"Club :";
        t->display_name();
        std::cout<<"Meeting Date :";
        t->display_date();
        std::cout<<"Meeting Venue :";
        t->display_venue();
        std::cout<<"Meeting Time :";
        t->display_time();
        std::cout<<"Meeting Description :";
        t->display_about();
        std::cout<<std::endl;
    }
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";

}