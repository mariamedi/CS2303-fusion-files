/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 *      Author: agarza
 */
#include <iostream>
#include "Doodlebug.h"
#include "Organism.h"

//constructor
Doodlebug::Doodlebug(int row, int col) {
	timeStepsSinceEaten = 0;
	setRow(row);
	setCol(col);
	setPreyStatus(2);
}
/**
 * Takes the indices to a doodlebug in the grid and moves it according
 * to the provided rules. Looks for ants adjacent to it and moves to eat it.
 * Else it moves like an ant would by randomly selecting an unoccupied cell that's not off the
 * grid and moves the doodlebug there.
 * @param grid The array holding the current game state
 * @param r The row index of the doodlebug to be moved
 * @param c The column index of the doodlebug to be moved
 * @param nrows The total number of rows in the grid
 * @param ncols The total number of columns in the grid
 * @return True if an ant was eaten, false if not
 */
bool Doodlebug::move(Organism*** grid, int r, int c, int nrows, int ncols) {
	bool ateAnt = false;
	// if no ants were found, then moves like an ant
	// arrayof size 4 holding either 0 or 1 if it is a valid spot
	int count = 4; // size of the array to be returned

	// vars keep track if the given neighbors are unoccupied, true if they are
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;

	// keep track of whether an occupied space has an ant in it
	bool upAnt = false;
	bool downAnt = false;
	bool rightAnt = false;
	bool leftAnt = false;

	int randomSelector; // will hold the value of the random neighbor being selected

	int* neighbors = enumerateNeighbors(grid, r, c, count, nrows, ncols); // array holding info of surrounding neighbors
	int unoccupied = 0; // number of free neighbors around the doodlebug
	int ants = 0; // number of ants surrounding doodle
	// iterate through array and count how many are unoccupied
	for (int i = 0; i < count; i++) {

		if (*neighbors++ == 0) { // if 0 was returned, then that neighbor is unoccupied
			unoccupied++;

			// changes the values of the boolean vars to keep track of which neighbor is unoccupied
			switch (i) {
			case 0:
				up = true;
				break;
			case 1:
				down = true;
				break;
			case 2:
				right = true;
				break;
			case 3:
				left = true;
				break;
			default:
				break;
			}
		} else {
			//changes the values of the ant tracker booleans
			// checks to see if  the values are in bounds, if they are then it's an ant
			switch (i) {
			case 0:
				if ((((r - 1) >= 0 && c >= 0) && ((r - 1) < nrows && c < ncols)
						&& grid[r - 1][c] != NULL
						&& grid[r - 1][c]->getPreyStatus() == 1)) {
					upAnt = true;
					ants++;
				}
				break;
			case 1:
				if (((r + 1) >= 0 && c >= 0) && ((r + 1) < nrows && c < ncols)
						&& grid[r + 1][c] != NULL
						&& grid[r + 1][c]->getPreyStatus() == 1) {
					downAnt = true;
					ants++;
				}
				break;
			case 2:
				if ((r >= 0 && (c + 1) >= 0) && (r < nrows && (c + 1) < ncols)
						&& grid[r][c + 1] != NULL
						&& grid[r][c + 1]->getPreyStatus() == 1) {
					rightAnt = true;
					ants++;
				}
				break;
			case 3:
				if ((r >= 0 && (c - 1) >= 0) && (r < nrows && (c - 1) < ncols)
						&& grid[r][c - 1] != NULL
						&& grid[r][c - 1]->getPreyStatus() == 1) {
					leftAnt = true;
					ants++;
				}
				break;
			default:
				break;
			}
		}

	} // end for
	  // first check to see if there are any ants to influence movement
	  // makes sure that it is not reading a bug that has already moved
	  // if there is only one ant, the doodlebug goes there
	if (ants == 1 && !grid[r][c]->getMoved()) {
		if (upAnt) {
			delete grid[r - 1][c]; // delete the ant that had been there
			grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r - 1][c]->setMoved(true);
		} else if (downAnt) {
			delete grid[r + 1][c];
			grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r + 1][c]->setMoved(true);
		} else if (rightAnt) {
			delete grid[r][c + 1];
			grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r][c + 1]->setMoved(true);
		} else if (leftAnt) {
			delete grid[r][c - 1];
			grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r][c - 1]->setMoved(true);
		}
		ateAnt = true;
		setTimeStepsSinceEaten(0); // reset the time passed since they ate back to 0
		//delete grid[r][c];
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	} else if (ants > 1 && !grid[r][c]->getMoved()) // random ant victim must be chosen
			{
		randomSelector = rand() % ants; // finds a random number w/ available count

		// number should at most have been 3 as count is 4, so checks to see which was selected
		// and moves the doodlebug. A case should be selected because value above is being modded by the count
		switch (randomSelector) {
		case 0:
			if (upAnt) {
				grid[r - 1][c] = NULL;
				grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
				grid[r - 1][c]->setMoved(true);
			}
			break;
		case 1:
			if (downAnt) {
				grid[r + 1][c] = NULL;
				grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
				grid[r + 1][c]->setMoved(true);
			}
			break;
		case 2:
			if (rightAnt) {
				grid[r][c + 1] = NULL;
				grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
				grid[r][c + 1]->setMoved(true);
			}
			break;
		case 3:
			if (leftAnt) {
				grid[r][c - 1] = NULL;
				grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
				grid[r][c - 1]->setMoved(true);
			}
			break;
		default:
			break;
		}
		ateAnt = true;
		setTimeStepsSinceEaten(0); // reset the time passed since they ate back to 0
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	}

