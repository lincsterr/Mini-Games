#include "..\Include\TicTacToeBoard.h"



TicTacToeBoard::TicTacToeBoard(int r, int c, int n)
	: Board(r, c, n)
{
	initializeBoard();
}

bool TicTacToeBoard::addToken(int playerNumber, int rowNumber, int columnNumber)
{
	if (tokens[rowNumber][columnNumber].getPlayerNum() == 0) {
		if (playerNumber == 1) {
			tokens[rowNumber][columnNumber].setPlayerNum(1);
			tokens[rowNumber][columnNumber].setColor(char(88));
		}
		else if (playerNumber == 2) {
			tokens[rowNumber][columnNumber].setPlayerNum(2);
			tokens[rowNumber][columnNumber].setColor(char(79));
		}
		return true;
	}
	else {
		return false;
	}
}

// function operator << definition
ostream  &operator<<(ostream &output, TicTacToeBoard const &c)
{
	/* Print Game Title */
	const int width = 15;
	string line = "TIC-TAC-TOE";
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
		if (a == 0) {
			output << "  ";
		}
		output << "   " << a + 1;
	}
	output << endl;
	for (int a = c.num_rows - 1; a >= 0; a--)
	{

		output << " ";
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << "  " << char(197);
			}
			else {
				output << char(197);
			}
			output << char(196) << char(196) << char(196);
		}
		output << char(180) << endl;
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << " " << a + 1 << " " << char(179);
			}
			output << " " << c.tokens[a][b] << " " << char(179);
		}
		output << '\n';
	}
	output << " ";
	for (int b = 0; b < c.num_cols; b++) {
		if (b == 0) {
			output << "  " << char(193);
		}
		else {
			output << char(193);
		}
		output << char(196) << char(196) << char(196);
	}
	output << char(217) << "\n";

	return output;
} // end function operator<<

TicTacToeBoard::~TicTacToeBoard()
{
}
