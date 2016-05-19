#pragma once
#include "HighScores.h"
class Game
{
public:
	Game();
	virtual ~Game();

	virtual void play();
protected: 
	HighScores highscores;
};

