#ifndef _CLUB_RECRUITMENT_MENU_H_

#define _CLUB_RECRUITMENT_MENU_H_
#include <vector>


#include "Interface.h"
#include "Recruitment.h"

class ClubRecruitmentMenu : public Interface
{
    public:
    void display(){};
    virtual void display(const std::vector<Recruitment> &recruitment_holder);
    virtual ~ClubRecruitmentMenu(){};
};

#endif