#ifndef _EVENT_MENU_H_

#define _EVENT_MENU_H_
#include <vector>
#include "Interface.h"
#include "Event.h"

class EventMenu : public Interface
{
    public:
    void display(){};
    void display(const std::vector<Event> &event_holder);
    virtual ~EventMenu(){};
};

#endif