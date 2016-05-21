/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Board
{
public:
	Board();
	Board(int, int);
	virtual ~Board();

protected: 
	int num_rows = 1;
	int num_cols = 1;
};

