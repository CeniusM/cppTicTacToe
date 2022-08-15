#pragma once



class Board
{
public:
    char board[9]{};
    int player = 1;
    int turn = 0;
    int winner = 0;
    bool isGameOver = false;

    bool MakeMove(int move);

    void GameOverCheck();

    Board();
    ~Board();

private:

};

struct TTTLLX //TTTlonglongsX
{
	static const unsigned long long row1 = 65793;
	static const unsigned long long row2 = 1103823372288;
	static const unsigned long long row3 = 72339069014638592;
	static const unsigned long long col1 = 281474993487873;
	static const unsigned long long col2 = 72057598332895488;
	static const unsigned long long col3 = 1099511693312;

	static const unsigned long long topLeft = 4294967297;
	static const unsigned long long topRght = 281479271743488;
};

struct TTTLLY //TTTlonglongsY
{
	static const unsigned long long row1 = 131586;
	static const unsigned long long row2 = 2207646744576;
	static const unsigned long long row3 = 144678138029277184;
	static const unsigned long long col1 = 562949986975746;
	static const unsigned long long col2 = 144115196665790976;
	static const unsigned long long col3 = 2199023386624;

	static const unsigned long long topLeft = 8589934594;
	static const unsigned long long topRght = 562958543486976;
};