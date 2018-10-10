/*
 * Organism.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 *      Author: agarza
 */
#include "Organism.h"
#include <iostream>

// constructor
Organism::Organism()
{
	preyStatus = 0; // default value
	canBreed = 0; // no time steps have passed
	numRow = -1; // set to default non-existent values
	numCol = -1; // set to default non-existent values
	hasMoved = false; // the default is that org has not moved
} // Organism Constructor
/**
 * Getter for the prey status variable holding what kind of organism it is
 * @return 0 if neither prey/predator, 1 if prey, 2 if predator
 */
int Organism::getPreyStatus(){
	return preyStatus;
}
/**
 * Protected method only available to derived classes of organism.
 * Used when creating a particular instance of an Organism to change
 * its preyStatus.
 */
void Organism::setPreyStatus(int p){
	preyStatus = p;
}
/**
 * Resets the breeding steps if the organism has just bred
 */
void Organism::setCanBreed(int p){
	canBreed = p;
}
/**
 * Returns the value of the number of time steps an organism has experienced
 * to see if it can breed
 * @return int The time steps that have been taken
 */
int Organism::getCanBreed(){
	return canBreed;
}
/**
 * Generic function header used to hold the space
 */
void Organism::move(Organism** o, int r, int c, int nrows, int ncols) {

}
/**
 * Sets the row to the current row of the organism
 * @param r The current row of the organism
 */
void Organism::setRow(int r) {
	numRow = r;
}
/**
 * Returns the row the Organism is located at
 * @param int The current row
 */
int Organism::getRow() {
	return numRow;
}
/**
 * Sets the column location of the Organism
 * @param c The current column location
 */
void Organism::setCol(int c) {
	numCol = c;
}
/**
 * Returns the column of the current Organism
 * @return int Current column
 */
int Organism::getCol() {
	return numCol;
}
/**
 * Creates an array to represent each of the four adjacent cells. Info is stored
 * assuming each index starting from 0 represents up, down, right, and left respectively.
 * A (1) is placed into the index if the cell is occupied and (0) if it is unoccupied.
 * @param grid The current state of the game board
 * @param r The row of the element being looked at
 * @param c The column of the element being looked at
 * @param count The size of the array that is being created
 * @return An array holding values representing an occupied or unoccupied neighbor state
 */
int* Organism::enumerateNeighbors(Organism*** grid, int r, int c, int count, int nrows,
		int ncols) {
	int * neighbors = new int[count]; // creates an array

	// checks element above for occupancy
	if (((r - 1) >= 0 && c >= 0) && ((r - 1) < nrows && c < ncols)
			&& grid[r - 1][c] == NULL)
		neighbors[0] = 0; // if element points to null and is in bound, then it is unoccupied
	else
		neighbors[0] = 1; // a cell is occupied if it is out of bounds or not null
	// checks element below for occupancy
	if (((r + 1) >= 0 && c >= 0) && ((r + 1) < nrows && c < ncols)
			&& grid[r + 1][c] == NULL)
		neighbors[1] = 0;
	else
		neighbors[1] = 1;
	// checks element to right for occupancy
	if ((r >= 0 && (c + 1) >= 0) && (r < nrows && (c + 1) < ncols)
			&& !grid[r][c + 1])
		neighbors[2] = 0;
	else
		neighbors[2] = 1;
	// checks element to left for occupancy
	if ((r >= 0 && (c - 1) >= 0) && (r < nrows && (c - 1) < ncols)
			&& grid[r][c - 1] == NULL)
		neighbors[3] = 0;
	else
		neighbors[3] = 1;

	return neighbors; // array should contain either 1 or 0 depending on if a neighbor in a given direction is unoccupied
}
/**
 * Changes the bool value marking if a given organism has moved in a time step
 */
void Organism::setMoved(bool p){
	hasMoved = p;
}
/**
 * Returns whether the organism has moved this turn
 * @return if has moved
 */
bool Organism::getMoved(){
	return hasMoved;
}
Organism::~Organism(){

}
