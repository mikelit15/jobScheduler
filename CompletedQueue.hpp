/*
 * CompletedQueue.hpp
 *
 *  Created on: May 11, 2022
 *      Author: paf00
 */

#ifndef COMPLETEDQUEUE_HPP_
#define COMPLETEDQUEUE_HPP_

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
using namespace std;


class CompletedQueue {
private:

public:
	list<Job> queue;
	void printQueue();
	void add(Job *job);




};



#endif /* COMPLETEDQUEUE_HPP_ */
