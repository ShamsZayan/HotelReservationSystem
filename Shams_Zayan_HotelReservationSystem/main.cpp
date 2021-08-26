#include <iostream>
#include "Monster.h"
#include "Human.h"
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
// fn used to write in the file the guest's data after modified
void WriteInFile(vector<Guest> guestRooms)
{
    ofstream myfile ("Guest_List.txt");
    if (myfile.is_open())
    {
        for(int i=0; i<(int)guestRooms.size(); i++)
        {
            myfile << guestRooms[i].gender<<",";
            myfile << guestRooms[i].getUsername()<<",";
            myfile << guestRooms[i].getId()<<",";
            myfile << guestRooms[i].getTcost()<<",";
            myfile << guestRooms[i].getRoom()<<"\n";

        }

        myfile.close();
    }
    else
        cout << "Unable to open file";

}
// fn used to cancel reservation of the guests and decrease room numbers
void  cancelReservation(vector<Guest> guestRooms,int index,int & hRoom,int & mRoom)
{
    int i;
    cout << "do you  want to cancel the whole reservation?\n 1-yes \n 2-no" << endl;
    cin>>i;
    if(guestRooms[index].getPricePerNight()==500)
    {
        if(i==1)
        {
            hRoom-=guestRooms[index].getRoom();
            guestRooms.erase( guestRooms.begin()+index);
        }
        else if(i==2)
            cout << "no cancelation happened" << endl;
        else
            cout << "error" << endl;
    }
    else  if(guestRooms[index].getPricePerNight()==200)
    {

        if(i==1)
        {
            mRoom-=guestRooms[index].getRoom();
            guestRooms.erase( guestRooms.begin()+index);
        }
        else if(i==2)
            cout << "no cancelation happened" << endl;
        else
            cout << "error" << endl;
    }
    WriteInFile(guestRooms);

}
void  additionalService(vector<Guest> guestRooms,int index)
{
    int i,cost;
    cout << "do you want additional service?\n 1- spa \n 2-dry cleaning" << endl;
    cin>>i;
    //check if guest human or monster
    if(guestRooms[index].getPricePerNight()==500)
    {
        if(i==1)
        {
            cost=100+guestRooms[index].getTcost();
            guestRooms[index].setTcost(cost);
        }
        else if(i==2)
        {
            cost=70+guestRooms[index].getTcost();
            guestRooms[index].setTcost(cost);
        }
        else
            cout << "error" << endl;
    }
    else  if(guestRooms[index].getPricePerNight()==200)
    {

        if(i==1)
        {
            cost=50+guestRooms[index].getTcost();
            guestRooms[index].setTcost(cost);
        }
        else if(i==2)
        {
            cost=30+guestRooms[index].getTcost();
            guestRooms[index].setTcost(cost);
        }
        else
            cout << "error" << endl;
    }
    cout << "the new total cost is " <<cost<< endl;
    WriteInFile(guestRooms);
}
void  extendReservation(vector<Guest> guestRooms,int index)
{
    int night,cost;
    cout << "how long will you stay(night numbers)?" << endl;
    cin>>night;
    //check if guest human or monster
    if(guestRooms[index].getPricePerNight()==500)
    {

        cost=500*night+guestRooms[index].getTcost();
        //modify the guest total cost
        guestRooms[index].setTcost(cost);
    }
    else  if(guestRooms[index].getPricePerNight()==200)
    {

        cout << "how long will you stay(night numbers)?" << endl;
        cin>>night;
        cost=200*night+guestRooms[index].getTcost();
        guestRooms[index].setTcost(cost);
    }
    cout << "the new total cost is " <<cost<< endl;
    WriteInFile(guestRooms);
}
void  newReservation(vector<Guest> guestRooms,int index,int & hRoom,int & mRoom)
{
    int room,night,cost;
    cout << "how many rooms do you need?" << endl;
    cin>>room;
    ofstream myfile;
    myfile.open( "Guest_List.txt", ios::app );
    if (myfile.is_open())
    {
        if(guestRooms[index].getPricePerNight()==500)
        {
            //check if there is available rooms or not
            if(room+hRoom<=5)
            {
                myfile << "human,";
                myfile << guestRooms[index].getUsername()<<",";
                myfile << guestRooms[index].getId()<<",";
                hRoom+=room;
                cout << "how long will you stay(night numbers)?" << endl;
                cin>>night;
                cost=500*night*room;
                guestRooms[index].setTcost(cost);
                myfile << guestRooms[index].getTcost()<<",";
                myfile << room<<"\n";
                cout << "the total cost is " <<cost<< endl;
            }
            else
                cout << "No Empty Rooms" << endl;
        }
        else  if(guestRooms[index].getPricePerNight()==200)
        {

            if(room+mRoom<=15)
            {
                myfile << "monster,";
                myfile << guestRooms[index].getUsername()<<",";
                myfile << guestRooms[index].getId()<<",";
                mRoom+=room;
                cout << "how long will you stay(night numbers)?" << endl;
                cin>>night;
                cost=200*night*room;
                guestRooms[index].setTcost(cost);
                myfile << guestRooms[index].getTcost()<<",";
                myfile << room<<"\n";
                cout << "the total cost is " <<cost<< endl;
            }
            else
                cout << "No Empty Rooms" << endl;
        }
    }
    else
        cout << "Unable to open file";
}
inline void features(vector<Guest> guestRooms,int index,int & hRoom,int & mRoom)
{
    cout << "1- New Reservation \n 2-Extend Reservation \n 3-Additional service \n 4-Cancel Reservation" << endl;
    int i;
    cin>>i;
    if(i==1)
        newReservation(guestRooms,index,hRoom,mRoom);
    else if(i==2)
        extendReservation(guestRooms,index);
    else if(i==3)
        additionalService(guestRooms,index);
    else if(i==4)
        cancelReservation(guestRooms,index,hRoom,mRoom);
}
//check if there is a similar id or not like the new guest id
void checkId(vector<Guest> guestRooms,int & ran)
{
    for(int i=0; i<(int)guestRooms.size(); i++)
    {
        if(guestRooms[i].getId()==ran)
        {
            srand(time(NULL));
            ran=rand();
            checkId(guestRooms,ran);
        }

    }
}
//check if entered id  true or not
int checkId2(vector<Guest> guestRooms,int & id,int&check)
{
    int i;
    for( i=0; i<(int)guestRooms.size(); i++)
    {

        if(guestRooms[i].getId()==id)
        {
            check=1;
            return i;
        }

    }
    return i;
}
int main()
{

    vector<Guest> guestRooms;
    string guestState,guestNature,username,line;
    int id,index,hRoom=0,mRoom=0,check=0;
    //read from file data and put data in vectors
    ifstream myfile ("Guest_List.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {

            //convert string to non constant char array to be used in strtok
            char cstr[line.size() + 1];
            strcpy(cstr, line.c_str());
            char*token=strtok(cstr,",");
            if(string(token).compare("monster")==0)
            {
                Monster m;
                m.gender=string(token);
                token = strtok (NULL, ",");
                m.setUsername(token);
                token = strtok (NULL, ",");
                m.setId(atoi(token));
                token = strtok (NULL, ",");
                m.setTcost(atoi(token));
                token = strtok (NULL, ",");
                m.setRoom(atoi(token));
                mRoom+=atoi(token);
                guestRooms.push_back(m);
            }
            else
            {
                Human h;
                h.gender=string(token);
                token = strtok (NULL, ",");
                h.setUsername(token);
                token = strtok (NULL, ",");
                h.setId(atoi(token));
                token = strtok (NULL, ",");
                h.setTcost(atoi(token));
                token = strtok (NULL, ",");
                h.setRoom(atoi(token));
                hRoom+=atoi(token);
                guestRooms.push_back(h);
            }
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";

    cout << "Are you New or Old guest?" << endl;
    cin>>guestState;
    // convert string to back to lower case
    transform(guestState.begin(), guestState.end(), guestState.begin(), ::tolower);
    if(guestState.compare("new")==0)
    {
        cout << "Are you Human or Monster?" << endl;
        cin>>guestNature;
        cout << "what is your username?" << endl;
        cin>>username;
        transform(guestNature.begin(), guestNature.end(), guestNature.begin(), ::tolower);
        if(guestNature.compare("monster")==0)
        {
            //creating monster object and assign it to guest variable
            Monster m;
            m.setUsername(username);
            srand(time(NULL));
            int ran=rand();
            checkId(guestRooms,ran);
            m.setId(ran);
            guestRooms.push_back(m);
            cout << "your id is "<<ran << endl;
            cout << "if you want to login please inter your id" << endl;
            cin>>id;
            index= checkId2(guestRooms,id,check);

        }
        else if(guestNature.compare("human")==0)
        {
            Human h;
            h.setUsername(username);
            srand(time(NULL));
            int ran=rand();
            checkId(guestRooms,ran);
            h.setId(ran);
            guestRooms.push_back(h);
            cout << "your id is "<<ran << endl;
            cout << "if you want to login please inter your id" << endl;
            cin>>id;
            index=checkId2(guestRooms,id,check);
        }

    }
    else if(guestState.compare("old")==0)
    {
        cout << " Enter your id :"<< endl;
        cin>>id;
        index= checkId2(guestRooms,id,check);

    }
    // check is flag for true id
    if(check)
        features(guestRooms,index,hRoom,mRoom);
    return 0;
}
