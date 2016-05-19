#include "../Include/ConnectFourBoard.h"


ConnectFourBoard::ConnectFourBoard()
	: Board(1,1)
{
	initializeBoard();
}

ConnectFourBoard::ConnectFourBoard(int r, int c)
	: Board(r,c)
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
				it->at(columnNumber).setColor(char(176));
			}
			else if (playerNumber == 2) {
				it->at(columnNumber).setPlayerNum(2);
				it->at(columnNumber).setColor(char(178));
			}
			break;
		}
	}
}

bool ConnectFourBoard::checkHorizontal(int playerNumber)
{
	int count;
	for (vector< vector<Token> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
		count = 0;
		for (size_t i = 0; i < 7; i++) {
			if (playerNumber == 1) {
				if (it->at(i).getPlayerNum() == 1) {
					count++;
				}
				else {
					count = 0;
				}
			}
			else if (playerNumber == 2) {
				if (it->at(i).getPlayerNum() == 2) {
					count++;
				}
				else {
					count = 0;
				}
			}
			if (count == 4) {
				return true;
			}
		}
	}
	if (count != 4) {
		return false;
	}
}

bool ConnectFourBoard::checkVertical(int playerNumber)
{
	int count;
	for (size_t i = 0; i < 7; i++) {
		count = 0;
		for (vector< vector<Token> >::iterator it = tokens.begin(); it != tokens.end(); ++it) {
			if (playerNumber == 1) {
				if (it->at(i).getPlayerNum() == 1) {
					count++;
				}
				else {
					count = 0;
				}
			}
			else if (playerNumber == 2) {
				if (it->at(i).getPlayerNum() == 2) {
					count++;
				}
				else {
					count = 0;
				}
			}
			if (count == 4) {
				return true;
			}
		}
	}
	if (count != 4) {
		return false;
	}
}

bool ConnectFourBoard::checkDiagonalLtoR(int playerNumber)
{
	for (size_t r = 0; r < 3; r++) {
		for (size_t c = 0; c < 4; c++) {
			if (iterateDiagonalLtoR(playerNumber, c, r)) {
				return true;
			}
		}
	}
	return false;
}

bool ConnectFourBoard::iterateDiagonalLtoR(int playerNumber, int column, int row)
{
	int r = row;
	for (size_t c = column; c < column + 4; c++) {
		if (tokens[r][c].getPlayerNum() == playerNumber) {
			r++;
		}
		else {
			return false;
		}
	}
		return true;
}

bool ConnectFourBoard::checkDiagonalRtoL(int playerNumber)
{
	for (size_t r = 0; r < 3; r++) {
		for (size_t c = 3; c < 7; c++) {
			if (iterateDiagonalRtoL(playerNumber, c, r)) {
				return true;
			}
		}
	}
	return false;
}

bool ConnectFourBoard::iterateDiagonalRtoL(int playerNumber, int column, int row)
{
	int r = row;
	for (int c = column; c >= column - 3; c--) {
		if (tokens[r][c].getPlayerNum() == playerNumber) { 
			r++;
		}
		else {
			return false;
		}
	}
		return true;
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

void ConnectFourBoard::initializeBoard()
{
	tokens.resize(num_rows);
	for (size_t i = 0; i < num_rows; i++)
	{
			tokens[i].resize(num_cols);
	} // end for
}

void ConnectFourBoard::clearBoard()
{
	for (size_t i = 0; i < num_rows; i++)
	{
		tokens[i].resize(0);
	} // end for
	tokens.resize(0);
	initializeBoard();
}