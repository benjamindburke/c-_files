/************************************************************************
 *	This program takes a .txt list of dictionary words and checks	*
 *	for misspelled words in a second given file. The included	*
 *	dictionary file would be "cs172-lab6-english_words.txt".	*
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void read(string filename, vector<string> &words)
{
    string word;

    ifstream input;
    input.open(filename.c_str(), ios::in);

    while (input >> word)
    {
	words.push_back(word);
    }

    input.close();
}

bool search(vector<string> words, string word, int from, int to)
{
    int pivot = (from + to) / 2;

    if (from == to)
    {
	if (word == words[from])
	    return true;
	else
	    return false;
    }

    else if (from > to)
	return false;

    else
    {
	if (words[pivot] == word)
	    return true;

	else if (words[pivot] > word)
	    return search(words, word, from, pivot - 1);

	else if (words[pivot] < word)
	    return search(words, word, pivot + 1, to);
    }
}

int main ()
{
    string filename;
    cout << "Enter a dictionary: ";
    cin >> filename;
    filename += ".txt";

    vector<string> dictionary;

    read(filename, dictionary);

    std::sort(dictionary.begin(), dictionary.end());

    filename = "";
    cout << "Enter a file to spellcheck: ";
    cin >> filename;
    filename += ".txt";

    vector<string> check_words;

    read(filename, check_words);
    //std::sort(check_words.begin(), check_words.end());

    ofstream output;
    output.open("output.txt", ios::out);

    for (int i = 0; i < check_words.size(); i++)
    {
	string target = check_words[i];
	
	string::iterator new_end = remove_if(target.begin(), target.end(), ::ispunct);
	target.erase(new_end, target.end());

	string temp = target;
	
        transform(target.begin(), target.end(), temp.begin(), ::tolower);
	
	check_words[i] = temp;
    }

    std::sort(check_words.begin(), check_words.end());

    for (int i = 0; i < check_words.size(); i++)
    {
	if (search(dictionary, check_words[i], 0, (dictionary.size() - 1)) == false)
	    output << check_words[i] << endl;
    }

    output.close();
    return 0;
}