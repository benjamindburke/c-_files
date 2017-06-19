#ifndef __bear_h__
#define __bear_h__

#include "enemy.h"

#include <iostream>
#include <string>

using namespace std;

//bear is a type of enemy
class bear: public enemy
{
public:

    //bear has unique species type that modifies damage dealt
    enum Species{BLACK,POLAR,BROWN,GRIZZLY,NOAH,GRIZLORD};

    bear();

    //returns speices as a string
    string species() const;
    //returns name
    string name() const;
    //returns tip based on bear's stats
    string tip() const;
    //returns description of the bear
    string out() const;

    //attack method chooses between following attacks
    void attack(enemy* my_enemy);
    //basic attack
    void gouge(enemy* my_enemy);
    //strong attack
    void bite(enemy* my_enemy);
    //strongest attack
    void maul(enemy* my_enemy);

private:

    Species species_;
};
#endif
