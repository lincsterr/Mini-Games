#pragma once
#include "TicTacToeBoard.h"
#include "Game.h"
#include <random> // contains C++11 random number generation features
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include "HighScores.h"
class TicTacToeGame :
	public Game
{
public:
	TicTacToeGame();
	TicTacToeGame(const TicTacToeGame&);
	//TicTacToeGame(const TicTacToeGame&) = default;
	//TicTacToeGame& operator=(const TicTacToeGame&) = default;
	~TicTacToeGame();
	void play();
	void input(int);
	bool evaluate(int);
	void initialize();
//private: 
	TicTacToeBoard board;
};

