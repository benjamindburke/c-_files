//------------------------------------------------------------------------
//
//	Socialite class tester (main)
//
//	This class creates text and HTML output representing a person's
//	first and last name, a picture, and a website link with a
//	description
//
//------------------------------------------------------------------------
//
//	Author: Benjamin Burke - bdb55
//	Date: April 2017
//
//------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include "socialite.h"
using namespace std;

int main ()
{
    vector<socialite> socialites;
    string input;

    cout << "What input file would you like to open? .txt is automatically appended: ";
    cin >> input;
    input += ".txt";

    socialite::readFile(input, socialites);

    socialite::outputTo(socialites, cout);

    return 0;
}