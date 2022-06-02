#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Interface.h"
#include "/Users/gourav/Documents/CPP_project/include/Club.h"

#else

#include "Interface.h"
#include "Club.h"

#endif

#include <vector>

class AdminClubInfoMenu :public Interface
{
    public:
    void display();
    virtual void display(std::vector<Club>&);
};