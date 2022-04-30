#include "Board.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>  // for high_resolution_clock
#include <thread>

void TestTTT()
{
	// Record start time
	auto start = std::chrono::high_resolution_clock::now();

	// GO THROUGH ALLLLLLLLLL THE COMBINATIONS... hopefully...



	// allocate 9 int memory blocks
	int* arr = (int*)malloc(9 * sizeof(int));
	if (!arr) {
		std::cout << "Memory Allocation Failed";
		exit(1);
	} for (int i = 0; i < 5; i++) {
		arr[i] = i * 2 + 1;
	}

	int arrPtr = 0;

	long combinations = 0;

	for (int a = 0; a < 9; a++)
	{
		Board board;
		board.MakeMove(a);
		arr[arrPtr] = a;
		arrPtr++;
		combinations++;
		for (int b = 0; b < 9; b++)
		{
			if (board.MakeMove(b)) {
				arr[arrPtr] = b;
				arrPtr++;
				combinations++;
			}
			else
			{
				continue;
			}
			for (int c = 0; c < 9; c++)
			{
				if (board.MakeMove(c)) {
					arr[arrPtr] = c;
					arrPtr++;
					combinations++;
				}
				else
				{
					continue;
				}
				for (int d = 0; d < 9; d++)
				{
					if (board.MakeMove(d)) {
						arr[arrPtr] = d;
						arrPtr++;
						combinations++;
					}
					else
					{
						continue;
					}
					for (int e = 0; e < 9; e++)
					{
						if (board.MakeMove(e)) {
							arr[arrPtr] = e;
							arrPtr++;
							combinations++;
						}
						else
						{
							continue;
						}
						for (int f = 0; f < 9; f++)
						{
							if (board.MakeMove(f)) {
								arr[arrPtr] = f;
								arrPtr++;
								combinations++;
							}
							else
							{
								continue;
							}
							for (int g = 0; g < 9; g++)
							{
								if (board.MakeMove(g)) {
									arr[arrPtr] = g;
									arrPtr++;
									combinations++;
								}
								else
								{
									continue;
								}
								for (int h = 0; h < 9; h++)
								{
									if (board.MakeMove(h)) {
										arr[arrPtr] = h;
										arrPtr++;
										combinations++;
									}
									else
									{
										continue;
									}
									for (int i = 0; i < 9; i++)
									{
										if (board.MakeMove(i)) {
											arr[arrPtr] = i;
											combinations++;
										}
										else
										{
											continue;
										}
										board.board[arr[arrPtr]] = 0;
										arrPtr--;
									}
									board.board[arr[arrPtr]] = 0;
									arrPtr--;
								}
								board.board[arr[arrPtr]] = 0;
								arrPtr--;
							}
							board.board[arr[arrPtr]] = 0;
							arrPtr--;
						}
						board.board[arr[arrPtr]] = 0;
						arrPtr--;
					}
					board.board[arr[arrPtr]] = 0;
					arrPtr--;
				}
				board.board[arr[arrPtr]] = 0;
				arrPtr--;
			}
			board.board[arr[arrPtr]] = 0;
			arrPtr--;
		}
		board.board[arr[arrPtr]] = 0;
		arrPtr--;
	}

	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	std::cout << "combinations " << combinations << "\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}