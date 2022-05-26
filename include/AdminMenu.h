#ifndef _ADMIN_MENU_H_

#define _ADMIN_MENU_H_

#include "Interface.h"

class AdminMenu : public Interface
{
    public:
    void display();
    virtual ~AdminMenu(){};
};

#endif