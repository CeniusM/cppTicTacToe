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

	// Record start time
	auto start = std::chrono::high_resolution_clock::now();

	// GO THROUGH ALLLLLLLLLL THE COMBINATIONS... hopefully...
	for (int i = 0; i < 1000000; i++) // 1m
	{
		Board board;
		while (true)
		{
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

	int foo = 0;
	int combinations = 0;
	for (int i = 0; i < 1000000; i++) // 1m
	{
		Board board;
		combinations = 0;
		while (true)
		{
			foo = rand() % 9;
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
	unsigned long long value = 0;
	int reps = 10;

	for (int i = 0; i < reps; i++)
	{
		long long t1 = Time1();
		long long t2 = Time2();
		value += t1 - t2;
	}
	value /= reps;

	std::cout << value << " milliseconds" << std::endl;

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