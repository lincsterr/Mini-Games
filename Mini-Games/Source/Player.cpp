/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
#include "../Include/Player.h"


Player::Player()
	:playerNum(0), name("No Name"), numTurns(0)
{

}

Player::Player(int pNum, string n)
	: playerNum(pNum), name(n), numTurns(0)
{

}

Player::~Player()
{
	
}

int Player::getNumTurns() const
{
	return numTurns;
}

void Player::incNumTurns()
{
	numTurns++;
}

void Player::resetNumTurns()
{
	numTurns = 0;
}

int Player::getPlayerNum() const
{
	return playerNum;
}

void Player::setPlayerNum(int pNum)
{
	playerNum = pNum;
}

string Player::getName() const
{
	return name;
}