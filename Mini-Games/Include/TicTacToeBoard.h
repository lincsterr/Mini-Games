#pragma once
#include "Board.h"
#include "Token.h"
#include "Player.h"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
class TicTacToeBoard :
	public Board
{
public:
	friend ostream &operator<<(ostream &, TicTacToeBoard const &);

	TicTacToeBoard();
	//TicTacToeBoard(const TicTacToeBoard&) = default;
	//TicTacToeBoard& operator=(const TicTacToeBoard&) = default;
	~TicTacToeBoard();
	bool addToken(int, int, int);
	//bool spotFilled(int);
};

