/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */	

#include "Include/ConnectFourGame.h"
#include "Include/TicTacToeGame.h"
#include "Include/UltimateGame.h"

void printMenu();

int main()
{
	int gameNumber;
	char temp = 'y';
	vector < Game * > games(3);
	ConnectFourGame connectFourGame;
	TicTacToeGame ticTacToeGame;
	UltimateGame ultimateGame;
	// initialize vector with Games
	games[0] = &connectFourGame;
	games[1] = &ticTacToeGame;
	games[2] = &ultimateGame;
	while (temp == 'y') {
		printMenu();
		cin >> gameNumber;
		while (cin.fail() || ((gameNumber < 0) && (gameNumber > 3))) {
			cout << "\nIncorrect input, please try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> gameNumber;
		}
		cin.ignore();
		if (gameNumber != 0) {
			games[gameNumber-1]->play();
		}
		else {
			break;
		}
	}
	return 0;
}

	void printMenu()
	{
		// display available options
		const int width = 30;
		const int height = 0;
		vector <string> strings;
		/* Clear Console */
		// cout << "\033[2J\033[1;1H";
		system("cls");
		/* All Strings to be printed in Menu */
		strings.push_back("Welcome to Mini-Games Land");
		strings.push_back("Main Menu");
		strings.push_back("");
		strings.push_back("Game Choices:");
		strings.push_back("");
		strings.push_back("Connect Four: Select 1");
		strings.push_back("");
		strings.push_back("Tic-Tac-Toe: Select 2");
		strings.push_back("");
		strings.push_back("Ultimate Tic-Tac-Toe: Select 3");
		strings.push_back("[Coming Soon]");
		strings.push_back("");
		strings.push_back("Exit: Select 0");
		/* Create Menu */
		cout << char(218);
		for (size_t j = 0; j < width; j++) {
			cout << char(196);
		}
		cout << char(191) << endl;
		for (const string &line : strings) {
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
				for (int i = 0; i <= (width - line.length()) / 2; i++) {
					cout << ' ';
				}
			}
			cout << char(179) << endl;
		}
		for (size_t i = 0; i < height; i++) {
			cout << char(179);
			for (size_t j = 0; j < width; j++) {
				cout << ' ';
			}
			cout << char(179) << endl;
		}
		cout << char(192);
		for (size_t j = 0; j < width; j++) {
			cout << char(196);
		}
		cout << char(217) << endl;
	} 