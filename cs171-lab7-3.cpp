#include <iostream>
using namespace std;

/************************************************************************
 *	This program is an exercise in recursion. I had a lot of fun	*
 * 	toying with the input numbers and font size on my terminal to	*
 * 	see how ludicrous the fractals were.				*
 ************************************************************************/

void fractal(int length, int spaces)
{
    if (length == 1)
    {
	for (int i = 0; i < spaces; i++){ cout << " "; }
	cout << "*" << endl;
    }

    else 
    {
	fractal((length / 2), spaces);
	for (int i = 0; i < spaces; i++){ cout << " "; }
	for (int i = 0; i < length; i++){ cout << "*"; }
    cout << endl;
    fractal((length / 2), (spaces + (length / 2)));
    }
}

int main ()
{
    int x;
    cout << "Fractal Generator" << endl;
    cout << "Enter an integer > 0: ";
    cin >> x;
    fractal(x, 0);
    return 0;
}