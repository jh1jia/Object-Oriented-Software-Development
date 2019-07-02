#include "cell.h"
#include "game.h"
#include <iostream>
using namespace std;


Cell::Cell()
:state(0), prevState(-1), numNeighbours(0), row(0), column(0), game(NULL)
{
  for(int i = 0; i < MAXNEIGHBOURS; i++)
  {
    this->neighbours[i] = NULL;
  }
}

char Cell::getState() const
{
    char ch;
    if(state == 0)
    {
      ch = '0';
    }
    else if(state == 1)
    {
      ch = '1';
    }
    else if(state == 2)
    {
      ch = '2';
    }
    else if(state == 3)
    {
      ch = '3';
    }
    else
    {
      ch = '4';
    }
    return ch;
}

void Cell::notifyGame() const
{
  game->notify(row, column, prevState, state);
}

void Cell::notifyNeighbours() const
{
  for(int i = 0; i < numNeighbours; i++)
  {
    neighbours[i]->notify(state, prevState);
  }
}

void Cell::setState(const int& change)
{
  prevState = state;
  state = change;
}

void Cell::setGame(Game* game)
{
  this->game = game;
}


void Cell::setCoords(const int row, const int column)
{
  this->row = row;
  this->column = column;
}

void Cell::addNeighbour(Cell *neighbours)
{
  this->neighbours[numNeighbours] = neighbours;
  numNeighbours++;
}

void Cell::notify(const int& change)
{
  prevState = state;
  state = change;
  notifyGame();
  notifyNeighbours();
}

void Cell::notify(const int& current, const int& previous)
{
  if(state == previous && state != current)
  { 
    prevState = state;
    state = current;
    notifyGame();
    notifyNeighbours();
  }
}
