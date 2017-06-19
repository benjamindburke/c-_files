#include "enemy.h"
#include "rat.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

rat::rat():enemy("rat", 20, 10)
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
    enemy::attack_name_ = "bites";
}

string rat::color() const
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

string rat::name() const
{
    //returns color and name of rat
    return color() + " " + enemy::name();
}

string rat::tip() const
{
    //set random seed
    srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
    //returns random tip
    switch(rand() % 3)
    {
	case 0: return "This rat is pretty weak...";
	case 1: return "This rat couldn't hurt me if it tried!";
	case 2: return "Of all things, a rat. This will be too easy.";
    }
}