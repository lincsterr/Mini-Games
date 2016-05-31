/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
#pragma once
#include "Board.h"
#include "Token.h"
#include "Player.h"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class ConnectFourBoard :
	public Board
{
public:
	friend ostream &operator<<(ostream &, ConnectFourBoard const &);

	ConnectFourBoard(int, int, int);
	~ConnectFourBoard();

	void addToken(int, int);
	bool columnFilled(int);
};

