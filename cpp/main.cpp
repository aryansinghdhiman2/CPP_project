#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/MainMenu.h"
#include "/Users/gourav/Documents/CPP_project/src/club_menu_initiator.cpp"
#include "/Users/gourav/Documents/CPP_project/src/event_menu_initiator.cpp"
#include "/Users/gourav/Documents/CPP_project/src/admin_menu_initiator.cpp"
#include "/Users/gourav/Documents/CPP_project/include/Event.h"

#else

#include "include/MainMenu.h"
#include "src/club_menu_initiator.cpp"
#include "src/event_menu_initiator.cpp"
#include "src/admin_menu_initiator.cpp"
#include "include/Event.h"

#endif

using namespace std;

int main() {
    
    MainMenu menu;// creating an object of type main menu. MainMenu is a class that is derieved from Interface class
    char input;
    bool has_invalid_input=0;
    menu.clear();// calling clear method.
    menu.display();//Calling display method
    for (;;)
    {
        cin >> input;
        cin.ignore(500,'\n');//ignores extra input 
        //see comment in club_menu_intiator under cin.ignore
        switch (input)
        {
        case '1':
            club_menu_initiator();
            break;
        case '2':
            event_menu_initiator();
            break;
        case '0':
            admin_menu_initiator();
            break;
        case 'q':
        case 'Q':
            return 0;
            break;
        default:
            cout<<"Invalid Input\nPlease Enter Character Again : ";
            has_invalid_input=1;
        }
        if (!has_invalid_input)
        {
            menu.clear();
            menu.display();
        }
    }
}
