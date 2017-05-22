#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/************************************************************************
 *	This program is the earliest work using file inputs and outputs.*
 *	I reference it often when I've had trouble working with more	*
 *	advanced file input/output manipulations.			*
 *									*
 *	This program takes a file as input and counts the words that	*
 *	start with each letter and adds them to an output file		*
 *	"results_<letter>.txt". It also makes a ubiquitous word count.	*
 ************************************************************************/

int starts_with_letter(string filename, char letter)
{
    string resName = "results_";
    resName += letter;
    resName += ".txt";
    string word;
    int count = 0;

    ofstream outfile;
    outfile.open(resName.c_str(), ios::out);

    ifstream infile;
    infile.open(filename.c_str(), ios::in);

    while (infile >> word)
    {
	if (word.at(0) == letter || word.at(0) == letter + 32)
	{
	    outfile << word << endl;
	    count++;
	}
    }
    
    infile.close();
    outfile.close();
    return count;
}

int main ()
{
    string filename;
    int total = 0;

    cout << "Enter the name of file to read: ";
    cin >> filename;

    for (char i = 'A'; i <= 90; i++)
    {
	cout << "Count of words that start with " << i << ": " 
	     << starts_with_letter(filename, i) << endl;
	total += starts_with_letter(filename, i);
    }
    cout << "Total words: " << total << endl;
    return 0;
}