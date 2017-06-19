#ifndef __boss_h__
#define __boss_h__

#include "enemy.h"
#include "hero.h"

#include <iostream>
#include <string>

using namespace std;

//boss is a type of hero - has fireballs, has potions and can shield
class boss: public hero
{
public:

    boss();

    //returns tip
    string tip() const;
    //returns description of boss
    string out() const;
    //returns amount of fireballs
    int fireballs() const;
    //returns max amount of fireballs
    int max_fireballs() const;
    //returns amount of potions
    int potions() const;
    //returns max amount of potions
    int max_potions() const;

    //boss attacks choose at random between shielding, using a fireball and using a potion
    void attack(enemy* my_enemy);
    //takes damage with possibility of shield
    void hit(int amount);
    //uses potion
    void potion();

};
#endif
