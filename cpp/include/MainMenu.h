#ifndef _MAIN_MENU_H_

#define _MAIN_MENU_H_

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"

#else

#include "Interface.h"

#endif

class MainMenu : public Interface
{
    public:
    void display();
    virtual ~MainMenu(){};
};

#endif