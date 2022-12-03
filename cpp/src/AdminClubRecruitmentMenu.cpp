#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/AdminClubRecruitmentMenu.h"

#else

#include "..\include\AdminClubRecruitmentMenu.h"

#endif

#include <iomanip>
#include <iostream>

void AdminClubRecruitmentMenu::display()
{
    std::cout << "[1] New Recruitment" << std::setw(29) << "[2] Edit Recruitment Info" << std::setw(28) << '\n';
    std::cout << "[3] Delete Recruitment" << std::setw(25) << "[Q] Return to Admin Menu" << '\n';
    std::cout << "Enter Input corresponding to Action to be performed: ";
}

void AdminClubRecruitmentMenu::display(const std::vector<Recruitment>& recruitment_holder)
{
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
    std::cout<<"Active Recruitments:\n";
    int i=0;
    for(auto t=recruitment_holder.begin();t!=recruitment_holder.end();t++,i++)
    {
        std::cout<<'['<<i<<']'<<' ';
        t->display_name();
    }
    std::cout<<std::setw(40)<<std::setfill('*')<<"\n"<<std::setfill(' ');
}