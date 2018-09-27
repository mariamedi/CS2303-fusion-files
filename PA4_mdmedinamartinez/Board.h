/*
 * Board.h
 *
 *  Created on: Sep 27, 2018
 *      Author: mdmedinamartinez
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>

class Board {
public:
	void playRound();
	int getSteps();
	void printBoard();
	int checkTermination();
	void printEnd();
private:
	int nrows; // Number of rows in the board
	int ncols; // Number of cols in the board
	int terminatingCondition; // Keeps track of reason of game termination
	int completedTimeSteps; // Number of time steps taken
	int countDoodles; // Number of doodlebugs currently in the grid
	int countAnts; // Number of ants currently in the game

	// 2D arrays used to play the game
	Organism **gridA; // holds the current time step grid
	Organism **gridB; // will hold the new time step grid

	Organism* getPointer();
	bool checkIfPrey(int r, int c);

};

#endif /* BOARD_H_ */
