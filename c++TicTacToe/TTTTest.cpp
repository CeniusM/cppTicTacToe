#include "Board.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>  // for high_resolution_clock
#include <thread>
#include <stdio.h>
#include <stdlib.h>

long long Time1()
{
	srand(472364878);
	long long combinations = 0;

	// Record start time
	auto start = std::chrono::high_resolution_clock::now();

	// GO THROUGH ALLLLLLLLLL THE COMBINATIONS... hopefully...
	for (int i = 0; i < 1000000; i++) // 1m
	{
		Board board;
		while (true)
		{
			combinations++;
			board.MakeMove(rand() % 9);
			if (board.isGameOver)
				break;
		}
	}

	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	return elapsed.count();
}

long long Time2()
{
	srand(472364878);

	// Record start time
	auto start = std::chrono::high_resolution_clock::now();

	// GO THROUGH ALLLLLLLLLL THE COMBINATIONS... hopefully...

	int combinations = 0;
	for (int i = 0; i < 1000000; i++) // 1m
	{
		combinations = 0;
		while (true)
		{
			rand() % 9;
			combinations++;
			if (combinations > 15)
				break;
		}
	}

	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	return elapsed.count();
}

void TestTTTWER() // beutifull code <3
{
	long long t1 = Time1();
	long long t2 = Time2();
	std::cout << t1 - t2 << " milliseconds" << std::endl;

	std::cin.get();
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

/*
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

	timer*





	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	std::cout << "combinations " << combinations << "\n";
	*/