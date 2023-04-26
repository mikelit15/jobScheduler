/*
 * System.hpp
 *
 * Created on: May 10, 2022
 * Author: Mike Litvin
 *
 *
 */

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_


class System
{
public:
	int memorySpace;
	int devices;
	int quantum;
	int availableMemory;
	int availableDevices;
	int cpuCount = 0;
	int curr_time;

	int getMemorySpace();
	int getDevices();
	int getQuantum();
	int getAvailableMemory();
	int getAvailableDevices();
	int getCPUCount();

	void setMemorySpace(int s);
	void setDevices(int d);
	void setQuantum(int q);
	void setAvailableMemory(int m);
	void setAvailableDevices(int d);

	System();
	System(int m, int d, int q);

	void setTime(int t);
	int getTime();
};

#endif
