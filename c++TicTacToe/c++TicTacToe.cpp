#include "Board.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello World!\n";

    cout << "Write your name here" << endl;

    string input;

    getline(cin, input);

    cout << "hi " << input << "You will now have to play TicTacToe" << endl;


    Board* board = new Board;
    int move;
    bool moveSucces;

    while (!board->isGameOver)
    {
        cout << "Type in a number" << endl;

        getline(cin, input);

        try
        {
            move = stoi(input);
        }
        catch (const std::exception&)
        {
            cout << "Error, must type in a valid num" << endl;
            continue;
        }

        moveSucces = board->MakeMove(move);

        if (moveSucces)
        {
            PrintBoard(board->board);
        }
        else
        {
            cout << "It must be a num from and too 0 - 8, and the spot can not be taken" << endl;
        }
    }

    cout << "well played... i think" << endl;

    delete board;
}

void PrintBoard(int* board)
{
    for (int i = 0; i < 3; i++)
    {
        string output;
        for (int j = 0; j < 3; j++)
        {
            if (board[i + (j * 3)] == 0)
                output += "[ ]";
            else if (board[i + (j * 3)] == 1)
                output += "[X]";
            else
                output += "[O]";
        }
        cout << output << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
