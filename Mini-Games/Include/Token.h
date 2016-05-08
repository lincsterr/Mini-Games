#pragma once // xyz if defines
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
class Token
{
public:
	friend ostream &operator<<(ostream &, const Token &);

	Token();
	Token(int, string);
	~Token();

	char getColor() const;
	void setColor(char);
	int getPlayerNum() const;
	void setPlayerNum(int);
private: 
	int playerNum;
	string Name;
	char Color;
};

