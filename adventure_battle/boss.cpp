#include "enemy.h"
#include "hero.h"
#include "boss.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


boss::boss():hero("Satan")
{
    hero::shielded_ = false;
    hero::fireballs_ = 2;
    hero::potions_ = 1;
}

string boss::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns random tip about boss
    switch(rand() % 3)
    {
	case 0: return "He's the hero of the creatures that bring darkness to this land!";
	case 1: return "He can shield and fireball too!";
	case 2: return "I must take him out at all costs.";
    }
}

string boss::out() const
{
    //returns description of boss
    return "You have encountered " + name() + "!\n";
}

int boss::fireballs() const
{
    //returns amount of fireballs remaining
    return hero::fireballs();
}

int boss::max_fireballs() const
{
    //returns max amount of fireballs
    return 2;
}

int boss::potions() const
{
    //return boss's potions
    return hero::potions();
}

int boss::max_potions() const
{
    //returns max amount of potions
    return 1;
}

void boss::attack(enemy* my_enemy)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));

    //boss uses potion instead of attacking if health <= 50
    if (enemy::health() <= 50 && hero::potions_ > 0)
    {
	hero::potion();
	enemy::attack_name_ = "uses a potion instead of attacking";
    }
    else if (hero::fireballs_ > 0)
    {
	//boss is most likely to attack but has the chance to shield or fireball if he has fireballs
	switch(rand() % 5)
	{
	    case 0: enemy::attack(my_enemy); enemy::attack_name_ = "slashes"; break;
	    case 1: enemy::attack(my_enemy); enemy::attack_name_ = "slashes"; break;
	    case 2: enemy::attack(my_enemy); enemy::attack_name_ = "slashes"; break;
	    case 3: hero::shield(); enemy::attack_name_ = "shields instead of attacking"; break;
	    case 4: hero::fireball(my_enemy); enemy::attack_name_ = "throws a fireball at"; break;
	}
    }
    else
    {
	//boss will not try to fireball if there are no fireballs left
	switch(rand() % 4)
	{
	    case 0: enemy::attack(my_enemy); enemy::attack_name_ = "slashes"; break;
	    case 1: enemy::attack(my_enemy); enemy::attack_name_ = "slashes"; break;
	    case 2: enemy::attack(my_enemy); enemy::attack_name_ = "slashes"; break;
	    case 3: hero::shield(); enemy::attack_name_ = "shields instead of attacking"; break;
	}
    }
}

void boss::hit(int amount)
{
    //boss uses hero version which has shield modifier
    hero::hit(amount);
}

void boss::potion()
{
    //boss uses potion
    hero::potion();
    enemy::attack_name_ = "uses a potion instead of attacking";
}
