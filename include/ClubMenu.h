#ifndef _CLUB_MENU_H_

#define _CLUB_MENU_H_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"

#else

#include "Interface.h"

#endif

class ClubMenu : public Interface
{
    public:
    void display();
    virtual ~ClubMenu(){};
};

#endif