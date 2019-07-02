#include "player.h"
#include "scoreboard.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// constructor
Player::Player(const char ch, const string str, ScoreBoard* sb)
:name(ch),inputtype(str),bd(sb) 
{}


void Player::makeMove()
{
	cout << name << "'s move" << endl;

	if(inputtype != "stdin")
	{
		// calling the ScoreBoard::makeMove method to register the move with the scoreboard.
		bd->makeMove(fin, name, inputtype);	
	}
	else
	{
		bd->makeMove(cin, name, inputtype);
	}

	bd->check();
}

// if the input is from a file, then open the file.
void Player::inway()
{
	if(inputtype != "stdin")
	{
		fin.open(inputtype.c_str());
	}
}

