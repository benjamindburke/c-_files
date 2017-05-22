#include "map.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

	    //------------------------------------------------------
	    //----- Constructor ------------------------------------
	    //------------------------------------------------------

map::map()
{
    x_ = 1;
    y_ = 1;
    location_ = ((y_ - 1) * 19) + x_;
    facing_ = 1;
    north_ = "forwards";
    east_ = "right";
    south_ = "backwards";
    west_ = "left";
}

	    //------------------------------------------------------
	    //----- Inspectors -------------------------------------
	    //------------------------------------------------------

string map::locate() const
{
    stringstream os;
    os << "You are in square ";
    os << location_;
    os << ", located at x = ";
    os << x_;
    os << ", y = ";
    os << y_;
    os << ".";
    string str = os.str();
    return str;
}

string map::directions() const
{
    string str = "You are facing ";
    switch (facing_)
    {
	case 1: str += "north. "; break;
	case 2: str += "east. "; break;
	case 3: str += "south. "; break;
	case 4: str += "west. "; break;
    }
    str += "North is " + north_ + ". ";
    str += "East is " + east_ + ". ";
    str += "South is " + south_ + ". ";
    str += "West is " + west_ + ".";
    return str;
}

	    //------------------------------------------------------
	    //----- Mutators ---------------------------------------
	    //------------------------------------------------------

void map::move(string str)
{
    int move;

    if (str == "forwards") move = 1;
    else if (str == "right") move = 2;
    else if (str == "backwards") move = 3;
    else if (str == "left") move = 4;
    else cout << "This is an invalid direction to move in. Forwards, backwards, left or right only." << endl;

    switch (facing_)
    {
	case 1:
	    switch (move)
	    {
		case 1: y_++; face(1); break;
		case 2: x_++; face(2); break;
		case 3: y_--; face(3); break;
		case 4: x_--; face(4); break;
	    } break;

	case 2:
	    switch (move)
	    {
		case 1: x_++; face(2); break;
		case 2: y_--; face(3); break;
		case 3: x_--; face(4); break;
		case 4: y_++; face(1); break;
	    } break;

	case 3:
	    switch (move)
	    {
		case 1: y_--; face(3); break;
		case 2: x_--; face(4); break;
		case 3: y_++; face(1); break;
		case 4: x_++; face(2); break;
	    } break;

	case 4:
	    switch (move)
	    {
		case 1: x_--; face(4); break;
		case 2: y_++; face(1); break;
		case 3: x_++; face(2); break;
		case 4: y_--; face(3); break;
	    } break;
    }

    location_ = ((y_ - 1) * 19) + x_;

}

void map::update()
{
    switch (facing_)
    {
	case 1: north_ = "forwards"; east_ = "right"; south_ = "backwards"; west_ = "left"; break;
	case 2: north_ = "left"; east_ = "forwards"; south_ = "right"; west_ = "backwards"; break;
	case 3: north_ = "backwards"; east_ = "left"; south_ = "forwards"; west_ = "right"; break;
	case 4: north_ = "right"; east_ = "backwards"; south_ = "left"; west_ = "forwards"; break;
    }
}

void map::face(int dir)
{
    facing_ = dir;
    update();
}

bool map::check()
{
    if (x_ < 1)
    {
	cout << "You can move no further in this direction." << endl;
	x_ = 1;
	return false;
    }

    else if (x_ > 19)
    {
	cout << "You can move no further in this direction." << endl;
	x_ = 19;
	return false;
    }

    else if (y_ < 1)
    {
	cout << "You can move no further in this direction." << endl;
	y_ = 1;
	return false;
    }

    else if (y_ > 19)
    {
	cout << "You can move no further in this direction." << endl;
	y_ = 19;
	return false;
    }

    else return true;
}