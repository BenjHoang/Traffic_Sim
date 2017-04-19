/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#ifndef Simulation_H
#define Simulation_H
#include "TrafficSimDataParser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "VehicleFactory.h"
#include "SimpleCarFactory.h"
#include "RoadMap.h"
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
using namespace std;
#pragma once;
class Simulation
{
	private:

			vector<VehicleFactory*> vector_Car1;
			int numCars;
			RoadMap world;
	public:
		Simulation();
		~Simulation();

		//run simulation
		void runSim(char* file, int faster);
		//set vehicle vector
		void setVehicle_vector(TrafficSimDataParser *parserObj);

};
#endif