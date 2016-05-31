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

	TicTacToeBoard(int,int,int);
	~TicTacToeBoard();
	bool addToken(int, int, int);
	//bool spotFilled(int);
};

