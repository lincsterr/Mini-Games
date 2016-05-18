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
	clearConsole();
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
			if (evaluate(1)) {
				cout << board;
				cout << players[0].getName() << " has won the game in " << players[0].getNumTurns() << " turns!" << endl;
				break;
			}
			cout << board;
			/* Player 2 */
			input(2);
			if (evaluate(2)) {
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
		while (cin.fail() || ((temp != 'y') && (temp != 'n'))) {
			cout << "\nIncorrect input, please try again (y/n): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> temp;
		}
	}
}

void ConnectFour::input(int playerNumber)
{
	int columnNumber;
	bool DONE = 0;
	cout << players[playerNumber - 1].getName() << " it is your turn! Please select a column: ";
	cin >> columnNumber;
	while (cin.fail() || (columnNumber < 0) || (columnNumber > 6) || (board.columnFilled(columnNumber))) {
		if (!cin.fail()) {
			if ((columnNumber < 0) || (columnNumber > 6)) {
				cout << "\nIncorrect input, please try again (0-6): ";
			}
			else {
				cout << "\nColumn filled, please try again: ";
			}
		}
		else {
			cout << "\nIncorrect input, please try again (0-6): ";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> columnNumber;
	}
	clearConsole();
	board.addToken(playerNumber, columnNumber);
	players[playerNumber - 1].incNumTurns();
}

bool ConnectFour::evaluate(int playerNum)
{
	if (board.checkHorizontal(playerNum)) {
		return true;
	}
	else if (board.checkVertical(playerNum)) {
		return true;
	}
	else if (board.checkDiagonalLtoR(playerNum)) {
		return true;
	}
	else if (board.checkDiagonalRtoL(playerNum)) {
		return true;
	}
	else {
		return false;
	}
}

void ConnectFour::clearConsole()
{
	cout << "\033[2J\033[1;1H";
}

void ConnectFour::initialize()
{
	string name;
	clearConsole();
	/* Print Title */
	const int width = 30;
	string line = "C O N N E C T  F O U R";
	cout << char(218);
	for (size_t j = 0; j < width; j++) {
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << char(179);
	for (int i = 0; i < (width - line.length()) / 2; i++) {
		cout << ' ';
	}
	cout << line;
	if (line.length() % 2 == 0) {
		for (int i = 0; i < (width - line.length()) / 2; i++) {
			cout << ' ';
		}
	}
	else {
		for (int i = 0; i < (width - line.length()) / 2; i++) {
			cout << ' ';
		}
	}
	cout << char(179) << endl;
	cout << char(192);
	for (size_t j = 0; j < width; j++) {
		cout << char(196);
	}
	cout << char(217) << endl;
	/* Input Names */
	cout << "Player 1 please input your name: ";
	getline(cin,name);
	players.push_back(Player(1, name));
	cout << "Player 2 please input your name: ";
	getline(cin, name);
	players.push_back(Player(2, name));
}
