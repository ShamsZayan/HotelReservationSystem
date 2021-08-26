#ifndef GUEST_H
#define GUEST_H
#include<string>
using namespace std;

class Guest
{
public:
    Guest();
    virtual ~Guest();
    void setId(int x);
    void setTcost(int x);
     void setUsername(string username);
     void setRoom(int x);
     string getUsername();
     int getId();
     int getTcost();
     int getPricePerNight();
     int getRoom();
     string gender;
protected:

     int pricePerNight;
    int spa;
    int dryCleaning;
private:
    string username;
    int id;
    int Tcost;
    int room;
};

#endif // GUEST_H
