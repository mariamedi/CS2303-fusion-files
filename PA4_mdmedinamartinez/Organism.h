/*
 * Organism.h
 *	The parent class for both an Ant and Doodlebug
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <iostream>

class Organism {
public:
	int getPreyStatus();
	virtual void move(Organism** grid, int r, int c, int nrows, int ncols);
	Organism(); // default constructor
	~Organism();

protected:
	int getCanBreed();
	void setPreyStatus(int p);
	void setCanBreed();

private:
	int canBreed; // keeps track of whether an organism is eligible to breed
	int preyStatus; // keeps track of whether an organism is prey, predator, or empty
};

#endif /* ORGANISM_H_ */
