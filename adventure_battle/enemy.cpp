#include "enemy.h"

#include <string>

using namespace std;

//prototype for all derivatives
enemy::enemy(string name, int health, int strength)
{
    name_ = name;
    health_ = health;
    max_health_ = health;
    strength_ = strength;
    dead_ = false;
}

int enemy::health() const
{
    //returns current health
    return health_;
}

int enemy::max_health() const
{
    //returns max health
    return max_health_;
}

bool enemy::dead() const
{
    //return true if enemy is dead
    return dead_;
}

int enemy::fireballs() const
{
    //returns 0 because basic enemies have no fireballs
    return 0;
};

int enemy::max_fireballs() const
{
    //returns 0 because basic eneimes have no fireballs
    return 0;
}

int enemy::potions() const
{
    //returns 0 because basic enemies have no potions
    return 0;
};

int enemy::max_potions() const
{
    //returns 0 because basic enemies have no potions
    return 0;
}

string enemy::name() const
{
    //returns enemy name
    return name_;
}

string enemy::tip() const
{
    //each enemy has different specified tip method
    return "";
}

string enemy::attack_name() const
{
    //returns enemy attack name
    return attack_name_;
}

string enemy::out() const
{
    //returns description of the enemy
    return "You have encountered a " + name() + "!\n";
};

void enemy::fireball()
{
    //does nothing, but is included because main throws problems if 1 or more enemies in the vector don't have access to fireball method
    //only boss enemy has access to a working fireball method
};

void enemy::potion()
{
    //does nothing, but is included because main throws problems if 1 or more enemies in the vector don't have access to potion method
    //only boss enemy has access to a working potion method
};

void enemy::hit(int amount)
{
    //how enemy takes damage
    health_ -= amount;

    //if health < 0 health is set to 0 and dead changes to true
    if (health_ <= 0)
    {
	health_ = 0;
	dead_ = true;
    }

    if (health_ >= 100)
	health_ = 100;
}

//how enemy deals damage
//method is passed enemy pointer which then uses the hit method to take damage
void enemy::attack(enemy* my_enemy)
{
    if (!dead_)
	my_enemy->hit(strength_);
}
