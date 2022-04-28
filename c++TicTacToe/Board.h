#pragma once



class Board
{
public:
    int board[9]{};
    int player;
    int turn;
    int winner;
    bool isGameOver;

    bool MakeMove(int move);

    bool GameOverCheck();

    Board();
    ~Board();

private:

};