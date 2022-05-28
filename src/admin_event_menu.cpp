#ifndef _ADMIN_EVENT_MENU_

#define _ADMIN_EVENT_MENU_

#include "..\include\AdminEventMenu.h"
#include <fstream>
#include <vector>

void admin_event_menu()
{
    AdminEventMenu menu;
    std::cout<<"Going to Events";
    for(int i=0;i<4;i++)
    {
        menu.slow_dots_display();
    }

    menu.clear();

    std::fstream("event.txt",std::ios::in|std::ios::app|std::ios::out);
}

#endif