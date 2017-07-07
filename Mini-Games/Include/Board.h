/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include "Token.h"
using namespace std;

class Board
{
public:
	Board(int, int, int);

	void initializeBoard();
	void clearBoard();
	bool checkHorizontal(int);
	bool checkVertical(int);
	bool checkDiagonalLtoR(int);
	bool iterateDiagonalLtoR(int, int, int);
	bool checkDiagonalRtoL(int);
	bool iterateDiagonalRtoL(int, int, int);
	virtual ~Board();

protected: 
	int num_rows = 1;
	int num_cols = 1;
	int numToWin;
	vector <vector <Token> > tokens;
};

