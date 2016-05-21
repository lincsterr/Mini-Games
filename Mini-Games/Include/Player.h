/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#pragma once
#include <string>
using namespace std;
class Player
{
public:
	Player();
	Player(int, string);
	~Player();

	int getNumTurns() const;
	void incNumTurns();
	void resetNumTurns();
	string getName() const;
	int getPlayerNum() const;
	void setPlayerNum(int);
private:
	int playerNum;
	string name;
	int numTurns;
};

