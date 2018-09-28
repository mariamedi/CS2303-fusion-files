/*
 * Doodlebug.h
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_
#include "Organism.h"

class Doodlebug: public Organism{
private:
	//int* enumerateNeighbors(Organism*** grid, int r, int c, int count, int nrows, int cols); // array keeping track of the neighbors around the organism
	int timeStepsSinceEaten;
public:
	bool move(Organism*** grid, int r, int c, int nrows, int ncols);
	bool breedDoodle(Organism*** grid, int r, int c, int nrows, int ncols);
	bool checkStarvation(Organism*** grid, int r, int c);
	int getTimeStepsSinceEaten();
	void setTimeStepsSinceEaten(int t);
	Doodlebug(int row, int col);
	~Doodlebug();
};




#endif /* DOODLEBUG_H_ */
