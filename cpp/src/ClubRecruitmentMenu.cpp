#ifdef __APPLE__
#include "/Users/gourav/Documents/CPP_project/include/ClubRecruitmentMenu.h"

#else
#include "..\include\ClubRecruitmentMenu.h"
#endif
#include <iostream>
#include <iomanip>

void ClubRecruitmentMenu::display(const std::vector<Recruitment> &recruitment_holder)
{
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";
    std::cout<<"Active Recruitments: \n";
    int i=0;
    for(auto t = recruitment_holder.begin();t!= recruitment_holder.end();t++,i++)
    {
        std::cout<<"Club :";
        t->display_name();
        std::cout<<"Recruitment Date :";
        t->display_date();
        std::cout<<"Recruitment Venue :";
        t->display_venue();
        std::cout<<"Recruitment Time :";
        t->display_time();
        std::cout<<std::endl;
    }
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";

}