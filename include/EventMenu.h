#ifndef _EVENT_MENU_H_

#define _EVENT_MENU_H_
#include <vector>
#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"
#include "/Users/gourav/Documents/CPP_project/include/Event.h"

#else

#include "Interface.h"
#include "Event.h"

#endif

class EventMenu : public Interface
{
    public:
    void display(){};
    virtual void display(const std::vector<Event> &event_holder);
    virtual ~EventMenu(){};
};

#endif