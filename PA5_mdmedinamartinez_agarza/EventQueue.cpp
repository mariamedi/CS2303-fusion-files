/*
 * EventQueue.cpp
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez agarza

 */
#include <iostream>
#include "EventQueue.h"

EventQueue::EventQueue(){
	// sets both head and tail to null to begin with
	head = NULL;
	tail = NULL;
}
/**
 * Take the input event and inserts it into the queue
 * according to the time of its action. If it is the first
 * event into the queue it is set to head. If it is the last
 * event, then it becomes the tail. Else, it is inserted into the
 * middle of the queue.
 * @param e Pointer to the Event being added into the queue
 */
void EventQueue::insertEvent(Event* e){
	// create a node of the event
	eventNode* temp = new eventNode();
	temp->*e = e;
	temp->next = NULL;

	// if there head is NULL
	if(head == NULL){
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else if()


}



