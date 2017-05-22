//------------------------------------------------------------------------
//
//	Socialite class header
//
//	This class creates text and HTML output representing a person's
//	first and last name, a picture, and a website link with a
//	description
//
//------------------------------------------------------------------------
//
//	Author: Benjamin Burke - bdb55
//	Date: April 2017
//
//------------------------------------------------------------------------
#ifndef __socialite_h__
#define __socialite_h__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class socialite
{
public:

	    //------------------------------------------------------
	    //----- Constructors -----------------------------------
	    //------------------------------------------------------

    socialite();	//Default constructor
    socialite(string last_name, string first_name, string user_id, string picture, string url, string description);	//Constructor with all attributes for ease of use

	    //------------------------------------------------------
	    //----- Inspectors -------------------------------------
	    //------------------------------------------------------

    string getLast() const;		//Return object's last name
    string getFirst() const;		//Return object's first name
    string getUserID() const;		//Return object's user id
    string getPicture() const;		//Return object's picture link
    string getURL() const;		//Return object's web link
    string getDescription() const;	//Return object's link description
    int getCliques() const;		//Return object's number of cliques
    string cliqueAt(int index) const;	//Return object's clique at vector index

	    //------------------------------------------------------
	    //----- Mutators ---------------------------------------
	    //------------------------------------------------------

    void setLast(string str);		//Change object's last name
    void setFirst(string str);		//Change object's first name
    void setUserID(string str);		//Change object's user id
    void setPicture(string str);	//Change object's picture link
    void setURL(string str);		//Change object's web link
    void setDescription(string str);	//Change object's link description
    void addClique(string str);		//Add clique to object's clique vector

	    //------------------------------------------------------
	    //----- Facilitators -----------------------------------
	    //------------------------------------------------------

    void outputText(ostream &os);	//Output object's attributes in a plain text format
    void outputHTML(ostream &os);	//Output object's attributes in an HTML webpage format
    static void readFile(string input, vector<socialite>& socialites); 	//Read variable number of socialites and cliques into socialite objects
    static void output(vector<socialite> socialites); 			//Loops outputText and outputHTML to files for each socialite for ease of use
    static void outputTo(vector<socialite> socialites, ostream& os);	//Loops outputText to generic ostream and outputHTML to files for each socialite for ease of use

private:

    string lastName_;
    string firstName_;
    string userID_;
    string picture_;
    string webURL_;
    string description_;
    vector<string> cliques_;
};
#endif