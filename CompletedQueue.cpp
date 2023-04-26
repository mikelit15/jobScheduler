/*
 * CompletedQueue.cpp
 *
 *  Created on: May 11, 2022
 *      Author: paf00
 */

#include "CompletedQueue.hpp"

void CompletedQueue::add(Job *job)
{
    queue.push_back(*job);
	queue.sort([](Job &f, Job &s)
	{
		return f.ID < s.ID;
	});
}

void CompletedQueue::printQueue()
{
    list<Job>::iterator it;
    for (it = queue.begin(); it != queue.end(); ++it)
    {
        cout << "   " << it->getID() << "                  " << it->getArrivalTime() << "                 "
        		"  " << it->getFinishTime() << "                   " << it->getTurnAround()<< endl;
    }
}

