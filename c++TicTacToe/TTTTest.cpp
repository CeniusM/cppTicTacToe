#include "Board.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>  // for high_resolution_clock
#include <thread>

void TestTTTWER() // beutifull code <3
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
	for (int reps = 0; reps < 100; reps++)
	{
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
												arrPtr++;
												combinations++;
											}
											else
											{
												continue;
											}
											arrPtr--;
											board.board[arr[arrPtr]] = 0;
											board.turn--;
											board.player ^= 0b11;
											board.isGameOver = false;
										}
										arrPtr--;
										board.board[arr[arrPtr]] = 0;
										board.turn--;
										board.player ^= 0b11;
										board.isGameOver = false;
									}
									arrPtr--;
									board.board[arr[arrPtr]] = 0;
									board.turn--;
									board.player ^= 0b11;
									board.isGameOver = false;
								}
								arrPtr--;
								board.board[arr[arrPtr]] = 0;
								board.turn--;
								board.player ^= 0b11;
								board.isGameOver = false;
							}
							arrPtr--;
							board.board[arr[arrPtr]] = 0;
							board.turn--;
							board.player ^= 0b11;
							board.isGameOver = false;
						}
						arrPtr--;
						board.board[arr[arrPtr]] = 0;
						board.turn--;
						board.player ^= 0b11;
						board.isGameOver = false;
					}
					arrPtr--;
					board.board[arr[arrPtr]] = 0;
					board.turn--;
					board.player ^= 0b11;
					board.isGameOver = false;
				}
				arrPtr--;
				board.board[arr[arrPtr]] = 0;
				board.turn--;
				board.player ^= 0b11;
				board.isGameOver = false;
			}
			arrPtr--;
			board.board[arr[arrPtr]] = 0;
			board.turn--;
			board.player ^= 0b11;
			board.isGameOver = false;
		}
		for (int i = 0; i < 5; i++) {
			arr[i] = i * 2 + 1;
		}arrPtr = 0;
	}

	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	std::cout << "combinations " << combinations << "\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(1000000000));
}

void TestTTT()
{
	// allocate 9 int memory blocks
	int* arr = (int*)malloc(9 * sizeof(int));
	if (!arr) {
		std::cout << "Memory Allocation Failed";
		exit(1);
	} for (int i = 0; i < 5; i++) {
		arr[i] = i * 2 + 1;
	}


	// allocate combinationArrSize int memory blocks
	int combinationArrSize = 100000;
	byte* combinationArr = (byte*)malloc(combinationArrSize * sizeof(byte));
	if (!combinationArr) {
		std::cout << "Memory Allocation Failed";
		exit(1);
	} for (int i = 0; i < combinationArrSize; i++) {
		combinationArr[i] = rand() % 9;
	}

	int arrPtr = 0;

	long combinations = 0;

	// Record start time
	auto start = std::chrono::high_resolution_clock::now();
	
	for (int reps = 0; reps < 100; reps++)
	{
		Board board;
		for (int i = 0; i < combinationArrSize; i++)
		{
			if (board.MakeMove(combinationArr[i]))
			{
				arr[arrPtr] = combinationArr[i];
				arrPtr++;
				combinations++;
			}
			else
			{
				arrPtr--;
				board.board[arr[arrPtr]] = 0;
				board.turn--;
				board.player ^= 0b11;
				board.isGameOver = false;
			}
		}
	}

	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	std::cout << "combinations " << combinations << "\n";

	std::this_thread::sleep_for(std::chrono::milliseconds(10000000));

	free(arr);
	free(combinationArr);
}