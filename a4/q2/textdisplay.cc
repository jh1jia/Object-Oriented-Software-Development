#include "textdisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(int n): View(n)
{
  theDisplay = new char* [gridSize];
  for(int i = 0; i < gridSize; i++)
  {
    theDisplay[i] = new char[gridSize];
    for(int j = 0; j < gridSize; j++)
    {
      theDisplay[i][j] = '0'; // the display is initialized with '0'
    }
  }
}


TextDisplay::~TextDisplay()
{
  for(int i = 0; i < gridSize; i++)
  {
    delete [] theDisplay[i];
    theDisplay[i] = NULL;
  }
  delete [] theDisplay;
  theDisplay = NULL;
}


void TextDisplay::notify(int row, int column, char ch)
{
  // If the triple row column ch refers to invalid co-ordinates, the triple is ignored.
  if(row >= 0 && row < gridSize && column >= 0 && column < gridSize)
    {
      theDisplay[row][column] = ch;
    }
}


void TextDisplay::print(std::ostream& out) const
{
  for(int i = 0; i < gridSize; i++)
  {
    for(int j = 0; j < gridSize; j++)
    {
      out << theDisplay[i][j];
    }
    out << endl;
  }
}
