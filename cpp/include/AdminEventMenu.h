#ifndef _ADMIN_EVENT_MENU_H_

#define _ADMIN_EVENT_MENU_H_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"
#include "/Users/gourav/Documents/CPP_project/include/Event.h"

#else

#include "Interface.h"
#include "Event.h"

#endif

#include <vector>
class AdminEventMenu : public Interface
{
    public:
    void display();
    virtual void display(std::vector<Event> event_holder);
    virtual ~AdminEventMenu(){};
};

#endif