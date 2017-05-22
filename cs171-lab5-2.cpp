#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/************************************************************************
 *	This program takes a number between 1 and 3999 and converts	*
 *	it into roman numerals.						*
 *									*
 *	This program is one of the earliest with a separate function to *
 *	return a value rather than having main() do the work.		*
 ************************************************************************/

string romanNumerals(int num)
{
    int ones, tens, huns, thous;
    string romans = "";
    
    //Extract numbers one by one
    ones = num % 10;
    num /= 10;
    tens = num % 10;
    num /= 10;
    huns = num % 10;
    num /= 10;
    thous = num % 10;

    //Convert to Roman Numerals starting with thousands and going to ones
    switch (thous)
    {
	case 0: break;
	case 1: romans += "M"; break;
	case 2: romans += "MM"; break;
	case 3: romans += "MMM"; break;
    }
    
    switch (huns)
    {
	case 0: break;
	case 1: romans += "C"; break;
	case 2: romans += "CC"; break;
	case 3: romans += "CCC"; break;
	case 4: romans += "CD"; break;
	case 5: romans += "D"; break;
	case 6: romans += "DC"; break;
	case 7: romans += "DCC"; break;
	case 8: romans += "DCCC"; break;
	case 9: romans += "CM"; break;
    }
    
    switch (tens)
    {
	case 0: break;
	case 1: romans += "X"; break;
	case 2: romans += "XX"; break;
	case 3: romans += "XXX"; break;
	case 4: romans += "XL"; break;
	case 5: romans += "L"; break;
	case 6: romans += "LX"; break;
	case 7: romans += "LXX"; break;
	case 8: romans += "LXXX"; break;
	case 9: romans += "XC"; break;
    }
    
    switch (ones)
    {
	case 0: break;
	case 1: romans += "I"; break;
	case 2: romans += "II"; break;
	case 3: romans += "III"; break;
	case 4: romans += "IV"; break;
	case 5: romans += "V"; break;
	case 6: romans += "VI"; break;
	case 7: romans += "VII"; break;
	case 8: romans += "VIII"; break;
	case 9: romans += "IX"; break;
    }
    
    return romans;
}

int main ()
{
    int num;
    cout << "Roman Numeral generator. Enter 0 to quit." << endl;
    do
    {
	cout << "Enter a number between 1 and 3,999: ";
	cin >> num;
	cout << "Roman Numerals:" << setfill(' ') << setw(10) << romanNumerals(num) << endl;
    } while (num > 0 && num < 4000);
    return 0;
}