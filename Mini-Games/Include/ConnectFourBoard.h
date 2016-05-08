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
	int checkHorizontal(int);
	int checkVertical(int);
	int checkDiagonalLtoR(int);
	bool iterateDiagonalLtoR(int, int, int);
	int checkDiagonalRtoL(int);
	bool iterateDiagonalRtoL(int, int, int);
	void initializeBoard();
	void clearBoard();
private:
	int num_rows = 1;
	int num_cols = 1;
	vector <vector <Token> > tokens;
};

