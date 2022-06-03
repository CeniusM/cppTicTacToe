#pragma once



class Board
{
public:
    char board[9]{}; // no byte aparenty, just char
    int player = 1;
    int turn = 0;
    int winner = 0;
    bool isGameOver = false;

    bool MakeMove(int move);

    void GameOverCheck();
    bool GameOverCheckOld();

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










//struct mLL // myLongLongs, what a name
//{
//    //const static long long row1X = (long long)new int*{ 1, 1, 1, 0, 0, 0, 0, 0, 0};
//    //const static M9DT row1X = M9DT({9,9,9,9,9,9,9,9,9});
//    //const static long long row1XLastByte = 0b1;
//    //M9DT test = (M9DT)0b111111111111111111;
//};
//
//
///// <summary>
///// since the int will be stacktin maby you will be able to compare
///// this struckt with serten preset varibles to the board array
///// </summary>
//struct M9DT //My9ByteDataTyepe, what a name
//{
//    int b[9];
//    M9DT()
//    {
//        // since this will be used at startup only i'll just do this crap code
//        for (int i = 0; i < 9; i++)
//        {
//            //b[i] = arr[i];
//        }
//    }
//};