#ifndef ScoreBoard_H
#define ScoreBoard_H
#include <iostream>
#include <string>
using std::istream;
using std::string;

const int TOTAL = 9; // 3x3 grid.

class ScoreBoard
{
public:
	char board[TOTAL];
	int Xscore;
	int Oscore;
	int count; // count moves of player X and player O.
	bool done; // if one game is finished, set done to true.
	bool quit; 
	ScoreBoard(); // constructor
	char winner() const; // check if there is a winner or not.
	void check(); // if the game has a result, then print the score.
	void nextround(); // reset the scoreboard for the next game.
	void showResult(const char); // update score and print the game result.
	void makeMove(istream&, const char, const string); // register the move with the scoreboard.
};

#endif


