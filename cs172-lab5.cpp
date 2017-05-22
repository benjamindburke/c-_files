/************************************************************************
 *	Similar to the cs172-lab4.cpp file, this program reads a file	*
 *	and sorts the words based on a method specified by the user.	*
 *	Valid sort methods are insertion sort and quick sort, which uses*
 *	partitioning. The chrono library times how long each operation	*
 *	takes for comparision.						*
 ***********************************************************************/

#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void swap(vector<string> &words, int x, int y)
{
    string temp = words[x];
    words[x] = words[y];
    words[y] = temp;
}

void read(string filename, vector<string> &words)
{
    ifstream input;
    input.open(filename.c_str(), ios::in);

    string word;

    while(input >> word)
    {
	words.push_back(word);
    }

    input.close();
}

void write(string filename, vector<string> words)
{
    ofstream output;
    output.open(filename.c_str(), ios::out);

    for (int i = 0; i < words.size(); i++)
    {
	output << words[i] << endl;
    }

    output.close();
}

void insertionSort(vector<string> &words)
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

int partition(vector<string> &words, int from, int to)
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

void quickSort(vector<string> &words, int from, int to)
{
    if (from >= to) return;
    int p = partition(words, from, to);
    quickSort(words, from, p);
    quickSort(words, p + 1, to);
}

int main ()
{
    vector<string> words;

    string filename, response;

    cout << "Enter filename (.txt is appended): ";
    cin >> filename;
    filename += ".txt";

    read(filename, words);

    cout << "Which sort method is being executed? ";
    cin >> response;

    unsigned long start = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);

    if (response == "insertion")
	insertionSort(words);			//took 802775 milliseconds - over 13 min.
    else if (response == "quick")
	quickSort(words, 0, words.size() - 1);	//took 342 milliseconds - < 1/2 a second.

    unsigned long finish = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);

    cout << "This sort took " << finish - start << " milliseconds to run" << endl;

    cout << "Final filename (.txt is appended): ";
    cin >> filename;
    filename += ".txt";

    write(filename, words);

    return 0;
}