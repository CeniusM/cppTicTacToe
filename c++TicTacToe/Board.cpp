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

	// new, avg = ~650ms, just for comparison...
	GameOverCheck();
	if (isGameOver)
	{
		winner = player;
		isGameOver = true;
		return true;
	}


	// old, avg = ~775ms, just for comparison...
	//if (GameOverCheckOld())
	//{
	//	winner = player;
	//	isGameOver = true;
	//	return true;
	//}

	player ^= 0b11; // change player
}

void Board::GameOverCheck() // will just set the isgameover to true so no return needed
{
	// crap, i want to compare board arrayn as a long long so you can just compare the byte to a long
	// but long long is only 8 bytes and the board has 9, i guess il add an extra if statement in...

	// 8 combinations * 2

	//board[0] = 2;
	//board[4] = 2;
	//board[8] = 2;

									// is the relly necesary ??, no clue, dont wanna keep trying
	unsigned long long longBoard = (unsigned long long) *(unsigned long long*) & board[0];

	// need to check 8 place becous long long 1 byte to short

	if (player == 1)
	{
		if (
			// rows
			(longBoard & TTTLLX::row1) == TTTLLX::row1 ||
			(longBoard & TTTLLX::row2) == TTTLLX::row2 ||
			((longBoard & TTTLLX::row3) == TTTLLX::row3 && board[8] == 1) ||

			// collums
			(longBoard & TTTLLX::col1) == TTTLLX::col1 ||
			(longBoard & TTTLLX::col2) == TTTLLX::col2 ||
			((longBoard & TTTLLX::col3) == TTTLLX::col3 && board[8] == 1) ||

			// diagonal
			((longBoard & TTTLLX::topLeft) == TTTLLX::topLeft && board[8] == 1) ||
			(longBoard & TTTLLX::topRght) == TTTLLX::topRght
			)
		{
			isGameOver = true;
				return;
		}
	}
	else
	{
		if (
			// rows
			(longBoard & TTTLLY::row1) == TTTLLY::row1 ||
			(longBoard & TTTLLY::row2) == TTTLLY::row2 ||
			((longBoard & TTTLLY::row3) == TTTLLY::row3 && board[8] == 2) ||

			// collums
			(longBoard & TTTLLY::col1) == TTTLLY::col1 ||
			(longBoard & TTTLLY::col2) == TTTLLY::col2 ||
			((longBoard & TTTLLY::col3) == TTTLLY::col3 && board[8] == 2) ||

			// diagonal
			((longBoard & TTTLLY::topLeft) == TTTLLY::topLeft && board[8] == 2) ||
			(longBoard & TTTLLY::topRght) == TTTLLY::topRght
			)
		{
			isGameOver = true;
			return;
		}
	}

}

bool Board::GameOverCheckOld()
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