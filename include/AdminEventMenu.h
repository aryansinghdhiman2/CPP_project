#ifndef _ADMIN_EVENT_MENU_H_

#define _ADMIN_EVENT_MENU_H_

#include "Event.h"
#include "Interface.h"
#include <vector>
class AdminEventMenu : public Interface
{
    public:
    void display();
    virtual void display(std::vector<Event> event_holder);
    virtual ~AdminEventMenu(){};
};

#endif