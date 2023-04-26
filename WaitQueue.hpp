/*
 * WaitQueue.hpp
 *
 *  Created on: May 18, 2022
 *      Author: paf00
 */

#ifndef WAITQUEUE_HPP_
#define WAITQUEUE_HPP_

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
#include "System.hpp"
#include "ReadyQueue.hpp"
using namespace std;


class WaitQueue {
private:

public:
	list<Job> queue;
	void add(Job *job);
	void printQueue();
	void popFirst(Job a);
	Job getFirstJob();
	bool isEmpty();
	void ProcessWaitQueue(System sys, ReadyQueue rQueue);
};



#endif /* WAITQUEUE_HPP_ */
