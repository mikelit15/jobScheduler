/*
 * Request.cpp
 *
 *  Created on: May 11, 2022
 *      Author: Mike Litvin
 */

#include "Request.hpp"

Request::Request()
{
	jobID = 0;
	devices = 0;
}

Request::Request(int j, int d)
{
	jobID = j;
	devices = d;
}

void Request::setID(int j)
{
	jobID = j;
}

void Request::setDevices(int d)
{
	devices = d;
}

int Request::getID()
{
	return jobID;
}

int Request::getDevices()
{
	return devices;
}

Request Request::getRequest(Request r)
{
	return r;
}

//void Request::popFirst(Request r)
//{
//	cout << "popping : " << r.getID() << endl;
//	requests.splice(requests.end(),
//	                 requests,
//	                 requests.begin());
//    requests.pop_front();
//}
//
//void Request::removeR(Request r)
//{
//	requests.remove(r);
//}
//
//void Request::add(Request *req) {
//	requests.push_back(*req);
//}






