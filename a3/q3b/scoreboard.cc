#include "scoreboard.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// constructor
ScoreBoard::ScoreBoard()
: Xscore(0), Oscore(0), count(0), done(false),quit(false)
{
	for(int i = 0; i < TOTAL; i++)
	{
		board[i] = '_'; // initialize the score board by '_'
	}
}

// reset the scoreboard for the next game.
void ScoreBoard::nextround()
{
	count = 0;
	done = false;
	quit = false;
	for(int i = 0; i < TOTAL; i++)
	{
		board[i] = '_';
	}
}

// check if there is a winner or not.
char ScoreBoard::winner() const
{
	const int wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
	const int rows = 8;

	for(int i = 0; i < rows; i++)
	{
		if((board[wins[i][0]] != '_') && (board[wins[i][0]] == board[wins[i][1]]) && 
			(board[wins[i][1]] == board[wins[i][2]]))
		{
			return board[wins[i][0]]; // returns the winner 'X' or 'O'
		}
	}
	if(count == TOTAL) // no one wins the game
	{
		return 'T';
	}
	return 'N'; // 'N' means the game is not finished yet.
}

// update score and print the game result.
void ScoreBoard::showResult(const char result)
{
	if(result == 'X') // X wins
	{
		Xscore++;
		cout << "X wins" << endl;
	}
	else if(result == 'O') // O wins
	{
		Oscore++;
		cout << "O wins" << endl;
	}
	else // tie
	{
		cout << "Draw" << endl;
	}
	cout << "Score is" << endl
	<< "X " << Xscore << endl
	<< "O " << Oscore << endl;
}

// if the game has a result, then print the score.
void ScoreBoard::check()
{
	char status = winner();

	if(status != 'N') // if this is true, means the game is finished.
	{
		showResult(status);
		done = true;
	}
}

// register the move with the scoreboard.
void ScoreBoard::makeMove(istream& in, const char name, const string inputtype)
{
	string str;

	while(in >> str)
	{
		if(str == "NW")
		{
			if(board[0] != '_') continue;
			board[0] = name;
			count++;
			break;
		}
		if(str == "N")
		{
			if(board[1] != '_') continue;
			board[1] = name;
			count++;
			break;
		}		
		if(str == "NE")
		{
			if(board[2] != '_') continue;
			board[2] = name;
			count++;
			break;
		}
		if(str == "W")
		{
			if(board[3] != '_') continue;
			board[3] = name;
			count++;
			break;
		}
		if(str == "C")
		{
			if(board[4] != '_') continue;
			board[4] = name;
			count++;
			break;
		}
		if(str == "E")
		{
			if(board[5] != '_') continue;
			board[5] = name;
			count++;
			break;
		}
		if(str == "SW")
		{
			if(board[6] != '_') continue;
			board[6] = name;
			count++;
			break;
		}
		if(str == "S")
		{
			if(board[7] != '_') continue;
			board[7] = name;
			count++;
			break;
		}
		if(str == "SE")
		{
			if(board[8] != '_') continue;
			board[8] = name;
			count++;
			break;
		}
		if(str == "quit") // set quit flag to be true and return.
		{
			quit = true;
			return;
		}
	}

	if(inputtype != "stdin") // moves are taken from a file
	{
		cout << "(plays " << str << ")" << endl;
	}
}

