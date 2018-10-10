/*
 * EventQueue.h
 *
 * Represented with a Linked List
 *
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez agarza
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include "Event.h"

struct eventNode{
	Event e; // holds data of current Event node
	eventNode* next;
};
class EventQueue {
private:
	eventNode* head; // head of the eventQueue
	eventNode* tail; // tail of the eventQueue;

public:
	void insertEvent(Event* e);
	void removeEvent(Event* e);
	EventQueue();
	~EventQueue();
};
// function to add event to the event queue in TIME order
	// iterates through list until finds event w time > than that of one being inserted
	// insert just before this
	// if time is same, new event goes after that event already in queue
	// possible it will become the new head

// function to remove an event from event queue and invoke action method (call it's action, call the events remove method



#endif /* EVENTQUEUE_H_ */
