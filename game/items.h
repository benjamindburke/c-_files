#ifndef __items_h__
#define __items_h__
#include "map.h"

using namespace std;

class items
{
private:
    unsigned long seed;
    int items[19][19];
public:

    items();

    populate();

    search(int x, int y);

    take();

};

#endif