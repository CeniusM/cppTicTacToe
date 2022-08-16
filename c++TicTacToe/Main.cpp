#include "Board.h"
#include "GUI.h"
#include "GetKeyStroke.h"
#include "TTTTest.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	//TestTTTWER();

	//KEY_EVENT_RECORD key;
	//for (; ; )
	//{
	//    getconchar(key);
	//    std::cout << "key: " << key.uChar.AsciiChar
	//        << " code:  " << key.wVirtualKeyCode << std::endl;
	//}

	while (true)
	{

		KEY_EVENT_RECORD key;

		Board* board = new Board;
		bool moveSucces = true;
		int selecktedPiece = 0;

		// !!! for debbuging
		//board->MakeMove(selecktedPiece);

		PrintBoard(board->board, &selecktedPiece);

		while (!board->isGameOver)
		{
			if (!moveSucces)
				cout << "It must be a num from and too 0 - 8, and the spot can not be taken" << endl;

			getconchar(key);
			//        system("CLS");

			switch (key.uChar.AsciiChar)
			{
			case 'w':
				if (selecktedPiece % 3 != 0)
					selecktedPiece -= 1;
				break;
			case 'a':
				if (!(selecktedPiece - 3 < 0))
					selecktedPiece -= 3;
				break;
			case 's':
				if (selecktedPiece != 8)
					selecktedPiece++;
				break;
			case 'd':
				if (!(selecktedPiece + 3 > 8))
					selecktedPiece += 3;
				break;
			default:
				break;
			}

			if (key.wVirtualKeyCode == 32)
				moveSucces = board->MakeMove(selecktedPiece);

			PrintBoard(board->board, &selecktedPiece);
		}


		switch (board->winner)
		{
		case 0:
			cout << "what a game, well played both of you" << endl;
			break;
		case 1:
			cout << "Well played the the player with [X] :D" << endl;
			break;
		case 2:
			cout << "Well played the the player with [O] :D" << endl;
			break;
		default:
			cout << "what the heck" << endl;
			break;
		}

		delete board;


		cout << "press 'r' to play again" << endl;
		getconchar(key);
		if (key.uChar.AsciiChar != 'r')
			break;
	}
}