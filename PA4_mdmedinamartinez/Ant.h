/*
 * Ant.h
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 *      Author: agarza
 */

#ifndef ANT_H_
#define ANT_H_
#include "Organism.h"

class Ant: public Organism {
private:
//	int* enumerateNeighbors(Organism*** grid, int r, int c, int count, int nrows,
	//		int cols); // array keeping track of the neighbors around the organism

public:
	void move(Organism*** grid, int r, int c, int nrows, int ncols);
	bool breedAnt(Organism*** grid, int r, int c, int nrows, int ncols);
	Ant(int row, int col);
	~Ant();
};

#endif /* ANT_H_ */
