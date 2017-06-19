#include "enemy.h"
#include "deer.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

deer::deer():enemy("deer", 60, 6)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //50/50 chance of being male or femals
    switch (rand() % 2)
    {
	case 0: gender_ = MALE; break;
	case 1: gender_ = FEMALE; break;
    }

    //basic attack name
    enemy::attack_name_ = "charges at";
}

string deer::name() const
{
    //returns gender as a string
    switch (gender_)
    {
	case MALE: return "buck";
	case FEMALE: return "doe";
    }
}

string deer::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns random tip
    switch (rand() % 3)
    {
	case 0: return "Deer are large but mostly harmless.";
	case 1: return "Deer are usually gentle and shy.";
	case 2: return "Deer are large creatures but they startle easily.";
    }
}

void deer::run()
{
    //rather than writing new function, deer just takes damage equal to max health
    enemy::hit(60);
    enemy::attack_name_ = "runs away from";
}

void deer::attack(enemy* my_enemy)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    int num = rand() % 10 + 1;
    //40% chance to run away
    if (num > 6)
	run();
    else
	enemy::attack(my_enemy);
}
