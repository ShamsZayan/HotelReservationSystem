#include "Guest.h"

Guest::Guest()
{
    //ctor
}

void Guest::setId(int x)
{
    id=x;
}
void Guest:: setUsername(string username)
{
    this->username=username;
}
int Guest::getId()
{
    return id;
}
void Guest::setTcost(int x)
{
    Tcost=x;
}
int Guest::getTcost()
{
    return Tcost;
}
int Guest::getPricePerNight()
{
    return pricePerNight;
}
string Guest::getUsername()
{
    return username;
}
int Guest::getRoom()
{
    return room;
}
void Guest::setRoom(int x)
{
    room=x;
}
/**<
void Guest:: setPricePerNight(int x)
{
    pricePerNight=x;
}
void Guest:: setSpa(int y)
{
    spa=y;
}
void Guest:: setDryCleaning;(int z)
{
    dryCleaning=z;
}
*/
Guest::~Guest()
{
    //dtor
}
