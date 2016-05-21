/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
#include "../Include/Token.h"


Token::Token()
	: playerNum(0), Name("Log"), Color(char(0))
{

}

Token::Token(int pNum, string n)
	: playerNum(pNum), Name(n)
{
	if (playerNum == 1) {
		Color = char(176);
	}
	else if (playerNum == 2) {
		Color = char(178);
	}
	else {
		Color = char(233); //xyz
	}
}

char Token::getColor() const 
{
	return Color;
}

void Token::setColor(char ID)
{
	Color = ID;
}

int Token::getPlayerNum() const
{
	return playerNum;
}

void Token::setPlayerNum(int pNum)
{
	playerNum = pNum;
}

// function operator<< definition
ostream  &operator<<(ostream &output, const Token &c)
{
	output << c.Color;
	return output;
} // end function operator<<

Token::~Token()
{

}
