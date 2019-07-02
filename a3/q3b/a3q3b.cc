#include "scoreboard.h"
#include "player.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::ifstream;

int main()
{
	int turn = 0; // count innings
	string str;

	ScoreBoard newgame;

	while(cin >> str)
	{
		if (str == "game")
		{
			string in1, in2; // to store input types of two players
			ifstream fin1, fin2;
			cin >> in1 >> in2; 
			turn++;

			Player playerx('X', in1, &newgame);
			Player playero('O', in2, &newgame);

			// set the input stream.
			playerx.inway();
			playero.inway();

            // X plays first in odd-numbered games (starting from 1), 
			// and O plays first in even-numbered games.
			if(turn % 2 != 0) 

			{
				while(1)
				{
					playerx.makeMove(); // player X's move.
					// if receive the quit command, then quit the program.
					if(newgame.quit) return 0;
					if(newgame.done)
					{ 
						newgame.nextround(); // reset the score board.
						break;
					}
					playero.makeMove(); // player O's move.
					if(newgame.quit) return 0;
					if(newgame.done) 
					{ 
						newgame.nextround();
						break;
					}
				}
				continue;
			}
			else
			{
				while(1)
				{
					playero.makeMove();
					if(newgame.quit) return 0;
					if(newgame.done) 
					{ 
						newgame.nextround();
						break;
					}
					playerx.makeMove();
					if(newgame.quit) return 0;
					if(newgame.done)
					{ 
						newgame.nextround();
						break;
					}
				}
				continue;
			}
		}
		if (str == "quit")
		{
			return 0;
		}
	}

	return 0;
}


