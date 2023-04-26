/*
 * CPU.cpp
 *
 *  Created on: May 10, 2022
 *      Author: paf00
 */


#include "CPU.hpp"
#include "Request.hpp"

CPU::CPU() {
	Job *currJob = new Job();
	currJob = new Job(0, 0, 0, 0, 0, 0);
}

void CPU::newJob(Job job, System sys, int curr_time) {
    //Initialize job start time:
    jobStartTime = curr_time;
    //Initialize remaining allocated execution time for job:
    if (job.getTimeLeft() <= sys.getQuantum()){
        qTimeLeft = job.getTimeLeft();
    }
    else {
        qTimeLeft = sys.quantum;
    }
    //Initialize currJob:
    currJob = job;
    // Initialize the static time at which the task of the cpu ends.
    jobEndTime = qTimeLeft;

    // So what do these member fields represent?
    // jobStartTime: the time interval at which the cpu began working on task
    // qTimeLeft: an integer (1 to time quantum) of time left before cpu stops working on task
    // currJob: The current job that's being worked on by the CPU
}

//void CPU::updateRemainingJobTime(int curr_time){
//	// Remaining time left for alloted task on cpu:
//	qTimeLeft = jobEndTime - curr_time;
//	// Also modify the remaining time on the currJob:
//	currJob.setTimeLeft(jobEndTime - curr_time);
//}
void CPU::processCPU() {
	// "1" Represents the amount of time worked on the task for

	qTimeLeft -= 1;
	currJob.setTimeLeft(1);
}

Job CPU::oldJob()
{
    return currJob;
}

int CPU::getEndTime() {
    return jobEndTime;
}

void CPU::printCPU()
{
	if(!currJob.getID() == 0)
	{
		cout << "   " << currJob.getID() << "\t\t   " << currJob.getTimeAccrued() << "\t\t    " << currJob.getTimeLeft() << endl;
	}
}
