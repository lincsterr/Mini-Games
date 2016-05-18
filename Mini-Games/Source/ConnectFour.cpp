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
		clearConsole();
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
	bool DONE = 0;
	cout << players[playerNumber - 1].getName() << " it is your turn! Please select a column: ";
	cin >> columnNumber;
	while (cin.fail() || (columnNumber < 0) || (columnNumber > 6)) {
		cout << "\nIncorrect input, please try again (0-6): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> columnNumber;
	}
	clearConsole();
	board.addToken(playerNumber, columnNumber);
	players[playerNumber - 1].incNumTurns();
}

int ConnectFour::evaluate(int playerNum)
{
	if (board.checkHorizontal(playerNum) == playerNum) {
		return playerNum;
	}
	else if (board.checkVertical(playerNum) == playerNum) {
		return playerNum;
	}
	else if (board.checkDiagonalLtoR(playerNum) == playerNum) {
		return playerNum;
	}
	else if (board.checkDiagonalRtoL(playerNum) == playerNum) {
		return playerNum;
	}
	else {
		return -1;
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
