/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
#pragma once
#include "HighScores.h"
#include "ConnectFourBoard.h"
#include "Player.h"
#include <vector>
class Game
{
public:
	Game();
	virtual ~Game();

	void clearConsole();
	virtual void play();
protected: 
	HighScores highscores;
	vector <Player> players;
};

