#ifndef CELL_H
#define CELL_H
#include <iostream>

//forward declare the Game class
//as an include is not needed
class Game; 

const int MAXNEIGHBOURS = 4;

class Cell {
  int state;        //current state of the cell
  int prevState;    //previous state of the cell
  int numNeighbours;   //number of neighbors
  Cell *neighbours[MAXNEIGHBOURS];   //pointers to neighbors
  int row, column;                   //co-ordinates of the cell
  Game * game;                //pointer to game
  
  // Add other private members if necessary

  void notifyNeighbours() const ;   // Tell all of my neighbours that I have been switched.
  void notifyGame() const ;	   // notify the game and registered notification object of the change

 public:
  Cell();                           // Default constructor

  char getState() const ;          //getter for private state
  void setState(const int& change);         //setter for private state
  void setCoords(const int row, const int column);		    //setter for private co-ordinates of cell

  void setGame(Game * game);  //setter for game

  void addNeighbour(Cell *neighbour);       //add a neighbouring cell

  /*
   * The following methods are provided as a hint towards 
   * implementing the notification.
   * You should try to use the methods with the given signatures.
   *
   * If you feel the need to change the *signature* of the method 
   * (do not change the name) you may do so but MUST provide a comprehensive 
   * explanation in your code why you felt the change was necessary
   */
	
	
  /*
   * Intended to be called only by the game class for changing the state of the 0 0 cell
   */
  void notify( const int & change);

	/*
	 * Intended to be called by Cells to notify their neighbors
	 * current: this cells current(new) state 
	 * previous: this cells past state
	 */
  void notify( const int& current, const int&  previous); 
};
#endif
