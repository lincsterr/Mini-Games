/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	
#include "../Include/ConnectFour.h"
#include "../Include/Player.h"


ConnectFour::ConnectFour()
	: board(6,7), Game()
{
}

ConnectFour::~ConnectFour()
{
	clearConsole();
}

void ConnectFour::play()
{
	initialize();
	char temp = 'y';
	while (temp == 'y') {
		board.clearBoard();
		players[0].resetNumTurns();
		players[1].resetNumTurns();
		clearConsole();
		for (size_t i = 0; i < (6 * 7)/2; i++) {
			cout << board;
			/* Player 1 */
			input(1);
			if (evaluate(1)) {
				cout << board;
				cout << players[0].getName() << " has won the game in " << players[0].getNumTurns() << " turns!" << endl;
				highscores.input(players[0].getName(), 0, players[0].getNumTurns());
				break;
			}
			cout << board;
			/* Player 2 */
			input(2);
			if (evaluate(2)) {
				cout << board;
				cout << players[1].getName() << " has won the game in " << players[1].getNumTurns() << " turns!" << endl;
				highscores.input(players[1].getName(), 0, players[1].getNumTurns());
				break;
			}
			if (i == ((6*7)/2 - 1)) {
				cout << "Tie! Nobody won!" << endl;
				break;
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
	while (cin.fail() || (columnNumber < 1) || (columnNumber > 7) || (board.columnFilled(columnNumber-1))) {
		if (!cin.fail()) {
			if ((columnNumber < 1) || (columnNumber > 7)) {
				cout << "\nIncorrect input, please try again (1-7): ";
			}
			else {
				cout << "\nColumn filled, please try again: ";
			}
		}
		else {
			cout << "\nIncorrect input, please try again (1-7): ";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> columnNumber;
	}
	clearConsole();
	board.addToken(playerNumber, columnNumber-1);
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
	const int width = 42;
	string line = "C O N N E C T  F O U R";
	string line1 = "H I G H S C O R E S ";
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
	cout << char(179);
	for (int i = 0; i < (width - line1.length()) / 2; i++) {
		cout << ' ';
	}
	cout << line1;
	if (line1.length() % 2 == 0) {
		for (int i = 0; i < (width - line1.length()) / 2; i++) {
			cout << ' ';
		}
	}
	else {
		for (int i = 0; i < (width - line1.length()) / 2; i++) {
			cout << ' ';
		}
	}
	cout << char(179) << endl;
	cout << char(192);
	for (size_t j = 0; j < width; j++) {
		cout << char(196);
	}
	cout << char(217) << endl;
	/* Print all Highscores */
	highscores.display_all(0);
	/* Delete names if already there */
	if (players.size() > 0) {
		players.erase(players.begin(), players.begin() + players.size());
	}
	/* Input Names */
	cout << "\nPlayer 1 please input your name: ";
	getline(cin,name);
	players.push_back(Player(1, name));
	cout << "Player 2 please input your name: ";
	getline(cin, name);
	players.push_back(Player(2, name));
}
