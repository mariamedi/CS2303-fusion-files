/*
 * Board.h
 *
 *  Created on: Sep 27, 2018
 *      Author: mdmedinamartinez
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "twoD.h"

class Board {
public:
	void playRound();
	int getSteps();
	void printBoard();
	int checkTermination();
	void printEnd(int argc, char** argv);
   // void decreaseAnts();
	Board(int rows, int cols, int ants, int doodles, int seed);
	~Board();
private:
	int nrows; // Number of rows in the board
	int ncols; // Number of cols in the board
	int terminatingCondition; // Keeps track of reason of game termination
	int completedTimeSteps; // Number of time steps taken
	int countDoodles; // Number of doodlebugs currently in the grid
	int countAnts; // Number of ants currently in the game
	int totalAnts; // The total number of ants that existed over course of simulation
	int totalDoodles; // The total number of doodles that existed over the course of the simulation
	int seed; // The seed passed in by the user or default
	// 2D arrays used to play the game
	Organism ***gridA; // holds the current time step grid
	//Organism **gridB; // will hold the new time step grid

	Organism* getPointer(int r, int c);
	int checkIfPrey(Organism** o);
	bool checkBounds(int r, int c);
    void initializeGameBoard(int seed);

};

#endif /* BOARD_H_ */
