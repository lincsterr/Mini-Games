#pragma once
#include "UltimateBoard.h"
#include "TicTacToeGame.h"
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

class UltimateGame :
	public Game
{
public:
	UltimateGame();
	//UltimateGame(const UltimateGame&) = default;
	//UltimateGame& operator=(const UltimateGame&) = default;
	~UltimateGame();

	//void initializeGame();
	//void clearGame();
	void play();
	void input(int);
	bool evaluate(int);
	void initialize();
private:
	UltimateBoard board;
	/*vector <vector <TicTacToeGame> > TicTacToeGames;*/
};

