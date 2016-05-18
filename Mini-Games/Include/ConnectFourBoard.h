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

	ConnectFourBoard();
	ConnectFourBoard(int, int);
	~ConnectFourBoard();

	void addToken(int, int);
	bool checkHorizontal(int);
	bool checkVertical(int);
	bool checkDiagonalLtoR(int);
	bool iterateDiagonalLtoR(int, int, int);
	bool checkDiagonalRtoL(int);
	bool iterateDiagonalRtoL(int, int, int);
	bool columnFilled(int);
	void initializeBoard();
	void clearBoard();
private:
	int num_rows = 1;
	int num_cols = 1;
	vector <vector <Token> > tokens;
};

