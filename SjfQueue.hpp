/*
 * SjfQueue.hpp
 *
 *  Created on: May 10, 2022
 *      Author: cheat
 */

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
using namespace std;

class SjfQueue {
private:
public:
	list<Job> queue;
	void add(Job* job);
	Job getFirst();
	Job popFirst();
	void printQueue();
};
