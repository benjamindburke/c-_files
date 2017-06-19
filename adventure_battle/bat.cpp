#include "enemy.h"
#include "bat.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bat::bat():enemy("bat", 20, 6)
{
    //Set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //species is chosen at random
    switch (rand() % 4)
    {
	case 0: species_ = FRUIT; break;
	case 1: species_ = BROWN; break;
	case 2: species_ = INDIANA; break;
	case 3: species_ = VAMPIRE; break;
    }

    //bat's attack name
    enemy::attack_name_ = "bites";
}

string bat::species() const
{
    //returns bat's species as a string
    switch (species_)
    {
	case FRUIT: return "fruit";
	case BROWN: return "brown";
	case INDIANA: return "indiana";
	case VAMPIRE: return "vampire";
    }
}

string bat::name() const
{
    return species() + " " + enemy::name();
}

string bat::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns random tip
    switch(rand() % 3)
    {
	case 0: return "This bat is pretty weak...";
	case 1: return "This bat looks relatively harmless";
	case 2: return "It isn't much of a threat.";
    }
}

string bat::out() const
{
    //returns a description of the enemy
    string result = "You have encountered ";
    if (species_ == INDIANA)
	result += "an ";
    else
	result += "a ";
    result += name() + "!\n";
    return result;
}
