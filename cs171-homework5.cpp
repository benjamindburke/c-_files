/* Benjamin Burke
 * CS 171-061
 * Homework 5
 */

/********************************************************************************
 *	This program is a basic replication of a NASA training game designed	*
 *	as part of a new astronaut's training. This was created under a set	*
 *	of guidelines given by course intructors and is in no way meant to	*
 *	infringe upon any copyrighted material. 				*
 *										*
 *	This program asks the user for an amount of fuel to burn and then	*
 *	calculates the lander's speed and distance from the moon's surface	*
 *	each second. This data is outputted to the user each second, with a	*
 *	second meaning each time the program's functions execute, rather than	*
 *	an actual second in real time. This runs until the distance from the	*
 *	surface is less than zero, and then a final calculation on the time	*
 *	and speed of contact is determined.					*
 ********************************************************************************/

//Known issues - burn amount is not assured to be non-negative

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void reportStatus (ostream& os, double time, double height, double velocity, double fuel, string name)
{
    os << endl << "Status of your " << name << " spacecraft:" << endl;
    os << "Time  : " << time << " seconds" << endl;
    os << "Height: " << height << " feet" << endl;
    os << "Speed : " << velocity << " feet/second" << endl;
    if (fuel <= 0) os << "***OUT OF FUEL***" << endl;
    else os << "Fuel  : " << fuel << endl;
}

void updateStatus (double& velocity, double burn, double& fuel, double& height)
{
    fuel -= burn;
    height -= ((velocity + (velocity + 5 - burn)) / 2);
    velocity = velocity + (5 - burn);
}

void finalAnalysis (ostream& os, double velocity)
{
    if (velocity >= 50) os << "You totaled an entire mountain!" << endl << "Your family will be notified...by post." << endl;
    else if (velocity > 30) os << "Your ship is a wreck!" << endl << "Your family will be notified...by post." << endl;
    else if (velocity > 10) os << "You blasted a huge crater!" << endl << "Your family will be notified...by post." << endl;
    else if (velocity > 5) os << "Your ship is a heap of junk!" << endl << "Your family will be notified...by post." << endl;
    else if (velocity > 2) os << "You blew it!" << endl << "Your family will be notified...by post." << endl;
    else if (velocity > 0) os << "A little bumpy." << endl;
    else if (velocity == 0) os << "Congratulations! A perfect landing!" << endl << "Your license will be renewed...later." << endl;
}

void introduction (ostream& os, string target, string replacement)
{
    string word;
    ifstream instr;
    instr.open("instructions.txt", ios::in);
    while (instr >> word)
    {
	if (word == target) os << replacement << " ";
	else if (word == "(1)" || 
		 word == "(2)" || 
		 word == "(3)" || 
		 word == "(4)" || 
		 word == "(5)") os << endl << word << " ";
	else os << word << " ";
    }
    os << endl;
    instr.close();
}

void touchdown (double& elapsedTime, double& velocity, double& burn, double& height, string name)
{
    height += ((velocity + (velocity - 5 + burn)) / 2);
    velocity = velocity - 5 + burn;
    double delta = ((sqrt((velocity*velocity) + (height * (10 - (2 * burn))))) - velocity) / (5 - burn);
    elapsedTime = (elapsedTime - 1) + delta;
    velocity += (5 - burn) * delta;
    height = 0;
}

void simulate (ostream& os, string name)
{
    double burn, time, height = 1000, velocity = 50, fuel = 150;

    for (time = 0; height != 0; time++)
    {
	if (height <= 0)
	{
	    touchdown(time, velocity, burn, height, name);
	    cout << endl << endl << "*****CONTACT*****" << endl;
	    cout << "Touchdown at " << time << " seconds." << endl;
	    cout << "Landing velocity = " << velocity << " feet/sec." << endl;
	    cout << fuel << " units of fuel remaining." << endl << endl;
	    os << "*****CONTACT*****" << endl;
	    os << "Touchdown at " << time << " seconds." << endl;
	    os << "Landing velocity = " << velocity << " feet/sec." << endl;
	    os << fuel << " units of fuel remaining." << endl << endl;
	    finalAnalysis(cout, velocity);
	    finalAnalysis(os, velocity);
	}
	else
	{
	    reportStatus(cout, time, height, velocity, fuel, name);
	    reportStatus(os, time, height, velocity, fuel, name);

	    if (fuel > 0)
	    {
		cout << "Enter fuel burn amount: ";
		cin >> burn;
		os << "Enter fuel burn amount: " << burn << endl;
		if (burn > fuel) burn = fuel;
	    }
	    else burn = 0;

	    updateStatus(velocity, burn, fuel, height);
	}
    }
}

int main () 
{
    cout << "Would you like to see the instructions? ";
    char intro;
    cin >> intro;
    if (intro == 'Y' || intro == 'y') introduction(cout, "$SPACECRAFT", "APOLLO");

    string name, output;
    cout << "The name of your spacecraft: ";
    cin >> name;
    cout << "The name of the file to log this session to (don't write .txt): ";
    cin >> output;
    output += ".txt";
    ofstream outfile;
    outfile.open(output.c_str(), ios::out);

    simulate(outfile, name);

    outfile.close();
    return 0;
}