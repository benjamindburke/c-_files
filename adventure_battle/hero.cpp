#include "enemy.h"
#include "hero.h"

#include <iostream>
#include <string>

using namespace std;

hero::hero(string name):enemy(name, 100, 16)
{
    shielded_ = false;
    fireballs_ = 10;
    potions_ = 6;
}

int hero::potions() const
{
    //returns number of potions
    return potions_;
}

int hero::fireballs() const
{
    //returns number of fireballs
    return fireballs_;
}

void hero::potion()
{
    //uses potion if theres 1 or more potions left
    if (potions_ > 0)
    {
	//hero takes negative damage - acts as healing
	enemy::hit(-50);
	potions_--;
    }
}

void hero::fireball(enemy* my_enemy)
{
    //enemy takes damage greater than sword damage
    if (fireballs_ > 0)
    {
	my_enemy->hit(30);
	fireballs_--;
    }
}

void hero::shield()
{
    //modifies shielded to be true
    shielded_ = true;
}

void hero::hit(int amount)
{
    //if shielded, hero takes less damage
    if (shielded_)
	enemy::hit(amount / 2);
    else
	enemy::hit(amount);

    //after hero takes damage, shielded changes to false - does not modify if already false
    shielded_ = false;
}