// movement depends on how many are unoccupied
// if there is only one unoccupied neighbor, it looks for the free position
	else if (unoccupied == 1 && !grid[r][c]->getMoved()) {
		if (up) {
			grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r - 1][c]->setMoved(true);
		} else if (down) {
			grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r + 1][c]->setMoved(true);
		} else if (right) {
			grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r][c + 1]->setMoved(true);
		} else if (left) {
			grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
			grid[r][c - 1]->setMoved(true);
		}
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	} else if (unoccupied > 1 && !grid[r][c]->getMoved()) { // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
		while (!grid[r][c]->getMoved()) { // runs until the doodle has moved
			randomSelector = rand() % count; // finds a random number w/ available count
			// number should at most have been 3 as count is 4, so checks to see which was selected
			// and moves the ant. A case should be selected because value above is being modded by the count
			switch (randomSelector) {
			case 0:
				if (up) {
					grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
					grid[r - 1][c]->setMoved(true); // to ensure not moved again in same turn
				}
				break;
			case 1:

				if (down) {
					grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
					grid[r + 1][c]->setMoved(true); // to ensure not moved again in same turn
				}
				break;
			case 2:
				if (right) {
					grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
					grid[r][c + 1]->setMoved(true); // to ensure not moved again in same turn
				}
				break;
			case 3:
				if (left) {
					grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
					grid[r][c - 1]->setMoved(true); // to ensure not moved again in same turn
				}
				break;
			default:
				break;
			}
		}
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	}
// if there are no free spaces the function exits without having moved the ant
	return ateAnt;
}
/**
 * Functions focuses on whether a doodlebug can breed. Can only breed if 8 time steps
 * have passed. Checks this and if there is space, then it breeds else it stays still.
 * @param grid Holds the current state of the board
 * @r The row of the doodlebug
 * @c The column of the doodlebug
 * @nrows The number of rows in the grid
 * @ncols The number of columns in the grid
 * @return Whether the doodle successfully bred
 */
