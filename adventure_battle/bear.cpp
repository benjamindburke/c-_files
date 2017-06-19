#include "enemy.h"
#include "bear.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bear::bear():enemy("bear", 75, 30)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    int num = rand() % 14;
    //bear has 1/13 chance to be stronger and 1/13 chance to be my friend Noah
    if (num == 13)
	species_ = GRIZLORD;
    else if (num == 12)
	species_ = NOAH;
    else if (num >= 9)
	species_ = GRIZZLY;
    else if (num >= 6)
	species_ = BROWN;
    else if (num >= 3)
	species_ = POLAR;
    else
	species_ = BLACK;

    //basic bear attack name is gouges because basic attack is gouge
    enemy::attack_name_ = "gouges";
}

string bear::species() const
{
    //returns bear species as a string, with an easter egg to indirectly refer to Noah Cote
    switch (species_)
    {
	case BLACK: return "black";
	case POLAR: return "polar";
	case BROWN: return "brown";
	case GRIZZLY: return "grizzly";
	case NOAH: return "Papabear";
	case GRIZLORD: return "Grizlord";
    }
}

string bear::name() const
{
    //return bear name
    if (species_ == GRIZLORD || species_ == NOAH)
	return "the one and only " + species();
    else
	return species() + " " + enemy::name();
}

string bear::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns tips based on species
    switch (species_)
    {
	case GRIZLORD:
	    switch (rand() % 3)
	    {
		case 0: return "This bear seems much stronger than regular bears";
		case 1: return "It will seriously hurt me if I don't kill it fast!";
		case 2: return "I better not let it maul me!";
	    }
	default:
	    switch (rand() % 3)
	    {
		case 0: return "This bear could really hurt me if I'm not careful.";
		case 1: return "At least it wasn't the Grizlord. That thing is too much to handle.";
		case 2: return "If it mauls me, I'll be hurt much worse than a scratch or a bite.";
	    }
    }
}

string bear::out() const
{
    //returns a description of bear
    string result = "You have encountered ";
    if (species_ != GRIZLORD && species_ != NOAH)
	result += "a ";
    result += name() + "!\n";
    return result;
}

void bear::attack(enemy* my_enemy)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //determines at random which attack is used
    if (species_ != GRIZLORD)
    {
	//bear is least likely to maul because it is strongest attack
	int num = rand() % 9;
	if (num > 7)
	    maul(my_enemy);
	else if (num > 4)
	    gouge(my_enemy);
	else
	    bite(my_enemy);
    }
    else
    {
	switch(rand() % 3)
	{
	    //stronger bear is more likely to have stronger attacks
	    case 0: bite(my_enemy); break;
	    case 1: gouge(my_enemy); break;
	    case 2: maul(my_enemy); break;
	}
    }
}

void bear::gouge(enemy* my_enemy)
{
    //basic attack
    enemy::attack_name_ = "gouges";

    if (species_ == GRIZLORD)
	my_enemy->hit(35);
    else if (species_ == NOAH)
    {
	//Noah only does damage to himself as a joke
	enemy::attack_name_ = "doubts himself instead of attacking";
	enemy::hit(10);
    }
    else
	enemy::attack(my_enemy);
}

void bear::bite(enemy* my_enemy)
{
    //strong attack
    enemy::attack_name_ = "bites";

    if (species_ == GRIZLORD)
	my_enemy->hit(40);
    else if (species_ == NOAH)
    {
	//Noah only does damage to himself as a joke
	enemy::attack_name_ = "is too busy smoking to attack";
	enemy::hit(15);
    }
    else
	my_enemy->hit(20);
}

void bear::maul(enemy* my_enemy)
{
    //strongerst attack
    enemy::attack_name_ = "mauls";

    if (species_ != GRIZLORD)
	my_enemy->hit(60);
    else if (species_ == NOAH)
    {
	//Noah only does damage to himself as a joke
	enemy::attack_name_ = "lays down and cries instead of attacking";
	enemy::hit(25);
    }
    else
	my_enemy->hit(40);
}