/*
 * Customer.h
 *
 *  Created on: Oct 9, 2018
 *      Author: mdmedinamartinez agarza
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
class Customer {
private:
	int arrivalTime; // time they arrived at the bank
	int completionTIme; // time they were finished being serviced
public:
	Customer();
	~Customer();
};
#endif /* CUSTOMER_H_ */