bool Doodlebug::breedDoodle(Organism*** grid, int r, int c, int nrows,
		int ncols) {
	// checks to see if doodle has been alive for at least 8 time steps
	if (getCanBreed() >= 8) { // take steps to see if a doodle has space to spawn as it is eligible
		int count = 4; // size of the array to hold the neighbors

		// vars keep track if the given neighbors are unoccupied, true if they are
		bool up = false;
		bool down = false;
		bool right = false;
		bool left = false;

		int randomSelector; // will hold the value of the random neighbor being selected

		int* neighbors = enumerateNeighbors(grid, r, c, count, nrows, ncols);
		int unoccupied = 0;

		// iterate through array and count how many are unoccupied
		for (int i = 0; i < count; i++) {
			if (*neighbors++ == 0) { // if 0 was returned, then that neighbor is unoccupied
				unoccupied++;

				// changes the values of the boolean vars to keep track of which neighbor is unoccupied
				switch (i) {
				case 0:
					up = true;
					break;
				case 1:
					down = true;
					break;
				case 2:
					right = true;
					break;
				case 3:
					left = true;
					break;
				default:
					break;
				}
			}
		}
		// spawn location depends on how many are unoccupied
		// if there is only one unoccupied neighbor, it looks for the free position
		if (unoccupied == 1) {
			if (up) {
				grid[r - 1][c] = new Doodlebug(r - 1, c); // assigns the located pointer to a new ant
			} else if (down) {
				grid[r + 1][c] = new Doodlebug(r + 1, c); // assigns the located pointer to a new ant
			} else if (right) {
				grid[r][c + 1] = new Doodlebug(r, c + 1); // assigns the located pointer to a new ant
			} else if (left) {
				grid[r][c - 1] = new Doodlebug(r, c - 1); // assigns the located pointer to a new ant
			}
			setCanBreed(0); // resets this doodle's breed count
			return true; // successfully spawned a new doodle
		} else if (unoccupied > 1) { // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
			randomSelector = rand() % count; // finds a random number w/ available count

			// number should at most have been 3 as count is 4, so checks to see which was selected
			// and spawns an ant. A case should be selected because value above is being modded by the count
			switch (randomSelector) {
			case 0:
				if (up)
					grid[r - 1][c] = new Doodlebug(r - 1, c); // assigns the located pointer to a new ant
				break;
			case 1:
				if (down)
					grid[r + 1][c] = new Doodlebug(r + 1, c); // assigns the located pointer to a new ant
				break;
			case 2:
				if (right)
					grid[r][c + 1] = new Doodlebug(r, c + 1); // assigns the located pointer to a new ant
				break;
			case 3:
				if (left)
					grid[r][c - 1] = new Doodlebug(r, c - 1); // assigns the located pointer to a new ant
				break;
			default:
				break;
			}
			setCanBreed(0); // resets the doodle breed count
			return true; // successfully spawned a new doodle
		}
	}
	return false; // no doodle was spawned during the existence of this function

}
/**
 * Checks to see if the current doodlebug is starving or not, if it is
 * then it is deleted from the grid.
 * @param grid The current state of the game
 * @param r The row of the doodlebug
 * @param c The column of the doodlebug
 * @return True if the doodle starved, false if it did not
 */
bool Doodlebug::checkStarvation(Organism*** grid, int r, int c) {
	if (getTimeStepsSinceEaten() >= 3) // the doodle is starved and will die
			{
		delete grid[r][c];
		grid[r][c] = NULL;
		grid[r][c] = new Organism(); // set the old pointer to null
		return true;
	}
	return false;
}
/**
 * Returns how many time steps have passed since the doodlebug ate
 * @return the number of time steps that passed
 */
int Doodlebug::getTimeStepsSinceEaten() {
	return timeStepsSinceEaten;
}
/**
 * Sets the timeSteps to the passed in value
 * @param t The steps that are being set
 */
void Doodlebug::increaseTimeStepsSinceEaten() {
	timeStepsSinceEaten++;
}
/**
 * Sets the timeSteps to the passed in value
 * @param t The steps that are being set
 */
void Doodlebug::setTimeStepsSinceEaten(int i) {
	timeStepsSinceEaten = i;
}
Doodlebug::~Doodlebug() {

}
