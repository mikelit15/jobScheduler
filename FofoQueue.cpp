/*
 * FofoQueue.cpp
 *
 *  Created on: May 10, 2022
 *      Author: paf00
 */

#include "FofoQueue.hpp"
#include "Job.hpp"
#include <iterator>

void FofoQueue::add(Job* job)
{
    queue.push_back(*job);
}

Job FofoQueue::getFirst()
{
    return queue.front();
}

Job FofoQueue::popFirst()
{
    Job frontitem = queue.front();
    queue.pop_front();
    return frontitem;
}

void FofoQueue::printQueue()
{
    list<Job>::iterator it;
    for (it = queue.begin(); it != queue.end(); ++it) {
        cout << "   " << it->getID() << "\t\t   " << it->getRunTime() << endl;
    }
}
