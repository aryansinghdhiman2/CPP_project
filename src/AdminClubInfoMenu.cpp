#include"..\include\AdminClubInfoMenu.h"
#include"..\include\Club.h"
#include<iomanip>
void AdminClubInfoMenu::display(std::vector<Club>& club_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    for(unsigned int i=0;i<club_holder.size();i++)
    {
        std::cout<<'['<<i<<']'<<' ';
        club_holder.at(i).display_name();
    }
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}

void AdminClubInfoMenu::display()
{
    std::cout<<"[1] New Event"<<std::setw(18)<<"[2] Edit Event"<<std::setw(28)<<'\n';
    std::cout<<"[3] Delete Event"<<std::setw(25)<<"[Q] Return to Admin Menu"<<'\n';
    std::cout<<"Enter Input corresponding to Action to be performed: ";
}