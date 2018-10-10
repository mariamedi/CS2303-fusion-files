/*
 * TellerEvent.h
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_
#include "Event.h"
#include "Teller.h"
class TellerEvent: public Event{
private:
	bool serviceCompleted; // keeps track if a customer was just serviced
	bool completedBreak; // keeps track of whether a break was just completed
	Teller t; // teller being represented
public:
	void action(Event* e); // do we need to pass in EventQueue?
	TellerEvent();
	~TellerEvent();
};




#endif /* TELLEREVENT_H_ */
