#include "chains.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 ---------------------------
        Private methods
 ---------------------------
*/

bool chains::contains(string s, vector<vector<string> > words)
{
    for (int i = 0; i < words.size(); i++)
    {
	if (s == words[i][0])
	    return true;
    }
    return false;
}

void chains::swap(vector<string> &words, int x, int y)
{
    string temp = words[x];
    words[x] = words[y];
    words[y] = temp;
}

int chains::partition(vector<string> &words, int from, int to)
{
    string pivot = words[from];
    int i = from - 1;
    int j = to + 1;
    while (i < j)
    {
	i++;

	while (words[i] < pivot)
	{
	    i++;
	}

	j--;

	while (words[j] > pivot)
	{
	    j--;
	}

	if (i < j)
	    swap(words, i, j);
    }

    return j;
}

/*int chains::count(vector<string> words)
{
    
}*/

/*
 ---------------------------
        Public methods
 ---------------------------
*/

void chains::sort(vector<string> &words, int from, int to)
{
    if (from >= to) return;
    int p = partition(words, from, to);
    sort(words, from, p);
    sort(words, p + 1, to);
}

void chains::readFile(string file_name, vector<string> & words)
{
    ifstream input_file;
    input_file.open(file_name.c_str(), ios::in);

    string s;

    while (input_file >> s)
    {
	words.push_back(s);
    }

    input_file.close();
}

void chains::print(ostream & os, vector<string> words)
{
    for (int i = 0; i < words.size(); i++)
    {
	os << words[i] << endl;
    }
}

void chains::trim(vector<string> & words)
{
    for (int i = 0; i < words.size(); i++)
    {
	string target = words[i];
	
	string::iterator new_end = remove_if(target.begin(), target.end(), ::ispunct);
	target.erase(new_end, target.end());

	string temp = target;
	
        transform(target.begin(), target.end(), temp.begin(), ::tolower);
	
	words[i] = temp;
    }
}

vector<string> chains::next(string word, vector<string> & words)
{
    vector<string> next_words;
    next_words.push_back(word); // first word is index 0, then it's followed by words that commonly follow it

    for (int i = 0; i < words.size(); i++)
    {
	if (words[i] == word)
	    next_words.push_back( words[i + 1] );
    }

    return next_words;
}

void chains::link(vector<string> words, vector<vector<string> > & chains)
{
    for (int i = 0; i < words.size(); i++)
    {
	vector<string> next_words = next(words[i], words);
	if (!(contains(next_words[0], chains)))
	{
	    chains.push_back(next_words);
	}
    }
}

/*string chains::follows(vector<string> words)
{
    string most_common;

    vector<int> counts;

    for (int i = 0; i < counts.size(); i++)
    {
	
	
    }

    int max = counts[0];

    for (int i = 1; i < counts.size(); i++)
    {
	if (
    }
}*/








