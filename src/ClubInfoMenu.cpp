#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/ClubInfoMenu.h"


#else

#include "..\include\ClubInfoMenu.h"

#endif

#include <iostream>
#include <iomanip>

void ClubInfoMenu::display(const std::vector<Club> &club_holder)
{
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";
    std::cout<<"Clubs: \n";
    int i=0;
    for(auto t = club_holder.begin();t!=club_holder.end();t++,i++)
    {
        std::cout<<"Club Name :";
        t->display_name();
        std::cout<<"Convenor :";
        t->display_convener();
        std::cout<<"Co-convenor:";
        t->display_co_convener();
        std::cout<<"Social Media Handle";
        t->display_social_media_id();
        std::cout<<"Club Description";
        t->display_description();
        std::cout<<std::endl;
    }
    std::cout<<std::setw(70)<<std::setfill('*')<<"\n";

}