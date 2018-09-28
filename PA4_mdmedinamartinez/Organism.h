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
private:
	int canBreed; // keeps track of whether an organism is eligible to breed
	int preyStatus; // keeps track of whether an organism is prey, predator, or empty
	int numRow; // the current row location
	int numCol; // the current column location
	bool hasMoved; // whether an organism has moved in a given turn
public:
	int getPreyStatus();
	virtual void move(Organism** grid, int r, int c, int nrows, int ncols);
	int getRow();
	void setRow(int r);
	int getCol();
	void setCol(int c);
	int getCanBreed();
	void setCanBreed(int p);
	void setMoved(bool b);
	bool getMoved();
	Organism(); // default constructor
	virtual ~Organism(){}
	//~Organism();

protected:
	void setPreyStatus(int p);
	int* enumerateNeighbors(Organism*** grid, int r, int c, int count, int nrows,
				int cols); // array keeping track of the neighbors around the organism

};

#endif /* ORGANISM_H_ */
