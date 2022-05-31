#include"Interface.h"
#include<vector>
#include"Club.h"
class AdminClubInfoMenu :public Interface
{
    public:
    void display();
    virtual void display(std::vector<Club>&);
};