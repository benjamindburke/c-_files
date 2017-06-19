#ifndef __rat_h__
#define __rat_h__

#include "enemy.h"

#include <iostream>
#include <string>

using namespace std;

class rat: public enemy
{
public:

    //unique color type
    enum Color{BLACK,WHITE,BROWN,GREY};

    rat();

    //returns color as a string
    string color() const;
    //returns name of rat
    string name() const;
    //returns random tip about rat stats
    string tip() const;

private:

    //color variable
    Color color_;
};

#endif
