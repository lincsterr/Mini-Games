#include "..\Include\TicTacToeGame.h"


TicTacToeGame::TicTacToeGame()
	:board(), Game()
{
}

TicTacToeGame::TicTacToeGame(const TicTacToeGame&obj)
{
	this->board = obj.board;
}

void TicTacToeGame::play()
{
	initialize();
	char temp = 'y';
	while (temp == 'y') {
		board.clearBoard();
		players[0].resetNumTurns();
		players[1].resetNumTurns();
		clearConsole();
		for (size_t i = 0; i < (3 * 3) / 2; i++) {
			cout << board;
			/* Player 1 */
			input(1);
			if (evaluate(1)) {
				cout << board;
				cout << players[0].getName() << " has won the game in " << players[0].getNumTurns() << " turns!" << endl;
				highscores.input(players[0].getName(), 1, players[0].getNumTurns());
				break;
			}
			cout << board;
			/* Player 2 */
			input(2);
			if (evaluate(2)) {
				cout << board;
				cout << players[1].getName() << " has won the game in " << players[1].getNumTurns() << " turns!" << endl;
				highscores.input(players[1].getName(), 1, players[1].getNumTurns());
				break;
			}
			if (i == ((3 * 3) / 2 - 1)) {
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

bool TicTacToeGame::evaluate(int playerNum)
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

void TicTacToeGame::input(int playerNumber)
{
	int columnNumber;
	int rowNumber;
	cout << players[playerNumber - 1].getName() << " it is your turn! Please select a location - \"x y\": ";
	cin >> columnNumber;
	cin >> rowNumber;
	while (cin.fail() || (columnNumber < 1) || (columnNumber > 3) || (rowNumber < 1) || (rowNumber > 3) || !board.addToken(playerNumber, rowNumber - 1, columnNumber - 1)) {
		if (!cin.fail()) {
			if ((columnNumber < 1) || (columnNumber > 3) || (rowNumber < 1) || (rowNumber > 3)) {
				cout << "\nIncorrect input, please try again (1-3): ";
			}
			else {
				cout << "\nSpot filled, please try again: ";
			}
		}
		else {
			cout << "\nIncorrect input, please try again (1-3): ";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> columnNumber;
		cin >> rowNumber;
	}
	clearConsole();
	players[playerNumber - 1].incNumTurns();
}

void TicTacToeGame::initialize()
{
	string name;
	clearConsole();
	/* Print Title */
	const int width = 42;
	string line = "T I C - T A C - T O E ";
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
	highscores.display_all(1);
	/* Delete names if already there */
	if (players.size() > 0) {
		players.erase(players.begin(), players.begin() + players.size());
	}
	/* Input Names */
	cout << "\nPlayer 1 please input your name: ";
	getline(cin, name);
	players.push_back(Player(1, name));
	cout << "Player 2 please input your name: ";
	getline(cin, name);
	players.push_back(Player(2, name));
}

TicTacToeGame::~TicTacToeGame()
{
	//clearConsole();
}
