/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
#include "../Include/Game.h"
#include <iostream>
#include <cstdio>
using namespace std;

Game::Game()
	:highscores("highscores.dat")
{
}


Game::~Game()
{
}

void Game::play()
{
	cout << "Let's play a game!" << endl;
}
