/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#include "../Include/Board.h"


Board::Board(int r, int c, int n)
	: num_rows(r), num_cols(c), numToWin(n)
{

}

void Board::initializeBoard()
{
	tokens.resize(num_rows);
	for (size_t i = 0; i < num_rows; i++)
	{
		tokens[i].resize(num_cols);
	} // end for
}

void Board::clearBoard()
{
	for (size_t i = 0; i < num_rows; i++)
	{
		tokens[i].resize(0);
	} // end for
	tokens.resize(0);
	initializeBoard();
}

bool Board::checkHorizontal(int playerNumber)
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
			if (count == numToWin) {
				return true;
			}
		}
	}
	if (count != numToWin) {
		return false;
	}
}

bool Board::checkVertical(int playerNumber)
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
			if (count == numToWin) {
				return true;
			}
		}
	}
	if (count != numToWin) {
		return false;
	}
}

Board::~Board()
{
}
