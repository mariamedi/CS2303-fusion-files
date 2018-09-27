/*
 * Organism.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: mdmedinamartinez
 */
#include "Organism.h"

// constructor
Organism::Organism()
{
	preyStatus = 0; // default value
	canBreed = 0; // no time steps have passed
} // Organism Constructor
/**
 * Getter for the prey status variable holding what kind of organism it is
 * @return 0 if neither prey/predator, 1 if prey, 2 if predator
 */
int Organism::getPreyStatus(){
	return preyStatus;
}
/**
 * Protected method only available to derived classes of organism.
 * Used when creating a particular instance of an Organism to change
 * its preyStatus.
 */
void Organism::setPreyStatus(int p){
	preyStatus = p;
}
/**
 * Resets the breeding steps if the organism has just bred
 */
void Organism::setCanBreed(){
	canBreed = 0;
}
// destructor
Organism::~Organism() {
	// delete dynamically allocated things
}
