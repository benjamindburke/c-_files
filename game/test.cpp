#include "map.h"
#include <string>
#include <iostream>
using namespace std;

int main ()
{
    map map;

    string response;

    while (response != "break")
    {
	//cout << "What is your command: ";
	cin >> response;
	if (response == "locate") cout << map.locate() << endl;
	else if (response == "directions") cout << map.directions() << endl;
	else if (response == "move")
	{
	    //cout << "In which direction? ";
	    cin >> response;
	    map.move(response);
	    map.check();
	    //cout << map.directions() << endl << map.locate() << endl;
	}
    }

    return 0;
}