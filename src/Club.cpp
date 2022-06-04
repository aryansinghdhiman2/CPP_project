#ifdef __APPLE__

#include "/Users/gourav/Documents/CPP_project/include/Club.h"

#else

#include"..\include\Club.h"

#endif
Club::Club(std::fstream &input)
{
    if(input)
    {
        std::getline(input,name);
        std::getline(input,convener);
        std::getline(input,co_convener);
        std::getline(input,social_media_id);
        std::getline(input,description);
        int t=input.tellg();//gets rid of the bug which causes getline to read last line twice.
        //for getting rid of unused variable warning by the compiler
        if(t==-2)
            std::cout<<"This should not be possible\n";
    }
}
void Club::display_name() const
{
    std::cout<<this->name<<"\n";
}
void Club::display_convener() const
{
    std::cout<<this->convener<<"\n";
}
void Club::display_co_convener() const
{
    std::cout<<this->co_convener<<"\n";
}
void Club::display_social_media_id() const
{
    std::cout<<this->social_media_id<<"\n";
}
void Club::display_description() const
{
    std::cout<<this->description<<"\n";
}
Club::Club(std::string name,std::string convener,std::string co_convener,std::string social_media_id,std::string description)
{
    this->name=name;
    this->convener=convener;
    this->co_convener=co_convener;
    this->description=description;
}