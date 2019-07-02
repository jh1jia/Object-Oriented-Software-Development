#include <iostream>
#include "game.h"
using namespace std;


void Game::notify(int row, int column, unsigned int oldState, unsigned int newState)
{
  colours[oldState]--;
  colours[newState]++;
  notification->notify(row, column, newState);
}

Game::Game():gridSize(0), theGrid(NULL), notification(NULL)
{
  for(int i = 0; i < 5; i++)
  {
    colours[i] = 0;
  }
}

Game::~Game()
{
  clearGame();
}

void Game::clearGame()
{
  for(int i = 0; i < gridSize; i++)
  {
    delete [] theGrid[i];
    theGrid[i] = NULL;
  }
  delete [] theGrid;
  theGrid = NULL;
}

bool Game::isWon() const 
{
  unsigned int total = gridSize * gridSize;

  for(int i = 0; i < 5; i++)
  {  
    if(colours[i] == total)
    {
      return true;
    }
  }
  return false;
}

void Game::init(int n, GameNotification *gameNotification)
{
  gridSize = n;
  notification = gameNotification;

  if(theGrid != NULL)
  {
    clearGame();
  }

  colours[0] = gridSize * gridSize;
  for(int i = 1; i < 5; i++)
  {
    colours[i] = 0;
  }

  theGrid = new Cell* [gridSize];

  for(int i = 0; i < gridSize; i++)
  {
    theGrid[i] = new Cell[gridSize];

    for(int j = 0; j < gridSize; j++)
    {
      theGrid[i][j].setCoords(i, j);
      theGrid[i][j].setGame(this);
    }
  }

  for(int i = 0; i < gridSize; i++)
  {
    for(int j = 0; j < gridSize; j++)
    {
      if(j != 0)
      {
        theGrid[i][j].addNeighbour(&(theGrid[i][j-1]));
      }
      if(i != 0)
      {
        theGrid[i][j].addNeighbour(&(theGrid[i-1][j]));
      }
      if(j != gridSize-1)
      {
        theGrid[i][j].addNeighbour(&(theGrid[i][j+1]));
      }
      if(i != gridSize-1)
      {
        theGrid[i][j].addNeighbour(&(theGrid[i+1][j]));
      }
    }
  }
}

void Game::init(int row, int column, int state)
{
  // If the triple row column state refers to invalid co-ordinates, the triple is ignored.
  if(row >= 0 && row < gridSize && column >= 0 && column < gridSize && state >= 0 && state <= 4)
  {
    char oldstate = theGrid[row][column].getState();
    colours[oldstate - '0']--;
    colours[state]++;
    theGrid[row][column].setState(state);
  }
}

void Game::change(const int& state)
{
  theGrid[0][0].notify(state);
}


