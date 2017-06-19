#ifndef __bat_h__
#define __bat_h__

#include "enemy.h"

#include <string>

using namespace std;

//bat is a type of enemy
class bat: public enemy
{
public:

    //bat has a unique species
    enum Species{FRUIT,BROWN,INDIANA,VAMPIRE};

    bat();

    //returns speices as a string
    string species() const;
    //returns name
    string name() const;
    //returns a cryptic tip related to bat's stats
    string tip() const;
    //provides a description of the bat
    string out() const;

private:

    //species variable
    Species species_;
};
#endif
