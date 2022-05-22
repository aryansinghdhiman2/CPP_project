#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "include/MainMenu.h"
#include "src/club_menu_initiator.cpp"
#include "src/event_menu_initiator.cpp"
#include "src/admin_menu_initiator.cpp"
#include "include/Event.h"

using namespace std;

int main() {
    
    MainMenu menu;
    char input;
    menu.display();
    for (;;)
    {
        cin >> input;

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
        default:
            cout<<"Invalid Input\nPlease Enter Character Again : ";
        }
    }
}