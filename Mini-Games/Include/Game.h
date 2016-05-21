/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
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

