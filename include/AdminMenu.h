#ifndef _ADMIN_MENU_H_

#define _ADMIN_MENU_H_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"

#else

#include "Interface.h"

#endif

class AdminMenu : public Interface
{
    public:
    void display();
    virtual ~AdminMenu(){};
};

#endif