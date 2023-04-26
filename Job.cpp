/*
 * Job.cpp
 *
 * Created on: May 10, 2022
 * Author: Mike Litvin
 */

#include "Job.hpp"

/**
 * Default constructor for a job object
 *
 * @author Mike Litvin
 */
Job::Job()
{
	ID = 0;
	arrivalTime = 0;
	priority = 0;
	devices = 0;
	memory = 0;
	runTime = 0;
}

/**
 * Parameterized constructor for a job object
 *
 * @author Mike Litvin
 */
Job::Job(int arriv, int id, int mem, int dev, int run, int prio)
{
	ID = id;
	arrivalTime = arriv;
	priority = prio;
	devices = dev;
	memory = mem;
	runTime = run;
	timeLeft = run;
}

/**
 * Getter for the arrival time of a job
 *
 * @return int - arrival time
 * @author Mike Litvin
 */
int Job::getArrivalTime()
{
	return arrivalTime;
}

/**
 * Getter for the finish time of a job
 *
 * @return int - finish time
 * @author Mike Litvin
 */
int Job::getFinishTime()
{
	return finishTime;
}

/**
 * Getter for the turnaround time of a job
 *
 * @return int - turn around time
 * @author Mike Litvin
 */
int Job::getTurnAround()
{
	return turnAround;
}

/**
 * Getter for the time left of a job
 *
 * @return int - time left
 * @author Mike Litvin
 */
int Job::getTimeLeft()
{
	return timeLeft;
}

/**
 * Getter for the priority of a job
 *
 * @return int - priority
 * @author Mike Litvin
 */
int Job::getPriority()
{
	return priority;
}

/**
 * Getter for the ID of a job
 *
 * @return int - ID
 * @author Mike Litvin
 */
int Job::getID()
{
	return ID;
}

/**
 * Getter for the memory that the job requires
 *
 * @return int - memory amount
 * @author Mike Litvin
 */
int Job::getMemory()
{
	return memory;
}

/**
 * Getter for the devices that the job requires
 *
 * @return int - devices amount
 * @author Mike Litvin
 */
int Job::getDevices()
{
	return devices;
}

/**
 * Getter for the run time of a job
 *
 * @return int - run time
 * @author Mike Litvin
 */
int Job::getRunTime()
{
	return runTime;
}

/**
 * Setter for the arrival time of a job
 *
 * @return int - time left
 * @author Mike Litvin
 */
void Job::setTimeLeft(int r)
{
	timeLeft -= r;
}

void Job::setFinishTime(int f)
{
	finishTime = f;
	turnAround = finishTime - arrivalTime;
}

void Job::addNewDevices(int d) {
	devices = d;
}

int Job::getTimeAccrued()
{
	return getRunTime() - getTimeLeft();
}






