#ifndef __chains_h__
#define __chains_h__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class chains
{
private:
    //static vector<string> next(string word, vector<string> & words);

    static bool contains(string s, vector<vector<string> > words);

    static void swap(vector<string> &words, int x, int y);

    static int partition(vector<string> &words, int from, int to);

    //static int count(vector<string> words);

public:
    static void sort(vector<string> &words, int from, int to);

    static void readFile(string file_name, vector<string> & words);

    static void print(ostream & os, vector<string> words);

    static void trim(vector<string> & words);

    static vector<string> next(string word, vector<string> & words);

    static void link(vector<string> words, vector<vector<string> > & chains);

    //static string follows(vector<string> words);
};

#endif