/*
 * FofoQueue.hpp
 *
 *  Created on: May 10, 2022
 *      Author: paf00
 */


#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
using namespace std;

class FofoQueue {
public:
	list<Job> queue;
	void add(Job *j);
	Job getFirst();
	Job popFirst();
	void printQueue();
};



