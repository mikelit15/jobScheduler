/*
 * Request.hpp
 *
 *  Created on: May 11, 2022
 *      Author: Mike Litvin
 */

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
using namespace std;

class Request
{
public:

	int jobID;
	int devices;

	Request();
	Request(int j, int d);

	void setID(int j);
	void setDevices(int d);
	void add(Request *r);
	void updateRequest();
	void removeR(Request r);

	int getID();
	int getDevices();

	void popFirst(Request a);
	Request getRequest(Request f);



};


#endif /* REQUEST_HPP_ */
