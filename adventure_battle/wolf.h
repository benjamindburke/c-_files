#ifndef __wolf_h__
#define __wolf_h__

#include "enemy.h"

#include <iostream>
#include <string>

using namespace std;

//wolf is a type of enemy
class wolf: public enemy
{
public:

    //unique color modifier
    enum Color{BLACK,WHITE,BROWN,GREY};

    wolf();

    //returns color as a string
    string color() const;
    //returns name of wolf
    string name() const;
    //returns random tip about wolf stats
    string tip() const;

    //attack method randomly chooses between following attacks
    void attack(enemy* my_enemy);
    //basic attack
    void scratch(enemy* my_enemy);
    //strong attack
    void bite(enemy* my_enemy);
    //strongest attack
    void gouge(enemy* my_enemy);

private:

    //color variable
    Color color_;
};

#endif
