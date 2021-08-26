#ifndef MONSTER_H
#define MONSTER_H
#include "Guest.h"
using namespace std;

class Monster:public Guest
{
    public:
        Monster();
        virtual ~Monster();
    protected:

    private:
};

#endif // MONSTER_H
