/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#pragma once

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
using namespace std;
#include "ConnectFourBoard.h"
#include "HighScores.h"
class ConnectFourGame : public Game
{
public:
	ConnectFourGame();
	~ConnectFourGame();

	void play();
	bool evaluate(int);

	void input(int);
	void clearConsole();
	void initialize();
private:
	ConnectFourBoard board;
	vector <Player> players;
};

