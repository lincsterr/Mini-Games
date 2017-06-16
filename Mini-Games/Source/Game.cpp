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

void Game::clearConsole()
{
	// cout << "\033[2J\033[1;1H";
	system("cls");
}

void Game::play()
{
	cout << "Let's play a game!" << endl;
}
