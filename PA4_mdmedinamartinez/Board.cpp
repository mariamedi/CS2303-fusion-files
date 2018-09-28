/*
 * Board.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: mdmedinamartinez
 */
#include "Board.h"

// constructor
Board::Board(int rows, int cols, int ants, int doodles, int seed) {
	nrows = rows;
	ncols = cols;
	countAnts = ants;
	countDoodles = doodles;
	totalAnts = ants;
	totalDoodles = doodles;
	completedTimeSteps = 0;
	terminatingCondition = -1;
	this->seed = seed;

	// creates arrays to hold the current and next state of the game
	gridA = make2DOrganism(nrows, ncols);
	//gridB = make2DOrganism(nrows, ncols);

	// populate the game board w/ initial organisms
	initializeGameBoard(seed);

} // constructor
/**
 * Initializes the board to a random grid filled with the desired
 * doodlebugs and ants
 */
void Board::initializeGameBoard(int seed) {
	srand(seed); // set the seed

	int r, c; // Where a given organism will be placed

	// place all the doodles w/ for loop
	for (int i = 0; i < totalDoodles; i++) {

		do {
			// finds random row and col number for element
			r = (int) ((rand() * 100) % nrows);
			c = (int) ((rand() * 100) % ncols);

		} while (getPointer(r,c) != NULL); // keeps running until a null pointer is found, so a doodlebug can inhabit the space

		// only adds a doodlebug if there is no current doodlebug located there
		//&getPointer(r,c) = new Doodlebug(); // sets a new Organism pointer in given array spot
	}
// place all the ants w/ for loop
	for (int i = 0; i < totalAnts; i++) {
		do {
			// finds random row and col number for element
			r = (int) ((rand() * 100) % nrows);
			c = (int) ((rand() * 100) % ncols);

		} while (getPointer(r,c) != NULL); // keeps running until a null pointer is found, so an ant can inhabit the space

		// adds the ant in the empty spot previously found
		Organism* o_pointer = getPointer(r,c);
		o_pointer = new Ant();
	}
}
/**
 * Checks whether the given coordinates are in bounds of the grid
 * @return True if they are within bounds, False if they are not
 */
bool Board::checkBounds(int r, int c) {
// check to see if the given row and column are in bounds
	if (c >= ncols || c < 0 || r >= nrows || r < 0)
		return false;
	return true;
}
/**
 * Gets the pointer to the Organism stored in the given cell and calls
 * the organism's function to check if it is prey or not
 * @return 0 if empty organism, 1 if the given organism is prey, 2 if not
 */
int Board::checkIfPrey(Organism* o) {
	return o->getPreyStatus(); // calls the pointer's method to see if it's prey
}
/**
 * Gets a pointer to the organism stored in the given cell
 * @return Pointer to the Organism in cell
 */
Organism* Board::getPointer(int r, int c) {
	return &gridA[r][c]; // returns the address of the cell;
}
/**
 * Plays one time step / round of the game
 * Iterates through current grid and moves the doodlebugs according to their rules.
 * After placing the doodles in their new locations, the current grid is iterated
 * through again, but the ants are now moved. Ants are moved according to their rules
 * and also by checking to see whether they were eaten by a doodle in the same step. Does
 * this by checking to see whether there are newly placed doodles in the next location grid.
 */
void Board::playRound() {
// should update the count of doodles and ants as it goes through

}
/**
 * Getter method for the completedTimeSteps member
 * @return The number of time steps completed so far
 */
int Board::getSteps() {
	return completedTimeSteps;
}
/**
 * Prints out the current game grid stored in gridA
 * o : prey
 * x: predator
 *  : empty space
 */
void Board::printBoard() {
	/* loops through entirety of the current array
	 to print out every character*/
	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < ncols; c++) {
			if (checkIfPrey(&gridA[r][c]) == 1)
				cout << 'o';
			else if (checkIfPrey(&gridA[r][c]) == 2)
				cout << 'x';
			else
				cout << ' ';
		}
		cout << endl;
	}
}
/**
 * Iterates through the current grid and checks to see if
 * any of the organism numbers have dropped to 0, thus signaling a game end.
 * @return Int specifying the reason for termination. 0 = no termination, 1 = no ants, 2 = no doodles
 */
int Board::checkTermination() {
	if (countAnts == 0) // no more ants
		return 1;
	else if (countDoodles == 0) // no more doodles
		return 2;
	else
		return 0; // no reason found for termination
}
/**
 * Prints a summary of the ending stage of the game
 * Outputs original command line arguments, the time steps completed,
 * the total number of ants that existed and that are left,
 * and the total number of doodles that existed and that are left at game end,
 * and picture of the final grid.
 */
void Board::printEnd(int argc, char** argv) {
	cout << "Final Grid" << endl;

// outputs the original command line
	cout << "./";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	cout << "Time steps completed: " + completedTimeSteps << endl;
	cout << "Total Ants: " << totalAnts << "Remaining Ants: " << countAnts << endl;
	cout
			<< "Total Doodles: " << totalDoodles << "Remaining Doodles: "
					<< countDoodles << endl;
	printBoard();
}
// come back to this
Board::~Board() {
// iterates through each element of the arrays and deletes them
	for (int i = 0; i < nrows; i++)
		delete *gridA++;
	//for (int i = 0; i < nrows; i++)
		//delete *gridB++;
} // destructor

