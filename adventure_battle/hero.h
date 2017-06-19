#ifndef __hero_h__
#define __hero_h__

#include "enemy.h"

#include <string>
#include <iostream>

using namespace std;

//hero is a type of enemy
class hero: public enemy
{
public:

    hero(string name);

    //returns number of potions
    int potions() const;
    //returns number of fireballs
    int fireballs() const;

    //a type of attack() method that does more damage than regular attack
    void fireball(enemy* my_enemy);
    //heals hero
    void potion();
    //causes hero to take less damage for one turn
    void shield();
    //how hero takes damage - includes damage modifier if hero uses shield
    void hit(int amount);

protected:

    //protected so boss can access them
    int potions_;
    int fireballs_;
    bool shielded_;

};
#endif