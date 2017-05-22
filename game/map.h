#ifndef __map_h__
#define __map_h__
#include <string>
using namespace std;

class map {
public:

	    //------------------------------------------------------
	    //----- Constructor ------------------------------------
	    //------------------------------------------------------

    map();

	    //------------------------------------------------------
	    //----- Inspectors -------------------------------------
	    //------------------------------------------------------

    string locate() const;
    string directions() const;

	    //------------------------------------------------------
	    //----- Mutators ---------------------------------------
	    //------------------------------------------------------

    void move(string str);
    void update();
    void face(int a);
    bool check();

private:

    int x_;
    int y_;
    int location_;
    int facing_;
    string north_;
    string east_;
    string south_;
    string west_;

};

#endif