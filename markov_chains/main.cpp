#include "chains.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    vector<string> words;
    string file_name;

    ifstream input_files;
    input_files.open("input_files.txt", ios::in);
    while (input_files >> file_name)
    {
	chains::readFile(file_name, words);
    }
    input_files.close();

    chains::trim(words);

    //chains::sort(words, 0, words.size() - 1);

    //vector<vector<string> > chains;

    //chains::link(words, chains);

    //chains::print(cout, chains[0]/*words*/);

    string word;
    cout << "Word: ";
    cin >> word;

    chains::print(cout, chains::next(word, words));

    return 0;
}