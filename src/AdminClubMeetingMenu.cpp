#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/AdminClubMeetingMenu.h"

#else

#include "..\include\AdminClubMeetingMenu.h"

#endif

#include <iomanip>
#include <iostream>

void AdminClubMeetingMenu::display()
{
    std::cout << "[1] New Meeting" << std::setw(18) << "[2] Edit Meeting" << std::setw(28) << '\n';
    std::cout << "[3] Delete Meeting" << std::setw(25) << "[Q] Return to Admin Menu" << '\n';
    std::cout << "Enter Input corresponding to Action to be performed: ";
}

void AdminClubMeetingMenu::display(const std::vector<Meeting>& meeting_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    std::cout<<"Clubs that have Meeting:\n";
    for(unsigned int i=0;i<meeting_holder.size();i++)
    {
        std::cout<<'['<<i<<']'<<' ';
        meeting_holder.at(i).display_name();
    }
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}