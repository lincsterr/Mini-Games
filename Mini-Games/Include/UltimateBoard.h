#pragma once
#include "Board.h"
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

	bool addToken(int, int, int);
};

