#ifndef __deer_h__
#define __deer_h__

#include "enemy.h"

#include <iostream>
#include <string>

using namespace std;

//deer is a type of enemy
class deer: public enemy
{
public:

    //deer has a unique gender
    enum Gender{MALE,FEMALE};

    deer();

    //returns name
    string name() const;
    //returns random tip about deer stats
    string tip() const;

    //deer has a chance to run away from battle
    void run();
    //deer attacks with a chance to run
    void attack(enemy* my_enemy);

private:

    //gender variable
    Gender gender_;
};
#endif
