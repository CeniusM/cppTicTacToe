#include "GUI.h"

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void PrintBoard(int *board, int *selecktedPiece)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i + (j * 3) == *selecktedPiece)
				SetConsoleTextAttribute(hConsole, 37);
			else
				SetConsoleTextAttribute(hConsole, 10);

			if (board[i + (j * 3)] == 0)
				cout << "[ ]";
			else if (board[i + (j * 3)] == 1)
				cout << "[X]";
			else
				cout << "[O]";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 10);
}