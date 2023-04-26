/*
 * WaitQueue.cpp
 *
 *  Created on: May 18, 2022
 *      Author: paf00
 */

#include "WaitQueue.hpp"

void WaitQueue::add(Job *job) {
	queue.push_back(*job);
}
void WaitQueue::printQueue() {
    list<Job>::iterator it;
    for (it = queue.begin(); it != queue.end(); ++it) {
        cout << "   " << it->getID() << "\t\t   " << it->getRunTime()
        		<< "\t\t     "  << it->getTimeLeft() << endl;
    }
}

void WaitQueue::popFirst(Job r)
{
	queue.push_front(r);
    queue.pop_front();
}

Job WaitQueue::getFirstJob() {
	return queue.front();
}

bool WaitQueue::isEmpty()
{
	return !queue.empty();
}

