/*
 * PA4.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: mdmedinamartinez
 */
#include <iostream>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Board.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {

	cout << "Welcome to Doodlebug Demise" << endl;

	// input command line arguments; defaults are initially included
	int nrows = 20; // Number of rows in the grid
	int ncols = 20; // Number of columns in the grid
	int doodlebugs = 5; // Number of doodlebugs in the program
	int ants = 100; // Number of ants in the program
	int timeSteps = 1000; // Number of time steps the program will take
	int seed = 1; // Number to be placed into the random function
	int doPause = 0; // Non-zero number to represent the number of time steps taken before pausing

	Board board; // Will hold the info about the game

	// Save the command line arguments
	// falls through switch b/c if has a high number of args, the rest are guaranteed
	switch (argc) {
	case 7:
		doPause = atoi(argv[6]); // Convert to integer
		if (doPause < 0) {
			cout << "Improper input." << endl;
			cout << "Only positive numbers allowed for generations." << endl;
			cout << "Default value: 0 - program will run, but will not pause."
					<< endl;
			doPause = 0; // reset to default if invalid input
		}
	case 6:
		seed = atoi(argv[5]); // Convert to integer
		if (seed < 0) {
			cout << "Improper input." << endl;
			cout << "Only positive numbers allowed for generations." << endl;
			cout << "Default value: 1 - program will run, but with default value."
					<< endl;
			seed = 1; // reset to default if invalid input
		}
	case 5:
		timeSteps = atoi(argv[4]); // Convert to integer
		if (timeSteps < 0) {
			cout << "Improper input." << endl;
			cout << "Only positive numbers allowed for generations." << endl;
			cout
					<< "Default value: 1000 - program will run, but with default value."
					<< endl;
			timeSteps = 1000; // reset to default if invalid input
		}
	case 4:
		ants = atoi(argv[3]); // Convert to integer
		if (ants < 0) {
			cout << "Improper input." << endl;
			cout << "Only positive numbers allowed for generations." << endl;
			cout << "Default value: 100 - program will run, but with default value."
					<< endl;
			ants = 100; // reset to default if invalid input
		}
	case 3:
		doodlebugs = atoi(argv[2]); // Converts to integer; falls through to other args
		if (doodlebugs < 0) {
			cout << "Improper input." << endl;
			cout << "Only positive numbers allowed for generations." << endl;
			cout << "Default value: 5 - program will run, but with default value."
					<< endl;
			doodlebugs = 5; // reset to default if invalid input
		}
	case 2:
		nrows = atoi(argv[1]); // Converts to integer
		ncols = nrows;
		if (nrows < 0) {
			cout << "Improper input." << endl;
			cout << "Only positive numbers allowed for generations." << endl;
			cout << "Default value: 20 - program will run, but with default value."
					<< endl;
			nrows = ncols = 20; // reset to default if invalid input
		}
		break;
	default:
		break;
	}

}

