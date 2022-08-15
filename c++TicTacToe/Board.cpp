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

	GameOverCheck();
	if (isGameOver)
	{
		winner = player;
		isGameOver = true;
		return true;
	}

	player ^= 0b11; // change player
	return true;
}

void Board::GameOverCheck()
{
	unsigned long long longBoard = (unsigned long long) * (unsigned long long*) & board[0];

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

Board::Board()
{

}

Board::~Board()
{

}