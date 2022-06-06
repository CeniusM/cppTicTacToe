#pragma once

class TTTPlayer
{
public:

	int GetMove(int board[9]);

	TTTPlayer();
	~TTTPlayer();

private:
	int finalMove{};


	void StartSearch();
	void SearchMove();

};
