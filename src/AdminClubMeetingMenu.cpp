#include "..\include\AdminClubMeetingMenu.h"
#include <iomanip>
#include <iostream>

void AdminClubMeetingMenu::display()
{
    std::cout << "[1] New Event" << std::setw(18) << "[2] Edit Event" << std::setw(28) << '\n';
    std::cout << "[3] Delete Event" << std::setw(25) << "[Q] Return to Admin Menu" << '\n';
    std::cout << "Enter Input corresponding to Action to be performed: ";
}