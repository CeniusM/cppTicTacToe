#pragma once



class Board
{
public:
    int board[9]{};
    int player = 1;
    int turn = 0;
    int winner = 0;
    bool isGameOver = false;

    bool MakeMove(int move);

    bool GameOverCheck();

    Board();
    ~Board();

private:

};





/*
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
*/