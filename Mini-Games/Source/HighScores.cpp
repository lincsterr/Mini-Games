#include "../Include/HighScores.h"
/* Code highly influenced from Sildomar T. Monteiro */


HighScores::HighScores(const char *filename)
{
	highscoreFile.open(filename, ios::in | ios::out | ios::binary);

	if (!highscoreFile) {

		cout << "Creating file: " << filename << endl;
		highscoreFile.open(filename, ios::out);
		highscoreFile.close();
		highscoreFile.open(filename, ios::in | ios::out | ios::binary);

		if (highscoreFile) {
			highscores.idnum = 0;
			highscores.gameID = 0;
			highscores.name[0] = '\0';
			highscores.numTurns = 0;
			for (int i = 0; i<100; ++i)
				highscoreFile.write(reinterpret_cast<char *> (&highscores),
					sizeof(highscores));
		}
		else {
			cerr << "File could not be created." << endl;
			exit(1);
		}
	}
}


HighScores::~HighScores()
{
	highscoreFile.close();
}

int HighScores::search_open_index()
{
	for (int num = 1; num < 100; num++) {
		highscoreFile.seekg((num - 1) * sizeof(highscores));
		highscoreFile.read(reinterpret_cast<char *> (&highscores), sizeof(highscores));
		if (num != highscores.idnum) {
			return num;
		}
	}
	cout << "Highscore file full" << endl;
	return 0;
}

int HighScores::search_by_name(string name, int gID)
{
	char tmp[30];
	if (name.length() < 30) {
		for (int i = 0; i < name.length(); i++) {
			tmp[i] = name[i];
		}
		tmp[name.length()] = '\0';
	}
	else
	{
		for (int i = 0; i < 29; i++) {
			tmp[i] = name[i];
		}
		tmp[29] = '\0';
	}
	for (int num = 1; num < 100; num++) {
		highscoreFile.seekg((num - 1) * sizeof(highscores));
		highscoreFile.read(reinterpret_cast<char *> (&highscores), sizeof(highscores));
		if ((strcmp(tmp,highscores.name) == 0) && (gID == highscores.gameID)) {
			return highscores.numTurns;
		}
	}
	cout << "Name not found in file (NO HIGHSCORE)" << endl;
	return 0;
}

// function to read the input data from the user
bool HighScores::input(string name, int gID, int nTurns)
{
	highscores.idnum = search_open_index();
	if (name.length() < 30) {
		for (int i = 0; i < name.length(); i++) {
			highscores.name[i] = name[i];
		}
		highscores.name[name.length()] = '\0';
	}
	else
	{
		for (int i = 0; i < 29; i++) {
			highscores.name[i] = name[i];
		}
		highscores.name[29] = '\0';
	}
	highscores.gameID = gID;
	highscores.numTurns = nTurns;
	write_file();
	return true;
}

// function to write data taken from the user into the file
void HighScores::write_file()
{
	highscoreFile.seekp((highscores.idnum - 1) * sizeof(highscores));
	highscoreFile.write(reinterpret_cast<char *> (&highscores), sizeof(highscores));
}

//function to read data from the file
bool HighScores::read_file(int num)
{
	highscoreFile.seekg((num - 1) * sizeof(highscores));
	highscoreFile.read(reinterpret_cast<char *> (&highscores), sizeof(highscores));
	if (num != highscores.idnum) {
		cout << "Record does not exists" << endl;
		return false;
	}
	else {
		display_data();
		return true;
	}
}

void HighScores::display_all(int gID)
{
	cout << left
		<< setw(30) << "Name"
		<< setw(7) << "# Turns" << endl;
	for (int num = 1; num < 100; num++) {
		highscoreFile.seekg((num - 1) * sizeof(highscores));
		highscoreFile.read(reinterpret_cast<char *> (&highscores), sizeof(highscores));
		if (num != highscores.idnum) {
			break;
		}
		else if (gID == highscores.gameID){
			cout << left
				<< setw(30) << highscores.name
				<< setw(7)
				<< highscores.numTurns << endl;
		}
	}
}

// function to display results to the screen
void HighScores::display_data()
{
	cout << left << setw(6) << "ID"
		<< setw(6) << "gID"
		<< setw(30) << "Name"
		<< setw(7) << "# Turns" << endl;
	cout << left << setw(6) << highscores.idnum
		<< setw(6) << highscores.gameID
		<< setw(30) << highscores.name
		<< setw(7)
		<< highscores.numTurns << endl;
}