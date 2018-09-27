/*
 * Ant.h
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 */

#ifndef ANT_H_
#define ANT_H_
#include "Organism.h"

class Ant: public Organism{
public:
	void move(Organism** grid, Ant* ant);
	void breedAnt(Organism** grid, Ant* ant);
	Ant();
	~Ant();
private:
	int* enumerateNeighbors(Organism** grid, int r, int c); // array keeping track of the neighbors around the organism
	Organism* chooseRandomNeighbor(Organism** grid, int r, int c);
	bool checkIfAllOccupied(Organism* org_array); // checks to see if all the neighbors are taken up by organism
};

#endif /* ANT_H_ */
