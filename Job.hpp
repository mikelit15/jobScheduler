/*
 * Job.hpp
 *
 * Created on: May 10, 2022
 * Author: Mike Litvin
 */

#ifndef JOB_HPP_
#define JOB_HPP_

#include <iostream>
#include <stdlib.h>
using namespace std;

class Job
{
public:
	int ID;
	int memory;
	int devices;
	int arrivalTime;
	int finishTime;
	int turnAround;
	int timeLeft = 0;
	int runTime;
	int priority;
	int release;

	Job();
//
	Job(int arriv, int id, int mem, int dev, int run, int prio);
//
//	Job(int arrivalTime, int ID, int devices);
//
//	Job(int arrivalTime, int ID, int release);

	int getArrivalTime();
	int getFinishTime();
	int getTurnAround();
	int getTimeLeft();
	int getPriority();
	int getID();
	int getMemory();
	int getDevices();
	int getRunTime();
	bool getCompleted();
	int getTimeAccrued();

	void setArrivalTime(int t);
	void setID(int i);
	void setDevices(int d);
	void setMemory(int m);
	void setPriority(int p);
	void setTimeLeft(int r);
	void setFinishTime(int f);
	void addNewDevices(int d);
};

#endif

