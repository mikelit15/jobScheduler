/*
 * ReadyQueue.cpp
 *
 *  Created on: May 10, 2022
 *      Author: paf00
 */

#include "ReadyQueue.hpp"

void ReadyQueue::add(Job *job) {
    queue.push_back(*job);
}

void ReadyQueue::printQueue()
{
    list<Job>::iterator it;
    for (it = queue.begin(); it != queue.end(); ++it) {
        cout << "   " << it->getID() << "\t\t   " << it->getRunTime()
        		<< "\t\t     "  << it->getTimeAccrued() << endl;
    }
}

bool ReadyQueue::isEmpty()
{
	return !queue.empty();
}

Job ReadyQueue::processNextJob()
{
	Job a;
	if(!queue.empty())
	{
		Job frontItem = queue.front();
		queue.pop_front();
		a = frontItem;
	}
	return a;
}




