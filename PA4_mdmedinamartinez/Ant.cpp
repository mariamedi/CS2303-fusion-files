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
 */
void Ant::move(Organism** grid, int r, int c) {
	// arrayof size 4 holding either 0 or 1 if it is a valid spot
	int count = 4; // size of the array to be returned

	// vars keep track if the given neighbors are unoccupied, true if they are
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;

	int randomSelector; // will hold the value of the random neighbor being selected

	int* neighbors = enumerateNeighbors(grid, r, c, count);
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
	}
	else if(count > 1){ // if > 1 then chooseRandomNeighbor(pass in the array and return a pointer to the right one in the grid)
		randomSelector = (rand() * 100) % count; // finds a random number w/ available count

		// number should at most have been 3 as count is 4, so checks to see which was selected
		// and moves the ant. A case should be selected because value above is being modded by the count
		switch(randomSelector){
		case 0:
			if(up)
				*grid[r - 1][c] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 1:
			if(down)
				*grid[r + 1][c] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 2:
			if(right)
				*grid[r][c + 1] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		case 3:
			if(left)
				*grid[r][c - 1] = *grid[r][c]; // assigns the current ant pointer to the new location
			break;
		default:
			break;
		}
		*grid[r][c] = (Organism*) NULL; //resets the old space to be a null pointer now
	}
	// if there are no free spaces the function exits without having moved the ant
}
void Ant::breedAnt(Organism** grid, Ant* ant) {

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
int* enumerateNeighbors(Organism** grid, int r, int c, int count) {
	int * neighbors = new int[count]; // creates an array


	return neighbors;
}
// destructor
Ant::~Ant() {
}

