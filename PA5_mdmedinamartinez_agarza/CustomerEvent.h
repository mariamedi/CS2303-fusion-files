/*
 * CustomerEvent.h
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez agarza
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_
#include "Event.h"
#include "Customer.h"

class CustomerEvent: public Event {
private:
	int arrivalTime; // keep track of when the given Customer arrived
	int completionTime; // keep track of when the Customer was serviced
	bool justArrived;
	bool serviceCompleted;
	Customer c; // Customer being represented by this event
public:
	void action(Event* e);
	CustomerEvent();
	~CustomerEvent();
};



#endif /* CUSTOMEREVENT_H_ */
