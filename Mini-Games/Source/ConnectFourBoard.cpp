/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#include "../Include/ConnectFourBoard.h"

ConnectFourBoard::ConnectFourBoard(int r, int c, int n)
	: Board(r,c,n)
{
	initializeBoard();
}

ConnectFourBoard::~ConnectFourBoard()
{

}

void ConnectFourBoard::addToken(int playerNumber, int columnNumber)
{
	for (vector< vector<Token> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
		if (it->at(columnNumber).getPlayerNum() == 0) {
			if (playerNumber == 1) {
				it->at(columnNumber).setPlayerNum(1);
				it->at(columnNumber).setColor(char(177));
			}
			else if (playerNumber == 2) {
				it->at(columnNumber).setPlayerNum(2);
				it->at(columnNumber).setColor(char(178));
			}
			break;
		}
	}
}

bool ConnectFourBoard::columnFilled(int column)
{
	if (tokens[5][column].getPlayerNum() > 0) {
		return true;
	}
	else {
		return false;
	}
}

// function operator << definition
ostream  &operator<<(ostream &output, ConnectFourBoard const &c)
{
	/* Print Game Title */
	const int width = 27;
	string line = "C O N N E C T  F O U R";
	output << ' ' << char(218);
	for (size_t j = 0; j < width; j++) {
		output << char(196);
	}
	output << char(191) << endl;
	output << ' ' << char(179);
	for (int i = 0; i < (width - line.length()) / 2; i++) {
		output << ' ';
	}
	output << line;
	if (line.length() % 2 == 0) {
		for (int i = 0; i <= (width - line.length()) / 2; i++) {
			output << ' ';
		}
	}
	else {
		for (int i = 0; i < (width - line.length()) / 2; i++) {
			output << ' ';
		}
	}
	output << char(179) << endl;
	output << ' ' << char(192);
	for (size_t j = 0; j < width; j++) {
		output << char(196);
	}
	output << char(217) << endl;

	/* Print Board */
	for (int a = 0; a < c.num_cols; a++) {
		output << "   " << a+1;
	}
	output << endl;
	for (int a = c.num_rows-1; a >= 0; a--)
	{
		
		output << " ";
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << char(195);
			}
			else {
				output << char(197);
			}
			output << char(196) << char(196) << char(196);
		}
		output << char(180) << endl; 
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << " " << char(179);
			}
			output << " " << c.tokens[a][b] << " " << char(179);
		}
		output << '\n';
	}
	output << " ";
	for (int b = 0; b < c.num_cols; b++) {
		if (b == 0) {
			output << char(192);
		}
		else {
			output << char(193);
		}
		output << char(196) << char(196) << char(196);
	}
	output << char(217) << "\n";

	return output;
} // end function operator<<