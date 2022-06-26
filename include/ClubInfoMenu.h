#ifndef _CLUB_INFO_MENU_H_
#define _CLUB_INFO_MENU_H_

#ifdef __APPLE__
#include "/Users/gourav/Documents/CPP_project/include/Interface.h"
#include "/Users/gourav/Documents/CPP_project/include/Club.h"
#elif
#include "Interface.h"
#include "Club.h"
#endif
#include<vector>
class ClubInfoMenu : public Interface
{
  public:
    void display(){};
    virtual void display(const std::vector<Club> &event_holder);
    virtual ~ClubInfoMenu(){};
   
};
#endif