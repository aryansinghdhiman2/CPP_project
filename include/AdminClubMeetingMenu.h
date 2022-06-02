#ifndef _ADMIN_CLUB_MEETING_MENU_H_

#define _ADMIN_CLUB_MEETING_MENU_H_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"
#include "/Users/gourav/Documents/CPP_project/include/Meeting.h"

#else

#include "Interface.h"
#include "Meeting.h"

#endif

#include <vector>

class AdminClubMeetingMenu : public Interface
{
    public:
    void display();
    void display(const std::vector<Meeting>&);

};




#endif