#ifndef _ADMIN_CLUB_MEETING_MENU_H_

#define _ADMIN_CLUB_MEETING_MENU_H_

#include "Interface.h"
#include "Meeting.h"
#include <vector>

class AdminClubMeetingMenu : public Interface
{
    public:
    void display();
    void display(const std::vector<Meeting>&);

};




#endif