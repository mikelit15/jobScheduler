/*
 * System.cpp
 *
 * Created on: May 10, 2022
 * Author: Mike Litvin
 *
 * System class that sets up the system configuration of the input system
 */

#include "System.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

/**
 * Default constructor for system object
 *
 * @author Mike Litvin
 */
System::System()
{
	memorySpace = 0;
	devices = 0;
	quantum = 0;
}

/**
 * Parameterized constructor for system object
 *
 * @author Mike Litvin
 */
System::System(int m, int d, int q)
{
	memorySpace = m;
	devices = d;
	quantum = q;
}

/**
 * Setter for total memory space in the system
 *
 * @param int - takes in the total memory from the text file
 * @author Mike Litvin
 */
void System::setMemorySpace(int space)
{
	memorySpace = space;
	availableMemory = space;
}

/**
 * Setter for total devices in the system
 *
 * @param int - takes in the total devices from the text file
 * @author Mike Litvin
 */
void System::setDevices(int numDevices)
{
	devices = numDevices;
	availableDevices = numDevices;
}

/**
 * Setter for the quantum of the system
 *
 * @param int - takes in the quantum from the text file
 * @author Mike Litvin
 */
void System::setQuantum(int quantumNum)
{
	quantum = quantumNum;
}

/**
 * Setter for the available memory in the system
 *
 * @param int - takes in the memory from the ready jobs and subtracts from the
 * existing available memory
 * @author Mike Litvin
 */
void System::setAvailableMemory(int memory)
{
	availableMemory -= memory;
}

/**
 * Setter for the available devices in the system
 *
 * @param int - takes in the devices from the ready jobs and subtracts from the
 * existing available devices
 * @author Mike Litvin
 */
void System::setAvailableDevices(int device)
{
	availableDevices -= device;
}

/**
 * Getter for the total memory
 *
 * @return int - total memory
 * @author Mike Litvin
 */
int System::getMemorySpace()
{
	return memorySpace;
}

/**
 * Getter for the available memory
 *
 * @return int - available memory
 * @author Mike Litvin
 */
int System::getAvailableMemory()
{
	return availableMemory;
}

/**
 * Getter for the available devices
 *
 * @return int - available devices
 * @author Mike Litvin
 */
int System::getAvailableDevices()
{
	return availableDevices;
}

/**
 * Getter for total devices
 *
 * @return int - total devices
 * @author Mike Litvin
 */
int System::getDevices()
{
	return devices;
}

/**
 * Getter for the quantum
 *
 * @return int - quantum
 * @author Mike Litvin
 */
int System::getQuantum()
{
	return quantum;
}

int System::getCPUCount()
{
	return cpuCount;
}

void System::setTime(int t) {
	curr_time = t;
}
int System::getTime() {
	return curr_time;
}


