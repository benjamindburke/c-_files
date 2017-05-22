#include "symbol.h"
#include "tic.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

tBoard::tBoard()
{
    for (int row = 0; row < 3; row++)
    {
	for (int col = 0; col < 3; col++)
	{
	    board_[row][col] = BLANK;
	}
    }
}

bool tBoard::move(symbol m, int x, int y)
{
    if (board_[x][y] == BLANK && (x >= 0 && x <= 2) && (y >= 0 && y <= 2))
    {
	board_[x][y] = m;
	return true;
    }
    else
	return false;
}

bool tBoard::game_over()
{

//If all spaces are not blank, game is over because no more moves can be made
    if (board_[0][0] != BLANK && board_[0][1] != BLANK && board_[0][2] != BLANK &&
	board_[1][0] != BLANK && board_[1][1] != BLANK && board_[1][2] != BLANK &&
	board_[2][0] != BLANK && board_[2][1] != BLANK && board_[2][2] != BLANK)
	    return true;

//Case to stop game after 3 consecutive symbol win case
    else if (winner() != BLANK)
	return true;

    return false;
}

symbol tBoard::winner()
{

//3 in a row win cases
    if (board_[0][0] == board_[0][1] && board_[0][0] == board_[0][2] && board_[0][0] != BLANK)
    {
	if (board_[0][0] == X)
	    return X;
	else
	    return O;
    }

    else if (board_[1][0] == board_[1][1] && board_[1][0] == board_[1][2] && board_[1][0] != BLANK)
    {
	if (board_[1][0] == X)
	    return X;
	else
	    return O;
    }

    else if (board_[2][0] == board_[2][1] && board_[2][0] == board_[2][2] && board_[2][0] != BLANK)
    {
	if (board_[2][0] == X)
	    return X;
	else
	    return O;
    }


//3 in a column win cases
    else if (board_[0][0] == board_[1][0] && board_[0][0] == board_[2][0] && board_[0][0] != BLANK)
    {
	if (board_[0][0] == X)
	    return X;
	else
	    return O;
    }

    else if (board_[0][1] == board_[1][1] && board_[0][1] == board_[2][1] && board_[0][1] != BLANK)
    {
	if (board_[0][1] == X)
	    return X;
	else
	    return O;
    }

    else if (board_[0][2] == board_[1][2] && board_[0][2] == board_[2][2] && board_[0][2] != BLANK)
    {
	if (board_[0][2] == X)
	    return X;
	else
	    return O;
    }


//3 in a diagonal win cases
    else if (board_[0][0] == board_[1][1] && board_[0][0] == board_[2][2] && board_[0][0] != BLANK)
    {
	if (board_[0][0] == X)
	    return X;
	else
	    return O;
    }

    else if (board_[0][2] == board_[1][1] && board_[0][2] == board_[2][0] && board_[0][2] != BLANK)
    {
	if (board_[0][2] == X)
	    return X;
	else
	    return O;
    }


//Tie/no winner end case - also used to test whether game is over
    else
	return BLANK;

}

symbol tBoard::at(int row, int col)
{
    return board_[row][col];
}

ostream & operator<<(ostream& os, tBoard myTable)
{
    os << " |  0  |  1  |  2  |" << endl;
    os << " +-----------------+" << endl;
    os << "0|  " << myTable.at(0, 0) << "  |"
	 << "  " << myTable.at(0, 1) << "  |"
	 << "  " << myTable.at(0, 2) << "  |" << endl;
    os << " +-----------------+" << endl;
    os << "1|  " << myTable.at(1, 0) << "  |"
	 << "  " << myTable.at(1, 1) << "  |"
	 << "  " << myTable.at(1, 2) << "  |" << endl;
    os << " +-----------------+" << endl;
    os << "2|  " << myTable.at(2, 0) << "  |"
	 << "  " << myTable.at(2, 1) << "  |"
	 << "  " << myTable.at(2, 2) << "  |" << endl;
    os << " +-----------------+" << endl;
}