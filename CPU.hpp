/*
 * CPU.hpp
 *
 *      Author: paf00
 */

#ifndef CPU_HPP_
#define CPU_HPP_

#include "System.hpp"
#include <iostream>
#include <stdlib.h>
#include <list>
#include "Job.hpp"
using namespace std;


class CPU{
private:

public:
	Job currJob;
	int qTimeLeft;
	int jobStartTime;
	int jobEndTime;
	void newJob(Job job, System sys, int curr_time);
	void processCPU();
//	void updateRemainingJobTime(int curr_time);
	Job oldJob();
	int getEndTime();
	void printCPU();

	CPU();
};



#endif /* CPU_HPP_ */
