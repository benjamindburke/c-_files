#ifndef __bird_h__
#define __bird_h__

#include "enemy.h"

#include <iostream>
#include <string>

using namespace std;

class bird: public enemy
{
public:

    //unique species type
    enum Species{SPARROW,VULTURE,CARDINAL,SEAGULL,CROW,GRACKEL};

    bird();

    //returns species as a string
    string species() const;
    //returns name of bird
    string name() const;
    //returns random tip based on bird stats
    string tip() const;

private:

    Species species_;
};

#endif
