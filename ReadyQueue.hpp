/*
 * ReadyQueue.hpp
 *
 *  Created on: May 10, 2022
 *      Author: paf00
 */

#ifndef READYQUEUE_HPP_
#define READYQUEUE_HPP_

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
using namespace std;


class ReadyQueue {
private:

public:
	list<Job> queue;
	void add(Job *job);
	void printQueue();
	Job processNextJob();
	bool isEmpty();

};


#endif /* READYQUEUE_HPP_ */
