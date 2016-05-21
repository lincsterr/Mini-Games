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

using namespace std;

//structure of HighScores
struct highscoreRecord {
	int idnum;
	int gameID;
	char name[30];
	int numTurns;
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
	int search_by_name(string, int);
	//void delete_file();
	void display_all(int);
	void display_data();
	/*void clear_stream();
	*/
private:
	highscoreRecord highscores;
	fstream highscoreFile;
};

