/*
 * Ant.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 */
#include <iostream>
#include "Ant.h"

// constructor
Ant::Ant() {
}
/**
 * Takes a pointer to an ant in the grid and moves it according
 * to the provided rules. Randomly selects an unoccupied cell that's not off the
 * grid and moves the ant there.
 * @param grid The array holding the current game state
 * @param r The row index of the ant to be moved
 * @param c The column index of the ant to be moved
 * @param nrows The total number of rows in the grid
 * @param ncols The total number of columns in the grid
 */
void Ant::move(Organism** grid, int r, int c, int nrows, int ncols) {
	// arrayof size 4 holding either 0 or 1 if it is a valid spot
	int count = 4; // size of the array to be returned

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
	// movement depends on how many are unoccupied
	// if there is only one unoccupied neighbor, it looks for the free posiiton
	if (count == 1) {
		if (up) {
			*grid[r - 1][c] = *grid[r][c]; // assigns the current ant pointer to the new location
		} else if (down) {
			*grid[r + 1][c] = *grid[r][c]; // assigns the current ant pointer to the new location
		} else if (right) {
			*grid[r][c + 1] = *grid[r][c]; // assigns the current ant pointer to the new location
		} else if (left) {
			*grid[r][c - 1] = *grid[r][c]; // assigns the current ant pointer to the new location
		}
		*grid[r][c] = (Organism*) NULL; //resets the old space to be a null pointer now
	} else if (count > 1) { // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
		randomSelector = (rand() * 100) % count; // finds a random number w/ available count

		// number should at most have been 3 as count is 4, so checks to see which was selected
		// and moves the ant. A case should be selected because value above is being modded by the count
		switch (randomSelector) {
		case 0:
			if (up)
				*grid[r - 1][c] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 1:
			if (down)
				*grid[r + 1][c] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 2:
			if (right)
				*grid[r][c + 1] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 3:
			if (left)
				*grid[r][c - 1] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		default:
			break;
		}
		*grid[r][c] = (Organism*) NULL; //resets the old space to be a null pointer now
	}
	// if there are no free spaces the function exits without having moved the ant
}
/**
 * If an ant has survived for three time steps, it is eligible to breed. Method checks
 * eligibility and spawns new ant in an unoccupied cell. If there is no free cell, the
 * ant still remains eligible to spawn. If it spawns, the time step counter for
 * breeding is reset. This function is for a single ant.
 * @param grid The array holding the current game state
 * @param r The row index of the ant to be bred
 * @param c The column index of the ant to be bred
 * @param nrows The total number of rows in the grid
 * @param ncols The total number of columns in the grid
 * @return True if an ant was spawned, false if not, used to keep track of total ants
 */
bool Ant::breedAnt(Organism** grid, int r, int c, int nrows, int ncols) {

	// checks to see if ant has been alive for at least 3 time steps
	if (getCanBreed >= 3) { // take steps to see if an ant has space to spawn as it is eligible
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
				*grid[r - 1][c] = new Ant(); // assigns the located pointer to a new ant
			} else if (down) {
				*grid[r + 1][c] = new Ant(); // assigns the located pointer to a new ant
			} else if (right) {
				*grid[r][c + 1] = new Ant(); // assigns the located pointer to a new ant
			} else if (left) {
				*grid[r][c - 1] = new Ant(); // assigns the located pointer to a new ant
			}
			setCanBreed(); // resets this ant's breed count
			return true; // successfully spawned a new ant
		} else if (count > 1) { // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
			randomSelector = (rand() * 100) % count; // finds a random number w/ available count

			// number should at most have been 3 as count is 4, so checks to see which was selected
			// and spawns an ant. A case should be selected because value above is being modded by the count
			switch (randomSelector) {
			case 0:
				if (up)
					*grid[r - 1][c] = new Ant(); // assigns the located pointer to a new ant
				break;
			case 1:
				if (down)
					*grid[r + 1][c] = new Ant(); // assigns the located pointer to a new ant
				break;
			case 2:
				if (right)
					*grid[r][c + 1] = new Ant(); // assigns the located pointer to a new ant
				break;
			case 3:
				if (left)
					*grid[r][c - 1] = new Ant(); // assigns the located pointer to a new ant
				break;
			default:
				break;
			}
			setCanBreed(); // resets the ants breed count
			return true; // successfully spawned a new ant
		}
	}
	return false; // no ant was spawned during the existence of this function
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
int* enumerateNeighbors(Organism** grid, int r, int c, int count, int nrows,
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
			&& grid[r][c + 1] == NULL)
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
// destructor
Ant::~Ant() {
}

