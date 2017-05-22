//------------------------------------------------------------------------
//
//	Socialite class implementation
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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "socialite.h"
using namespace std;

	//-----------------------------------------------------------------------
	//----- Constructors ----------------------------------------------------
	//-----------------------------------------------------------------------

socialite::socialite()
{
    lastName_ = "";
    firstName_ = "";
    userID_ = "";
    picture_ = "";
    webURL_ = "";
    description_ = "";
}

socialite::socialite(string last, string first, string user, string pic, string url, string description)
{
    lastName_ = last;
    firstName_ = first;
    userID_ = user;
    picture_ = pic;
    webURL_ = url;
    description_ = description;
}

	//-----------------------------------------------------------------------
	//----- Inspectors ------------------------------------------------------
	//-----------------------------------------------------------------------

string socialite::getLast() const
{
    return lastName_;
}

string socialite::getFirst() const
{
    return firstName_;
}

string socialite::getUserID() const 
{
    return userID_;
}

string socialite::getPicture() const
{
    return picture_;
}

string socialite::getURL() const
{
    return webURL_;
}

string socialite::getDescription() const
{
    return description_;
}

int socialite::getCliques() const
{
    return cliques_.size();
}

string socialite::cliqueAt(int i) const
{
    return cliques_.at(i);
}

	//-----------------------------------------------------------------------
	//----- Mutators --------------------------------------------------------
	//-----------------------------------------------------------------------

void socialite::setLast(string str)
{
    lastName_ = str;
}

void socialite::setFirst(string str)
{
    firstName_ = str;
}

void socialite::setUserID(string str)
{ 
    userID_ = str;
}

void socialite::setPicture(string str)
{
    picture_ = str;
}

void socialite::setURL(string str)
{
    webURL_ = str;
}

void socialite::setDescription(string str)
{
    description_ = str;
}

void socialite::addClique(string str)
{
    cliques_.push_back(str);
}

	//-----------------------------------------------------------------------
	//----- Facilitators ----------------------------------------------------
	//-----------------------------------------------------------------------

void socialite::outputText(ostream &os) //output text suitable for terminal or .txt formatting
{
    os << "First name: " << firstName_ << endl;
    os << "Last name : " << lastName_ << endl;
    os << "User ID: " << userID_ << endl;
    os << "Picture: " << picture_ << endl;
    os << "Website: " << webURL_ << endl;
    os << "Website description: " << description_ << endl;
    os << "Cliques: ";
    for (int i = 0; i < cliques_.size(); i++)
    {
	os << cliques_[i] << ((i != cliques_.size() - 1) ? ", " : "\n\n");
    }
}

void socialite::outputHTML(ostream &os) //output text in HTML format
{
    os << "<!doctype html>\n<html>" << endl;
    os << "  <head>\n    <title>" << firstName_ << " " << lastName_ << "'s Socialite</title>\n  </head>" << endl;
    os << "  <body>\n  <center>" << endl;
    os << "    <h2>" << userID_ << "</h3>" << endl;
    os << "    <h3>" << firstName_ << " " << lastName_ << "</h3>" << endl;
    os << "    <img src=\"" << picture_ << "\"></img>\n    <hr>" << endl;
    os << "    " << firstName_ << " wants to share <a HREF=\"" << webURL_ << "\">" << description_ << "</a> with you:" << endl;
    os << "    <br>    " << webURL_ << endl;
    os << "    <p><i>Cliques:</i></p>" << endl;
    os << "    <ul>" << endl;
    for (int i = 0; i < cliques_.size(); i++)
    {
	os << "      <li>" << cliques_[i] << "</li>" << endl;
    }
    os << "    </ul>" << endl;
    os << "  </center>\n  </body>\n</html>" << endl;
}

void socialite::readFile(string filename, vector<socialite>& socialites)
{
    ifstream file;
    file.open(filename.c_str(), ios::in);

    string userid, firstn, lastn, picture, url, description, clique = "";
    int i = 0;

    while (!file.eof())
    {
	file >> userid;
	file >> firstn;
	file >> lastn;
	file >> picture;
	file >> url;
	file.ignore();
	getline(file, description);
	socialites.push_back(socialite(lastn, firstn, userid, picture, url, description));

	while (true)
	{
	    getline(file, clique);
	    if (clique == "++++")
		break;
	    else
		socialites[i].addClique(clique);
	}

	clique = "";
	i++;
    }

    file.close();
}

void socialite::output(vector<socialite> socialites)
{
    for (int i = 0; i < socialites.size(); i++)
    {
	ofstream textFile;
	ofstream htmlFile;

	string file_text = socialites[i].getUserID() + ".txt";
	string file_html = socialites[i].getUserID() + ".html";

	textFile.open(file_text.c_str(), ios::out);
	htmlFile.open(file_html.c_str(), ios::out);

	socialites[i].outputText(textFile);
	socialites[i].outputHTML(htmlFile);

	textFile.close();
	htmlFile.close();
    }
}

void socialite::outputTo(vector<socialite> socialites, ostream& os)
{
    for (int i = 0; i < socialites.size(); i++)
    {
	socialites[i].outputText(os);

	ofstream htmlFile;
	string file_html = socialites[i].getUserID() + ".html";
	htmlFile.open(file_html.c_str(), ios::out);
	socialites[i].outputHTML(htmlFile);
	htmlFile.close();
    }
}

