/*
 * main.cpp
 *
 * Created on: May 10, 2022
 * Author: Mike Litvin and Zachary Golpira
 *
 * Main class that handles input from textfile
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "System.hpp"
#include "Job.hpp"
#include <list>
#include <vector>
#include <algorithm>
#include "FofoQueue.hpp"
#include "SjfQueue.hpp"
#include "ReadyQueue.hpp"
#include "CPU.hpp"
#include "CompletedQueue.hpp"
#include "WaitQueue.hpp"
#include "Request.hpp"

using namespace std;

string line;
ifstream file("i2.txt");
FofoQueue* hQueue2 = new FofoQueue();
SjfQueue* hQueue1 = new SjfQueue();
ReadyQueue* rQueue = new ReadyQueue();
CompletedQueue* cQueue = new CompletedQueue();
WaitQueue* wQueue = new WaitQueue();
Request req;
list<Request> requestss;
CPU *cpu = new CPU();
Job process;
double totalSys = 0.0;
double totalJobs = 0.0;
bool sysFlag = false;
bool disFlag = false;
bool reqFlag = false;
System sys;

/**
 * Get nextJob function that creates a new Job object and inserts it into the
 * appropriate queue.
 *
 * @author Mike
 */
void getNextJob()
{
	string word = "";
	int count = 0;
	string slime[100];
	for (auto x : line)
	{
		if(x == ' ' || x == '=')
		{
			slime[count] = word;
			count++;
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	slime[count] = word;
	int aTime = stoi(slime[1]);
	int ID = stoi(slime[3]);
	int mem = stoi(slime[5]);
	int dev = stoi(slime[7]);
	int run = stoi(slime[9]);
	int prio = stoi(slime[11]);
	Job *j = new Job(aTime, ID, mem, dev, run, prio);
	if(mem < sys.getMemorySpace() && dev < sys.getDevices())
	{
		if(mem > sys.getAvailableMemory() || dev > sys.getAvailableDevices())
		{
			if(prio == 1)
			{
				hQueue1->add(j);
			}
			else
			{
				hQueue2->add(j);
			}
		}
		else
		{
			rQueue->add(j);
			sys.setAvailableMemory(mem);
//			sys.setAvailableDevices(dev);
		}
	}
}

/**
 * Create system function that sets up the system configuration based on the
 * input from the text file.
 *
 * @author Mike Litvin
 */
void createSystem()
{
	string slime[100];
	int count = 0;
	string word = "";
	for (auto x : line)
	{
		if(x == ' ' || x == '=')
		{
			slime[count] = word;
			count++;
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	slime[count] = word;
	int m = stoi(slime[3]);
	int d = stoi(slime[5]);
	int q = stoi(slime[7]);
	sys.setMemorySpace(m);
	sys.setDevices(d);
	sys.setQuantum(q);
}


void releaseDevice()
{
	string slime[100];
	int count = 0;
	string word = "";
	for (auto x : line)
	{
		if(x == ' ' || x == '=')
		{
			slime[count] = word;
			count++;
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	slime[count] = word;
	int a = stoi(slime[1]);
	int j = stoi(slime[3]);
	int d = stoi(slime[5]);

//	if (cpu->currJob.getID() == j) {
//		// Release Devices from cpu_job:
//		sys.setAvailableDevices(-1 * d);
//		cpu->oldJob().addNewDevices(-1 * d);
//		// Move any Jobs from Wait Queue to Ready Queue:
////		wQueue->ProcessWaitQueue(*sys, *rQueue);
//		if (wQueue->isEmpty() == false) {
//			list<Job>::iterator it;
//			for (it = wQueue->queue.begin(); it != wQueue->queue.end(); ++it)
//			{
//				if ((sys.getAvailableDevices() >= it->getDevices()) && sys.getAvailableMemory() >= it->getMemory())
//				{
//					Job *movingJob = new Job();
//					*movingJob = *it;
//					sys.setDevices(it->getDevices());
//					sys.setAvailableMemory(it->getMemory());
//					rQueue->add(movingJob);
//					it = wQueue->queue.erase(it);
//				}
//			}
//		}
//	}
}

/**
 * Request device function that handles the requests a job makes for more devices
 * when it is in the CPU.
 *
 * @author Mike Litvin
 */
void requestDevice()
{
	string slime[100];
	int count = 0;
	string word = "";
	for (auto x : line)
	{
		if(x == ' ' || x == '=')
		{
			slime[count] = word;
			count++;
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	slime[count] = word;
	int a = stoi(slime[1]);
	int j = stoi(slime[3]);
	int d = stoi(slime[5]);
	Request *r = new Request(j, d);
	requestss.push_back(*r);
}

/**
 * Display status function that will display the system status when it is called
 * from the text file.
 *
 * @author Mike Litvin
 */
void displayStatus()
{
	string slime[100];
	int count = 0;
	string word = "";
	for (auto x : line)
	{
		if(x == ' ' || x == '=')
		{
			slime[count] = word;
			count++;
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
	slime[count] = word;
	int a = stoi(slime[1]);

	cout << "At time " << a << ":" <<endl;
	cout << "Current Available Main Memory = " << sys.getAvailableMemory() << endl;
	cout << "Current Devices = " << sys.getDevices() << endl;
	cout << "Completed Jobs:" << endl;
	cout << "------------------------------------------"
			"-----------------------------" << endl;
	cout << "Job ID		Arrival Time		Finish		Turnaround Time" << endl;
	cout << "=========================================="
			"=============================" << endl;
	cQueue->printQueue();
	cout << '\n' << "Hold Queue 1:" << endl;
	cout << "------------------------" << endl;
	cout << "Job ID		Run Time" << endl;
	cout << "========================" << endl;
	hQueue1->printQueue();
	cout << '\n' << "Hold Queue 2:" << endl;
	cout << "------------------------" << endl;
	cout << "Job ID		Run Time" << endl;
	cout << "========================" << endl;
	hQueue2->printQueue();
	cout << '\n' << "Ready Queue:" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Job ID		Run Time	Time Accrued" << endl;
	cout << "============================================" << endl;
	rQueue->printQueue();
	cout << '\n' << "Process running on CPU:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Job ID	      Time Accrued	Time Left" << endl;
	cout << "=========================================" << endl;
	cpu->printCPU();
	cout << '\n' << "Wait Queue:" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Job ID		Run Time	Time Accrued" << endl;
	cout << "============================================" << endl;
	wQueue->printQueue();
	if(sysFlag)
	{
		double sysTurnaround = totalSys/totalJobs;
		cout << '\n' << "System Turnaround Time: " << sysTurnaround;
	}
	cout << '\n' <<endl;
}

/**
 * Get next line funtion that gets the next line in the text file and calls the
 * appropriate helper function based on the first letter of the line.
 *
 * @author Mike Litvin
 */
void getNextLine()
{
	if(line[0] == 'A')
	{
		getNextJob();
	}
	else if(line[0] == 'C')
	{
		createSystem();
	}
	else if(line[0] == 'Q')
	{
		requestDevice();
	}
	else if(line[0] == 'L')
	{
		releaseDevice();
	}
	else if(line[0] == 'D')
	{
		disFlag = true;
	}
}

void fetchLine()
{
	std::getline(file, line);
}


void updateReadyQueue()
{
	if(rQueue->isEmpty())
	{
		process = (rQueue->processNextJob());
		cpu->newJob(process, sys, process.getArrivalTime());
	}
}


/**
 * Main function used to run the program
 *
 * @author Mike Litvin
 */
int main()
{
    string lines = "";
    int numLines = 0;
    if(file.is_open())
	{
        while(!file.eof()){
            getline(file,lines);
            numLines++;
        }
    }
    file.seekg(0);
    bool flag = true;
    bool flag2 = true;
    int arriv = 0;
    int lCount = 0;

    for(int curr_time = 0; lCount < numLines; curr_time++)
    {
    	sys.setTime(curr_time);
        string word = "";
        int count = 0;
        string slime[100];

        if(flag)
        {
            fetchLine();
            for (auto x : line)
            {
                if(isdigit(x))
                {
                    word = word + x;
                }
                else
                {
                    slime[count] = word;
                    count++;
                    word = "";
                }
            }
            slime[count] = word;
            flag = false;
            arriv = stoi(slime[2]);
    		if (arriv == 9999)
    		{
    			sysFlag = true;
    		}
        }
        if(rQueue->isEmpty() && flag2)
        {
        	updateReadyQueue();
        	flag2 = false;
        }

		if (cpu->oldJob().getID() != 0)
		 {
			if(wQueue->getFirstJob().getMemory() <= sys.getAvailableMemory() && wQueue->getFirstJob().getDevices() <= sys.getAvailableDevices())
			{
				if (wQueue->isEmpty() == true)
				{
					list<Job>::iterator it;
					for (it = wQueue->queue.begin(); it != wQueue->queue.end(); ++it)
					{
						if ((sys.getAvailableDevices() >= it->getDevices()) && sys.getAvailableMemory() >= it->getMemory())
						{
							Job *movingJob = new Job();
							*movingJob = *it;
//							sys.setAvailableDevices(it->getDevices());
							sys.setAvailableMemory(it->getMemory());
							rQueue->add(movingJob);
							it = wQueue->queue.erase(it);
						}
					}
				}
			}
			// if task still has time left, process as normal
			if (cpu->qTimeLeft != 0)
			{

			}
			// if task has ran out of time to run on cpu...
			else
			{
				Job * oldjob = new Job();
				*oldjob = cpu->oldJob();
				// if the job is COMPLETE
				if (oldjob->getTimeLeft() == 0)
				{
	    			oldjob->setFinishTime(curr_time-1);
					cQueue->add(oldjob);
					totalSys += double(oldjob->getTurnAround());
					totalJobs += 1.0;
					sys.setAvailableMemory(-1 * oldjob->getMemory());
//					sys.setAvailableDevices(-1 * oldjob->getDevices());
					if(wQueue->getFirstJob().getMemory() <= sys.getAvailableMemory() && wQueue->getFirstJob().getDevices() <= sys.getAvailableDevices())
					{
						if (wQueue->isEmpty() == true)
						{
							list<Job>::iterator it;
							for (it = wQueue->queue.begin(); it != wQueue->queue.end(); ++it)
							{
								if ((sys.getAvailableDevices() >= it->getDevices()) && sys.getAvailableMemory() >= it->getMemory())
								{
									Job *movingJob = new Job();
									*movingJob = *it;
//									sys.setAvailableDevices(it->getDevices());
									sys.setAvailableMemory(it->getMemory());
									rQueue->add(movingJob);
									it = wQueue->queue.erase(it);
								}
							}
						}
					}
					else if(hQueue1->getFirst().getMemory() <= sys.getAvailableMemory() && hQueue1->getFirst().getDevices() <= sys.getAvailableDevices())
					{
						Job *a = new Job();
						*a = hQueue1->popFirst();
						rQueue->add(a);
						sys.setAvailableMemory(a->getMemory());
//						sys.setAvailableDevices(a->getDevices());
					}
					else if(hQueue2->getFirst().getMemory() <= sys.getAvailableMemory() && hQueue2->getFirst().getDevices() <= sys.getAvailableDevices())
					{

						Job *a = new Job();
						*a = hQueue2->popFirst();
						rQueue->add(a);
						sys.setAvailableMemory(a->getMemory());
//						sys.setAvailableDevices(a->getDevices());
					}
				}
				else
				{
					rQueue->add(oldjob);
				}
				Job nextJob = rQueue->processNextJob();
				cpu->newJob(nextJob, sys, curr_time);
			}
		 }

		Job *currJob = new Job();
		*currJob = cpu->oldJob();
		if (currJob->getID() != 0)
		{
			list<Request>::iterator it;
			if(!requestss.empty())
			{
				for (it = requestss.begin(); it != requestss.end(); ++it)
				{
					if(currJob->getID() == it->getID())
					{
						currJob->addNewDevices(it->getDevices());
						if (sys.availableDevices >= (currJob->getDevices()))
						{
//							rQueue->add(currJob);

//							sys.setAvailableDevices(-1 * currJob->getDevices());
//							currJob->addNewDevices(-1 * it->getDevices());


//							updateReadyQueue();
						}
						else
						{
							// release devices f
							sys.setAvailableMemory(currJob->getMemory());
//							sys.setAvailableDevices(currJob->getDevices());
//							sys.setAvailableDevices(-1 * currJob->getDevices());

							// wQueue->add(currJob);
							updateReadyQueue();
						}
//						cout << "job ID: " << currJob->getID() << " curr job devs: " << currJob->getDevices() << endl;
//						cout << "curr sys Devs: " << sys.getAvailableDevices() << endl;
						// requestss.erase(it);
					}
				}
			}
		}
		if (curr_time == arriv)
		{
				lCount++;
				getNextLine();
				flag = true;
		}
		 	
		if (cpu->currJob.getID() != 0)
		{
			cpu->processCPU();
//			cout << "jobID: " << currJob->getID() << " curr mem: " << sys.getAvailableMemory() << endl;
		}
		if(disFlag)
		{
			displayStatus();
			disFlag = false;
		}

	}
}

