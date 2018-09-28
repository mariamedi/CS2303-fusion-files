/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 */
#include <iostream>
#include "Doodlebug.h"
#include "Organism.h"

//constructor
Doodlebug::Doodlebug(int row, int col) {
	timeStepsSinceEaten = 0;
	setRow(row);
	setCol(col);
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
	int ants = 0; // number of either occupied or off-the-grid spaces

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
						&& grid[r - 1][c] != NULL)) {
					upAnt = true;
					ants++;
				}
				break;
			case 1:
				if (((r + 1) >= 0 && c >= 0) && ((r + 1) < nrows && c < ncols)
						&& grid[r + 1][c] == NULL) {
					downAnt = true;
					ants++;
				}
				break;
			case 2:
				if ((r >= 0 && (c + 1) >= 0) && (r < nrows && (c + 1) < ncols)
						&& !grid[r][c + 1]) {
					rightAnt = true;
					ants++;
				}
				break;
			case 3:
				if ((r >= 0 && (c - 1) >= 0) && (r < nrows && (c - 1) < ncols)
						&& grid[r][c - 1] == NULL) {
					leftAnt = true;
					ants++;
				}
				break;
			default:
				break;
			}
		}

	}
	// first check to see if there are any ants to influence movement
	// if there is only one ant, the doodlebug goes there
	if (ants == 1) {
		if (upAnt) {
			delete grid[r - 1][c]; // delete the ant that had been there
			grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
		} else if (downAnt) {
			delete grid[r + 1][c];
			grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
		} else if (rightAnt) {
			delete grid[r][c + 1];
			grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
		} else if (leftAnt) {
			delete grid[r][c - 1];
			grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
		}
		ateAnt = true;
		setTimeStepsSinceEaten(0); // reset the time passed since they ate back to 0
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	} else if (ants > 1) // random ant victim must be chosen
			{
		randomSelector = (rand() * 100) % ants; // finds a random number w/ available count

		// number should at most have been 3 as count is 4, so checks to see which was selected
		// and moves the doodlebug. A case should be selected because value above is being modded by the count
		switch (randomSelector) {
		case 0:
			if (upAnt) {
				delete grid[r - 1][c]; // delete the ant that had been there
				grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			}
			break;
		case 1:
			if (downAnt) {
				delete grid[r + 1][c];
				grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			}
			break;
		case 2:
			if (rightAnt) {
				delete grid[r][c + 1];
				grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
			}
			break;
		case 3:
			if (leftAnt) {
				delete grid[r][c - 1];
				grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location

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
	if (count == 1) {
		if (up) {
			grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
		} else if (down) {
			grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
		} else if (right) {
			grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
		} else if (left) {
			grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
		}
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	} else if (count > 1) { // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
		randomSelector = (rand() * 100) % count; // finds a random number w/ available count

		// number should at most have been 3 as count is 4, so checks to see which was selected
		// and moves the ant. A case should be selected because value above is being modded by the count
		switch (randomSelector) {
		case 0:
			if (up)
				grid[r - 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 1:
			if (down)
				grid[r + 1][c] = grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 2:
			if (right)
				grid[r][c + 1] = grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 3:
			if (left)
				grid[r][c - 1] = grid[r][c]; // assigns the current ant pointer to the new location
			break;
		default:
			break;
		}
		grid[r][c] = NULL; //resets the old space to be a null pointer now
	}
// if there are no free spaces the function exits without having moved the ant
	return ateAnt;
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
 *
 int* Doodlebug::enumerateNeighbors(Organism*** grid, int r, int c, int count, int nrows,
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
 }*/
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
		if (count == 1) {
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
		} else if (count > 1) { // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
			randomSelector = (rand() * 100) % count; // finds a random number w/ available count

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
	if(getTimeStepsSinceEaten() >= 3) // the doodle is starved and will die
	{
		delete grid[r][c]; // delete the doodlebug
		grid[r][c] = NULL; // set the old pointer to null
		return true;
	}
	return false;
}
/**
 * Returns how many time steps have passed since the doodlebug ate
 * @return the number of time steps that passed
 */
int Doodlebug::getTimeStepsSinceEaten(){
	return timeStepsSinceEaten;
}
/**
 * Sets the timeSteps to the passed in value
 * @param t The steps that are being set
 */
void Doodlebug::setTimeStepsSinceEaten(int t){
	timeStepsSinceEaten = t;
}
Doodlebug::~Doodlebug(){

}
