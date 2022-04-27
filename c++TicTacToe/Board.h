#pragma once

class Board
{
public:
    int board[9];
    int player;
    int turn;
    int winner;
    bool isGameOver;
    Board();
    ~Board();
	bool MakeMove(int);
	bool GameOverCheck();
};