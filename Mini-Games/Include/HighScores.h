/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#pragma once

#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//structure of HighScores
struct highscoreRecord {
	int idnum;
	int gameID;
	char name[30];
	int numTurns;

	bool operator<(const highscoreRecord& val) const {
		return numTurns < val.numTurns;
	}
};


class HighScores
{
public:
	explicit HighScores(const char *);
	~HighScores();

	bool input(string, int, int);
	void write_file();
	bool read_file(int);
	int search_open_index();
	highscoreRecord search_by_name(string, int);
	bool replace(string, int, int);
	void delete_score();
	void display_all(int);
	void sort();
	void display_data();
	/*void clear_stream();
	*/
private:
	highscoreRecord highscores;
	vector<vector<highscoreRecord>> vHighscores;
	fstream highscoreFile;
};

