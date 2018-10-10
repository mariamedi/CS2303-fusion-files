/*
 * Board.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: mdmedinamartinez
 *      Author: agarza
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

	// populate the game board w/ initial organisms
	initializeGameBoard(seed);

} // constructor
/**
 * Initializes the board to a random grid filled with the desired
 * doodlebugs and ants
 */
void Board::initializeGameBoard(int seed) {
	cout << countDoodles << endl;
	cout << countAnts << endl;
	srand(seed); // set the seed

	int r, c; // Where a given organism will be placed

	// place all the doodles w/ for loop
	for (int i = 0; i < totalDoodles; i++) {

		do {
			// finds random row and col number for element
			r = (rand() % nrows);
			c = (rand() % ncols);

		} while (r >= 0 && c >= 0 && r < nrows && c < ncols
				&& gridA[r][c] != NULL); // keeps running until a null pointer is found, so a doodlebug can inhabit the space
		// only adds a doodlebug if there is no current doodlebug located there
		gridA[r][c] = new Doodlebug(r, c); // sets a new Organism pointer in given array spot
	}
// place all the ants w/ for loop
	for (int i = 0; i < totalAnts; i++) {
		do {
			// finds random row and col number for element
			r = (rand() % nrows);
			c = (rand() % ncols);

		} while (gridA[r][c] != NULL); // keeps running until a null pointer is found, so an ant can inhabit the space

		// adds the ant in the empty spot previously found
		gridA[r][c] = new Ant(r, c);
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
int Board::checkIfPrey(Organism**o) {
	return (*o)->getPreyStatus(); // calls the pointer's method to see if it's prey
}
/**
 * Gets a pointer to the organism stored in the given cell
 * @return Pointer to the Organism in cell
 */
Organism* Board::getPointer(int r, int c) {
	return gridA[r][c]; // returns the address of the cell;
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

	Organism* temp; // holds the current organism pointer we are looking at
	Doodlebug* dTemp; // holds a doodlebug temp pointer
	Ant * aTemp; // holds an ant temp pointer

	// iterates through board and changes the value of hasMoved to false since it will be a new iteration
	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < ncols; c++) {
			// proceeds if it contains an organism
			if (gridA[r][c] != NULL) {
				temp = gridA[r][c];
				temp->setMoved(false); // resets movement to false b/c new turn about to occur
			}
		}
	}

	// iterates through the game board and focuses on doodlebug actions
	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < ncols; c++) {
			// if it has an organism it proceeds
			if (gridA[r][c] != NULL) {
				temp = gridA[r][c];

				if (temp->getPreyStatus() == 2 && !temp->getMoved()) { // if we encounter a doodlebug
					dTemp = static_cast<Doodlebug*>(temp); // know it's a doodlebug, so we cast it
					// increases necessary time steps by one
					dTemp->setCanBreed(dTemp->getCanBreed() + 1);
					dTemp->increaseTimeStepsSinceEaten(); // increases time by one
					if (dTemp->move(gridA, r, c, nrows, ncols)) // moves the doodlebug first
						countAnts--; // decreases ant count as one was eaten
					if (dTemp->checkStarvation(gridA, r, c)) // checks to see if it has starved
							{
						countDoodles--; // decreases the current count of the doodles
					} else if (dTemp->breedDoodle(gridA, r, c, nrows, ncols)) {
						// increases all the doodle counts as a new one was born
						countDoodles++;
						totalDoodles++;
					}
				}
			}
		}
	}
	// iterates through the game board again and focuses on the ants
	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < ncols; c++) {
			// if it has an organism it proceeds
			if (gridA[r][c] != NULL) {
				temp = gridA[r][c];

				if (temp->getPreyStatus() == 1 && !temp->getMoved()) { // if we encounter an ant
					aTemp = static_cast<Ant*>(temp); // know it's an ant, so we cast it
					// increases necessary time steps by one
					aTemp->setCanBreed(aTemp->getCanBreed() + 1);

					aTemp->move(gridA, r, c, nrows, ncols); // moves the ant
					if (aTemp->breedAnt(gridA, r, c, nrows, ncols)) {
						// increases all the ant counts as a new one was born
						countAnts++;
						totalAnts++;
					}
				}
			}
		}
	}

	completedTimeSteps++;
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
	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < ncols; c++) {
			if (gridA[r][c] != NULL && gridA[r][c]->getPreyStatus() == 1) { // ant
				cout << 'o';
			} else if (gridA[r][c] != NULL
					&& gridA[r][c]->getPreyStatus() == 2) { // doodlebug
				cout << 'x';
			} else {
				cout << '-';
			}
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
	int reasonForEnd = checkTermination(); // displayed at the end as reasoning
	cout << "Final Grid" << endl;

// outputs the original command line
	cout << "./";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	switch (reasonForEnd) {
	case 0:
		cout << "Termination reason: Reached desired time steps" << endl;
		break;
	case 1:
		cout << "Termination reason: All ants consumed" << endl;
		break;
	case 2:
		cout << "Termination reason: All doodlebugs starved" << endl;
		break;
	default:
		break;
	}
	cout << "Time steps completed: " << completedTimeSteps << endl;
	cout << "Total Ants: " << totalAnts << " Remaining Ants: " << countAnts
			<< endl;
	cout << "Total Doodles: " << totalDoodles << " Remaining Doodles: "
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

