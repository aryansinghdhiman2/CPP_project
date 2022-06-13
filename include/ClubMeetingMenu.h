#ifndef _CLUB_MEETING_MENU_H_

#define _CLUB_MEETING_MENU_H_
#include <vector>


#include "Interface.h"
#include "Meeting.h"

class ClubMeetingMenu : public Interface
{
    public:
    void display(){};
    virtual void display(const std::vector<Meeting> &meeting_holder);
    virtual ~ClubMeetingMenu(){};
};

#endif