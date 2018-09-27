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
		// add other mehthods relevant to an organism
		// move method to have bounds checking
		bool isPrey();
		Organism(bool p);
		~Organism();

	private:
		// add variables
		bool preyStatus;
};





#endif /* ORGANISM_H_ */
