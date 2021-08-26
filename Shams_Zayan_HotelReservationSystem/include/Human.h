#ifndef HUMAN_H
#define HUMAN_H
#include "Guest.h"
using namespace std;

class Human :public Guest
{
    public:
        Human();
        int room;
        virtual ~Human();
    protected:

    private:

};

#endif // HUMAN_H
