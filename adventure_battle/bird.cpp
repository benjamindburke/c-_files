#include "enemy.h"
#include "bird.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bird::bird():enemy("bird", 40, 4)
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //species is chosen at random
    switch (rand() % 6)
    {
	case 0: species_ = SPARROW; break;
	case 1: species_ = VULTURE; break;
	case 2: species_ = SEAGULL; break;
	case 3: species_ = CARDINAL; break;
	case 4: species_ = CROW; break;
	case 5: species_ = GRACKEL; break;
    }

    //basic attack name
    enemy::attack_name_ = "poops on";
}

string bird::species() const
{
    //returns speices as a string
    switch (species_)
    {
	case SPARROW: return "sparrow";
	case VULTURE: return "vulture";
	case SEAGULL: return "seagull";
	case CARDINAL: return "cardinal";
	case CROW: return "crow";
	case GRACKEL: return "grackel";
    }
}

string bird::name() const
{
    //returns species, no point in saying grackel bird or sparrow bird - just sparrow
    return species();
}

string bird::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns random tip
    switch(rand() % 3)
    {
	case 0: return "Is this bird gonna poop on me?";
	case 1: return "I think the worst this bird could do is poop on me.";
	case 2: return "It would be a total waste of a fireball, but some grilled poultry would be nice.";
    }
}
