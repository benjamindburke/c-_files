/************************************************************************
 *	This program has a bunch of predetermined functions that run	*
 *	in a vector of functions through another function that creates	*
 *	a generalized input | output table.				*
 *									*
 *	This is my first experience working with pointers and vectors	*
 *	that take functions as inputs.					*
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int square(int a)
{
    return a * a;
}

int cube(int a)
{
    return a * a * a;
}

int two_n(int n)
{
    if (n == 0)
	return 1;
    else
	return 2 * two_n(n - 1);
}

int factorial(int n)
{
    if (n == 0)
	return 1;
    else
	return n * factorial(n - 1);
}

int fib(int n)
{
    if (n == 0)
	return 0;
    if (n == 1)
	return 1;
    else
	return fib(n - 1) + fib(n - 2);
}

int perrin(int n)
{
    if (n == 0)
	return 3;
    if (n == 1)
	return 0;
    if (n == 2)
	return 2;
    else
	return perrin(n - 2) + perrin(n - 3);
}

void make_function_table(string title, int (*f)(int))
{
    cout << "Testing Function " << title << endl;

    for (int i = 0; i <= 40; i++)
    {
	cout << setw(3) << i << "|" << setw(10) << f(i) << endl;
    }
}

int main()
{
    vector<int (*)(int)> my_functions = {square, cube, two_n, factorial, fib, perrin};
    vector<string> titles = {"Square", "Cube", "2^n", "Factorial", "Fibonacci", "Perrin"};

    for (int i = 0; i < my_functions.size(); i++)
    {
	make_function_table(titles[i], my_functions[i]);
	cout << endl;
    }

    return 0;
}
