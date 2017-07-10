#pragma once
#include "Board.h"
#include "TicTacToeGame.h"
#include "Token.h"
#include "Player.h"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
class UltimateBoard :
	public Board
{
public:
	friend ostream &operator<<(ostream &, UltimateBoard const &);

	UltimateBoard(int, int, int);
	~UltimateBoard();

	void initializeGame();
	void clearGame();

	bool addToken(int, int, int);
//private:
	vector <vector <TicTacToeGame> > TicTacToeGames;
};

