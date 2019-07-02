#ifndef Player_H
#define Player_H
#include "scoreboard.h"
#include <fstream>
#include <string>
using std::fstream;
using std::string;

class Player
{
public:
	const char name; // player X or O.
	const string inputtype; // input from stdin or a file.
	ScoreBoard* bd; // a pointer to the scoreboard
	fstream fin;
	void makeMove();
	void inway(); // if the input is from a file, then open the file.
	Player(const char, const string, ScoreBoard*);	// constructor
};

#endif
