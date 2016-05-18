#include "../Include/ConnectFour.h"
#include "../Include/Player.h"


ConnectFour::ConnectFour()
	: board(6,7)
{
	initialize();
	play();
}

ConnectFour::~ConnectFour()
{
}

void ConnectFour::play()
{
	char temp = 'y';
	while (temp == 'y') {
		board.clearBoard();
		players[0].resetNumTurns();
		players[1].resetNumTurns();
		for (size_t i = 0; i < 6 * 7; i++) {
			cout << board;
			/* Player 1 */
			input(1);
			if (evaluate(1) == 1) {
				cout << board;
				cout << players[0].getName() << " has won the game in " << players[0].getNumTurns() << " turns!" << endl;
				break;
			}
			cout << board;
			/* Player 2 */
			input(2);
			if (evaluate(2) == 2) {
				cout << board;
				cout << players[1].getName() << " has won the game in " << players[1].getNumTurns() << " turns!" << endl;
				break;
			}
			if (i == 41) {
				cout << "Tie! Nobody won!" << endl;
			}
		}
		cout << "Would you like to play again? (y/n): " << endl;
		cin >> temp;
	}
}

void ConnectFour::input(int playerNumber)
{
	int columnNumber;
	cout << players[playerNumber - 1].getName() << " it is your turn! Please select a column: ";
	cin >> columnNumber; // xyz check for integer only input from 0 - 6
	clearConsole();
	board.addToken(playerNumber, columnNumber);
	players[playerNumber - 1].incNumTurns();
}

int ConnectFour::evaluate(int playerNum)
{
	if (board.checkHorizontal(playerNum) > 0) {
		return board.checkHorizontal(playerNum);
	}
	else if (board.checkVertical(playerNum) > 0) {
		return board.checkVertical(playerNum);
	}
	else if (board.checkDiagonalLtoR(playerNum) > 0) {
		return board.checkDiagonalLtoR(playerNum);
	}
	else if (board.checkDiagonalRtoL(playerNum) > 0) {
		return board.checkDiagonalRtoL(playerNum);
	}
	else {
		return 0;
	}
}

void ConnectFour::clearConsole()
{
	cout << "\033[2J\033[1;1H";
}

void ConnectFour::initialize()
{
	string name;
	cout << "Player 1 please input your name: ";
	getline(cin,name);
	players.push_back(Player(1, name));
	cout << "Player 2 please input your name: ";
	getline(cin, name);
	players.push_back(Player(2, name));
}
