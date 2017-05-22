// CS 172 - Assignment 3 - Tic-Tac-Toe
// Main File by Mark Boady
// Drexel University 2016

//You may add new methods (public or private) and new private attributes.
//You may NOT remove or change any methods given.

#ifndef _TIC_TAC_TOE_
#define _TIC_TAC_TOE_

#include <iostream>
#include <string>
#include "symbol.h"
using namespace std;

class tBoard
{
	private:
		//You can pick your own data structure
		symbol board_ [3][3];
	public:
		//Default Constructor
		//Makes a board with all blank spaces
		tBoard();
		//Makes a move on the board
		//X is the row and y is the column
		//m is the symbol to place (either X or O)
		//It returns true if the move was made
		//If the move is illegal, return false and do not change the table
		bool move(symbol m, int x, int y);
		//Returns true if the game is over
		//This could be because of a winner or because of a tie
		bool game_over();
		//Returns who won X or O.
		//If the game was a tie, return  BLANK
		symbol winner();
		//Returns symbol at location (row, col) within array
		symbol at(int row, int col);
};
//Overload the output operator for whole game board
ostream & operator<<(ostream& os, tBoard myTable);

#endif
