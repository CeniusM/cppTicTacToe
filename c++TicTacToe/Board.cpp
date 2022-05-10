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
}

bool Board::GameOverCheck()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i] != 0 && board[i] == board[i + 3] && board[i + 3] == board[i + 6])
			return true;
		if (board[i * 3] != 0 && board[(i * 3)] == board[(i * 3) + 1] && board[(i * 3) + 1] == board[(i * 3) + 2])
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