#include "Board.h"

#include <iostream>
#include <string>

using namespace std;

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

    bool MakeMove(int move)
    {
        if (board[move] != 0 || isGameOver)
            return false;

        board[move] = player;
        turn++;

        if (GameOverCheck())
        {
            winner = player;
            isGameOver = true;
            return;
        }

        if (turn == 9)
        {
            winner = 0;
            isGameOver = true;
            return;
        }

        player ^= 0b11; // change player
    }

    bool GameOverCheck()
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

    Board()
    {
    }
    Board()
    {
    }
};