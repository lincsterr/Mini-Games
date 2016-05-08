#pragma once

#include <random> // contains C++11 random number generation features
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#include "ConnectFourBoard.h"

class ConnectFour
{
public:
	ConnectFour();
	~ConnectFour();

	void play();
	int evaluate(int);

	void input(int);
	void initialize();
private:
	ConnectFourBoard board;
	vector <Player> players;
};

