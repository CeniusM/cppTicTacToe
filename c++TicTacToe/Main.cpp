#include "Board.h"
#include "Main.h"
#include "GUI.h"
#include "GetKeyStroke.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    //KEY_EVENT_RECORD key;
    //for (; ; )
    //{
    //    getconchar(key);
    //    std::cout << "key: " << key.uChar.AsciiChar
    //        << " code:  " << key.wVirtualKeyCode << std::endl;
    //}
    KEY_EVENT_RECORD key;

    Board* board = new Board;
    int move = 0;
    bool moveSucces = true;
    int selecktedPiece = 0;

    while (!board->isGameOver)
    {
        if (!moveSucces)
            cout << "It must be a num from and too 0 - 8, and the spot can not be taken" << endl;

        getconchar(key);
        system("CLS");

        switch (key.uChar.AsciiChar)
        {
        case 'w':
            if (selecktedPiece % 3 != 0)
                selecktedPiece -= 1;
        case 'a':
            if (!(selecktedPiece - 3 < 0))
                selecktedPiece -= 3;
        case 's':
            if (selecktedPiece != 8)
                selecktedPiece++;
        case 'd':
            if (!(selecktedPiece + 3 > 8))
                selecktedPiece += 3;
        default:
            break;
        }

        PrintBoard(board->board, &selecktedPiece);

        if (key.wVirtualKeyCode == 32)
            moveSucces = board->MakeMove(move);
    }

    cout << "well played... i think" << endl;

    delete board;
}