/*
 * Event.h
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez agarza
 */

#ifndef EVENT_H_
#define EVENT_H_
#include "EventQueue.h"
class Event {
private:
	bool isCustomerEvent; // keeps track of whether it is Teller or Customer Event

public:
	bool insert(EventQueue* e, Event* e);
	bool remove(EventQueue* e, Event* e);
	virtual void action(Event* e);
	Event();
	virtual ~Event();
};
// function to insert into event queue

// function to remove from event queue

// function to perform action ; overriden in children



#endif /* EVENT_H_ */
