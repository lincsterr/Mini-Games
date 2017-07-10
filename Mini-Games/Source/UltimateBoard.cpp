#include "../Include/UltimateBoard.h"



UltimateBoard::UltimateBoard(int r, int c, int n)
	: Board(r, c, n)
{
	initializeBoard();
	initializeGame();
}

void UltimateBoard::initializeGame()
{
	TicTacToeGames.resize(3);
	for (size_t i = 0; i < 3; i++)
	{
		TicTacToeGames[i].resize(3);
	} // end for
}

void UltimateBoard::clearGame()
{
	for (size_t i = 0; i < 3; i++)
	{
		TicTacToeGames[i].resize(0);
	} // end for
	TicTacToeGames.resize(0);
	initializeGame();
}

bool UltimateBoard::addToken(int playerNumber, int rowNumber, int columnNumber)
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
ostream  &operator<<(ostream &output, UltimateBoard const &c)
{
	/* Print Game Title */
	const int width = 45;
	string line = "ULTIMATE-TIC-TAC-TOE";
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
	// Print Main 1 2 3 Header
	for (int a = 0; a < c.num_cols; a++) {
		if (a == 0) {
			output << "     ";
		}
		output << "      " << a + 1 << "       ";
	}
	output << endl;
/* Print x axis number for each board */
	// Left
	for (int a = 0; a < c.num_cols; a++) {
		if (a == 0) {
			output << "    ";
		}
		output << "   " << a + 1;
	}
	// Mid
	for (int a = 0; a < c.num_cols; a++) {
		if (a == 0) {
			output << "  ";
		}
		output << "   " << a + 1;
	}
	// Right
	for (int a = 0; a < c.num_cols; a++) {
		if (a == 0) {
			output << "  ";
		}
		output << "   " << a + 1;
	}
	output << endl;
	for (int v = 3; v > 0; v--)
	{
		for (int a = c.num_rows - 1; a >= 0; a--)
		{
			/* Print Top row of Board with slots for numbers */
				// Left
			output << "   ";
			for (int b = 0; b < c.num_cols; b++) {
				if (b == 0) {
					if (v != 3 && a == c.num_rows - 1) {
						output << "  " << char(194);
					}
					else {
						output << "  " << char(197);
					}
				}
				else {
					if (v != 3 && a == c.num_rows - 1) {
						output << char(194);
					}
					else {
						output << char(197);
					}
				}
				output << char(196) << char(196) << char(196);
			}
			if (v != 3 && a == c.num_rows - 1) {
				output << char(191);
			}
			else {
				output << char(180);
			}

			// Mid
			for (int b = 0; b < c.num_cols; b++) {
				if (b == 0) {
					if (v != 3 && a == c.num_rows - 1) {
						output << " " << char(218);
					}
					else {
						output << " " << char(195);
					}
				}
				else {
					if (v != 3 && a == c.num_rows - 1) {
						output << char(194);
					}
					else {
						output << char(197);
					}
				}
				output << char(196) << char(196) << char(196);
			}
			if (v != 3 && a == c.num_rows - 1) {
				output << char(191);
			}
			else {
				output << char(180);
			}

			// Right
			for (int b = 0; b < c.num_cols; b++) {
				if (b == 0) {
					if (v != 3 && a == c.num_rows - 1) {
						output << " " << char(218);
					}
					else {
						output << " " << char(195);
					}
				}
				else {
					if (v != 3 && a == c.num_rows - 1) {
						output << char(194);
					}
					else {
						output << char(197);
					}
				}
				output << char(196) << char(196) << char(196);
			}
			if (v != 3 && a == c.num_rows - 1) {
				output << char(191);
			}
			else {
				output << char(180);
			}

			output << endl;
			/* Print Row that includes y axis number and the token values */
				// Left
			for (int b = 0; b < c.num_cols; b++) {
				if (b == 0) {
					if (a == 1) {
						output << v;
						output << "  ";
					}
					else {
						output << "   ";
					}
					output << a + 1 << " " << char(179);
				}
				output << " " << c.TicTacToeGames[v-1][0].board.tokens[a][b] << " " << char(179);
				//output << " " << c.tokens[a][b] << " " << char(179);
			}

			// Mid
			for (int b = 0; b < c.num_cols; b++) {
				if (b == 0) {
					output << " " << char(179);
				}
				output << " " << c.TicTacToeGames[v-1][1].board.tokens[a][b] << " " << char(179);
				//output << " " << c.tokens[a][b] << " " << char(179);
			}

			// Right
			for (int b = 0; b < c.num_cols; b++) {
				if (b == 0) {
					output << " " << char(179);
				}
				output << " " << c.TicTacToeGames[v-1][2].board.tokens[a][b] << " " << char(179);
				//output << " " << c.tokens[a][b] << " " << char(179);
			}

			output << '\n';
		}

		/* Print Bottom Row of Board */

		// Left
		output << "   ";
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << "  " << char(193);
			}
			else {
				output << char(193);
			}
			output << char(196) << char(196) << char(196);
		}
		output << char(217);

		// Mid
		//output << " ";
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << " " << char(192);
			}
			else {
				output << char(193);
			}
			output << char(196) << char(196) << char(196);
		}
		output << char(217);

		// Right
		//output << " ";
		for (int b = 0; b < c.num_cols; b++) {
			if (b == 0) {
				output << " " << char(192);
			}
			else {
				output << char(193);
			}
			output << char(196) << char(196) << char(196);
		}
		output << char(217);
		output << "\n";
	}
	return output;
} // end function operator<<

UltimateBoard::~UltimateBoard()
{
}
