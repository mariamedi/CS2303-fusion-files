/*
 * qSim.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez agarza
 *
 * ./qSim #customers #tellers simulationTime averageServiceTime <seed>
 */

#include <iostream>
#include "EventQueue.h"
#include "TellerQueue.h"
#include "Customer.h"
#include "Teller.h"
#include "CustomerEvent.h"
#include "TellerEvent.h"
#include "Event.h"
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv) {
	cout << "Welcome to our Simulation" << endl;

	// constants
	const int DEF_CUSTOMERS = 10; // default customer number
	const int DEF_TELLERS = 3; // default teller numbers
	const float DEF_SIM_TIME = 60; // default sim time
	const float DEF_AVG_SERV = 2; // default avg service time
	const unsigned int DEF_SEED = time(NULL); // default random time

	// input command line arguments
	int customers; // specified customer amounts
	int tellers; // specified teller amounts
	float simTime; // specified simulation time in minutes
	float avgServiceTime; // average time it takes for customer to be serviced
	unsigned int seed; // random num seed; if not specified used time(NULL)

	// save the command line args
	customers = atoi(argv[1]);
	if (customers < 0) {
		cout << "Improper input. Customers should be > 0." << endl;
		cout << "Program will run w/ default value of " << DEF_CUSTOMERS << "."
				<< endl;
		customers = DEF_CUSTOMERS; // set to default
	}
	tellers = atoi(argv[2]);
	if (tellers < 0) {
		cout << "Improper input. Tellers should be > 0." << endl;
		cout << "Program will run w/ default value of " << DEF_TELLERS << "."
				<< endl;
		tellers = DEF_TELLERS; // set to default
	}
	simTime = atof(argv[3]);
	if (simTime < 0) {
		cout << "Improper input. Simulation time should be > 0." << endl;
		cout << "Program will run w/ default value of " << DEF_SIM_TIME << "."
				<< endl;
		simTime = DEF_SIM_TIME; // set to default
	}
	avgServiceTime = atof(argv[4]);
	if (avgServiceTime < 0) {
		cout << "Improper input. Average service time should be > 0." << endl;
		cout << "Program will run w/ default value of " << DEF_AVG_SERV << endl;
		avgServiceTime = DEF_AVG_SERV; // set to default
	}
	if (argc == 6) {
		seed = atoi(argv[5]);
		if (seed < 0) {
			cout << "Improper input. Seed should be greater > 0." << endl;
			cout << "Program will run w/ default value of" << DEF_SEED << "." << endl;

			seed = DEF_SEED; // reset to default if invalid input
		}
	}

	// Create an event queue to hold all events
	//EventQueue events = new EventQueue();

	// set all of the following in a function to run the sim w/ certain number of tellers
		// have function return total time

	//first call w/ n tellers
		// Create necessary CustomerEvents and Customers
			// Each CustomerEvent HAS-A Customer that action will be performed on
		// insert CustomerEvents into Event Queue w/ EventQueue insert method

		// Create necessary TellerEvents and Tellers
			// Each TellerEvent HAS-A Teller that action will be performed on
		// insert TellerEvents into Event Queue w/ Event Queue insert method

		// WHILE the EventQueue still has Events:
			// Remove first Event, and advance clock to it
			// perform the action of the Event w/ Event action method (P o l y m o r p h i s m )
				// TellerQueues will be created in this function to hold the lines of Customers

	// second call w/ 1 teller
		// have function return total time

	// compare the resulting times


	return 1;
}

