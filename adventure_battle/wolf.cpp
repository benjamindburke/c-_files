#include "enemy.h"
#include "wolf.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

wolf::wolf():enemy("wolf", 50, 20)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //color is chosen at random
    switch (rand() % 4)
    {
	case 0: color_ = BLACK; break;
	case 1: color_ = WHITE; break;
	case 2: color_ = BROWN; break;
	case 3: color_ = GREY; break;
    }

    //basic attack name
    enemy::attack_name_ = "scratches";
}

string wolf::color() const
{
    //returns color as a string
    switch (color_)
    {
	case BLACK: return "black";
	case WHITE: return "white";
	case BROWN: return "brown";
	case GREY: return "grey";
    }
}

string wolf::name() const
{
    //returns color and name of wolf
    return color() + " " + enemy::name();
}

string wolf::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns random tip
    switch(rand() % 3)
    {
	case 0: return "This wolf means business.";
	case 1: return "It will really hurt if it manages to sink its claws deep.";
	case 2: return "I hope all it does is scratches me.";
    }
}

void wolf::attack(enemy* my_enemy)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    int num = rand() % 9;
    //wolf is least likely to gouge because it's the storngest attack
    if (num > 7)
	gouge(my_enemy);
    else if (num > 4)
	bite(my_enemy);
    else
	scratch(my_enemy);
}

void wolf::scratch(enemy* my_enemy)
{
    //basic attack
    enemy::attack(my_enemy);
    enemy::attack_name_ = "scratches";
}

void wolf::bite(enemy* my_enemy)
{
    //strong attack
    my_enemy->hit(25);
    enemy::attack_name_ = "bites";
}

void wolf::gouge(enemy* my_enemy)
{
    //strongest attack
    my_enemy->hit(30);
    enemy::attack_name_ = "gouges";
}
