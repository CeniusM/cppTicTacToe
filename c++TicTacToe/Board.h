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

    Board();
    ~Board();

private:

};

struct TTTLL //TTTlonglongs
{
    static const long long row1 = 2512783134208;
    static const long long row2 = 2074635587888;
    static const long long row3 = 2427892990080;
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