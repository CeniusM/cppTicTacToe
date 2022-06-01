#include "Board.h"

#include <iostream>
#include <string>

bool Board::MakeMove(int move)
{
	if (board[move] != 0 || isGameOver)
		return false;

	//board[move] = player;
	turn++;

	if (turn == 9)
	{
		winner = 0;
		isGameOver = true;
		return true;
	}
	GameOverCheck();
	if (isGameOver)
	{
		winner = player;
		isGameOver = true;
		return true;
	}

	player ^= 0b11; // change player
}

void Board::GameOverCheck() // will just set the isgameover to true so no return needed
{
	// crap, i want to compare board arrayn as a long long so you can just compare the byte to a long
	// but long long is only 8 bytes and the board has 9, i guess il add an extra if statement in...

	// 8 combinations

	board[6];
	board[7];
	board[8];
	
	unsigned long long longBoard = (unsigned long long) & board; // WHY DOES LONGBOARD KEEP BEING JUNK?

	// rows
	if ((longBoard & TTTLL::row1) == TTTLL::row1 || (longBoard & TTTLL::row2) == TTTLL::row2 || (longBoard & TTTLL::row3) == TTTLL::row3)
	{
		isGameOver = true;
		return;
	}

}


Board::Board()
{

}

Board::~Board()
{

}




/*
#include "Board.h"

#include <iostream>
#include <string>

bool Board::MakeMove(int move)
{
	if (board[move] != 0 || isGameOver)
		return false;

	board[move] = player;
	turn++;

	if (turn == 9)
	{
		winner = 0;
		isGameOver = true;
		return true;
	}
	if (GameOverCheck())
	{
		winner = player;
		isGameOver = true;
		return true;
	}

	player ^= 0b11; // change player
	return true;
}

bool Board::GameOverCheck()
{
	int j;
	for (int i = 0; i < 3; i++)
	{
		j = i * 3;
		if (board[i] != 0 && board[i] == board[i + 3] && board[i + 3] == board[i + 6])
			return true;
		if (board[j] != 0 && board[j] == board[j + 1] && board[j + 1] == board[j + 2])
			return true;
	}

	if (board[0] != 0 && board[0] == board[4] && board[4] == board[8])
		return true;

	if (board[2] != 0 && board[2] == board[4] && board[4] == board[6])
		return true;

	return false;
}

Board::Board()
{
	player = 1;
	turn = 0;
	winner = 0;
	isGameOver = false;
}
Board::~Board()
{
	//free(board);
}
*/