/********************************************************************************
 *	This file reads a .txt file as input, copies each unique word into a	*
 *	string vector, sorts the vector, and prints a sorted list of all of the *
 *	words into an output file specified by the user.			*
 ********************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool vector_contains(string s, vector<string> &words)
{
    for (int i = 0; i < words.size(); i++)
    {
	if (s == words[i])
	    return true;
    }
    return false;
}

void readFile(string fileName, vector<string> &v)
{
    ifstream infile;
    infile.open(fileName.c_str(), ios::in);

    string current_word;
    while (infile >> current_word)
    {
	if (vector_contains(current_word, v) == false)
	    v.push_back(current_word);
    }

    infile.close();
}

void swap(vector<string> &words, int x, int y)
{
    string temp = words[x];
    words[x] = words[y];
    words[y] = temp;
}

void sort(vector<string> &words)
{
    int j;
    for (int i = 0; i < words.size(); i++)
    {
	j = i;
	while (j > 0 && words[j- 1] > words[j])
	{
	    swap(words, j, j - 1);
	    j -= 1;
	}
    }
}

void output(vector<string> &words, string fileName)
{
    ofstream outfile;
    outfile.open(fileName.c_str(), ios::out);
    for (int i = 0; i < words.size(); i++)
    {
	outfile << words[i] << endl;
    }

    outfile.close();
}

int main()
{
    string iname, oname;
    vector<string> words;

    cout << "Enter filename: ";
    cin >> iname;
    iname += ".txt";

    readFile(iname, words);
    sort(words);

    cout << "Output filename: ";
    cin >> oname;
    oname += ".txt";

    output(words, oname);
    return 0;
}