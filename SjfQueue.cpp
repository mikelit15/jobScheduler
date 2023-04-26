/*
 * SjfQueue.cpp
 *
 *  Created on: May 10, 2022
 *      Author: paf00
 */

#include "SjfQueue.hpp"


void SjfQueue::add(Job* job) {
    if (queue.empty() == true) {
        queue.push_back(*job);
    } else {
        list<Job>::iterator it;
        for (it = queue.begin(); it != queue.end(); ++it) {
            if (it->getRunTime() > job->getRunTime()) {
                queue.insert(it, *job);
                break;
            }
        }
        // job has the biggest runtime, insert at end of list
        queue.push_back(*job);
    }
}


Job SjfQueue::getFirst() {
	return queue.front();
}
Job SjfQueue::popFirst() {
	Job frontitem = queue.front();
	queue.pop_front();
	return frontitem;
}
void SjfQueue::printQueue()
{
    list<Job>::iterator it;
    for (it = queue.begin(); it != queue.end(); ++it) {
        cout << "   " << it->getID() << "\t\t   " << it->getRunTime() << endl;
    }
}
