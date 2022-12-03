#ifndef _ADMIN_CLUB_RECRUITMENT_MENU_H_

#define _ADMIN_CLUB_RECRUITMENT_MENU_H_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"
#include "/Users/gourav/Documents/CPP_project/include/Recruitment.h"

#else

#include "Interface.h"
#include "Recruitment.h"

#endif

#include <vector>

class AdminClubRecruitmentMenu : public Interface
{
    public:
    void display();
    void display(const std::vector<Recruitment>&);

};


#endif