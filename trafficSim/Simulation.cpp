/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Simulation.h"
using namespace std;


//default constructor
Simulation::Simulation()
{

}
//default destructor
Simulation::~Simulation()
{}


//run simulation
void Simulation::runSim(char* file, int faster)
{
	//timer
	_timeb   tStruct;
    double          thisTime;
    double          outputTimeA;
	double          outputTimeB;
    bool            done = false;  // while loop flag
	//counter timer
	int counter = 0;

	//run data parser
	TrafficSimDataParser *parserObject = TrafficSimDataParser::getInstance();
	parserObject->setDataFileName(file);

	//run world map simulation
	world.iniTraffic();
	world.setRoad(parserObject);
	world.setIntersection(parserObject);
	//run vehicle
	setVehicle_vector(parserObject);


	//perform 5 secs loop
	_ftime(&tStruct);	// Get start time
    thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
    outputTimeA = thisTime + 1.0; // Set next 1 second interval time
	outputTimeB = thisTime + 5.0; // Set next 5 second interval time

    while(!done)     // Start an eternal loop
    {
        _ftime(&tStruct);    // Get the current time
        thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
        	
		
		/*==========================================================================*/
		/*==========================================================================*/ 
		// Check for 1 second interval to update
        if(thisTime >= outputTimeA)
        {
		

			for(int i = 0; i< faster; i++ )//user reference how fast to run program(1x, 2x, 5x)
			{
				//update world with real time
				world.update(counter);
				//update through each car
				for (int i = 0; i <(int)(vector_Car1.size()); i++)
				{
					vector_Car1[i]->MOVE(world);
					
				}
					counter++; //increase counter by 1
			}



            // Call functions to perform actions at 1 second intervals
            outputTimeA += 1.0; // Set time for next 1 second interval
        }


		/*==========================================================================*/
		/*==========================================================================*/
		// Check for 5 second interval to print status to screen
        if(thisTime >= outputTimeB)
        {
			
			cout<<"current timelapsed "<<counter<<endl;
			//print report
			world.printLight();
			for (int i = 0; i < (int)(vector_Car1.size()); i++)
			{
				vector_Car1[i]->PrintReport();

			}
			// Call functions to perform actions at 5 second intervals
            outputTimeB += 5.0; // Set time for next 5 second interval
		
		}

        // Do other stuff here
   }
	

}

//set vehicle vector
void Simulation::setVehicle_vector(TrafficSimDataParser *parserObject)
{
	
		//variables car
		char type[128];
		int id;
		double xpos;
		double ypos;
		double startDir;
		double acc;
		for(int i =0; i<parserObject->getVehicleCount(); i++)
		{
			if(parserObject->getVehicleData(type, &id, &xpos, &ypos, &startDir, &acc)==true)
			{
				Factory * factory = new SimpleCarFactory;
				if(strcmp(type, "18-WHEELER") == 0)
				{
					
					VehicleFactory *temp = factory->create18WheelerInstance();
					Movement *moveObject = new Movement_18Wheeler();
					temp->setType(type);
					temp->setId(&id);
					temp->setXpos(&xpos);
					temp->setYpos(&ypos);
					temp->setStartdir(&startDir);
					temp->setAcc(&acc);
					temp->setMovement(moveObject);
					vector_Car1.push_back(temp);
				}
				else if(strcmp(type, "LARGE_TRUCK") == 0)
				{
					
					VehicleFactory *temp = factory->createLargeTruckInstance();
					Movement *moveObject = new Movement_LargeTruck();
					temp->setType(type);
					temp->setId(&id);
					temp->setXpos(&xpos);
					temp->setYpos(&ypos);
					temp->setStartdir(&startDir);
					temp->setAcc(&acc);
					temp->setMovement(moveObject);
					vector_Car1.push_back(temp);
					
				}
				else if(strcmp(type, "4-CYLINDER_CAR") == 0)
				{
					VehicleFactory *temp = factory->create4CynlinderInstance();
					Movement *moveObject = new Movement_4Cylinder();
					temp->setType(type);
					temp->setId(&id);
					temp->setXpos(&xpos);
					temp->setYpos(&ypos);
					temp->setStartdir(&startDir);
					temp->setAcc(&acc);
					temp->setMovement(moveObject);
					vector_Car1.push_back(temp);
				}
				else if(strcmp(type, "6-CYLINDER_CAR") == 0)
				{
					VehicleFactory *temp = factory->create6CynlinderInstance();
					Movement *moveObject = new Movement_6Cylinder();
					temp->setType(type);
					temp->setId(&id);
					temp->setXpos(&xpos);
					temp->setYpos(&ypos);
					temp->setStartdir(&startDir);
					temp->setAcc(&acc);
					temp->setMovement(moveObject);
					vector_Car1.push_back(temp);

				}
				else if(strcmp(type, "8-CYLINDER_CAR") == 0)
				{
					VehicleFactory *temp = factory->create8CynlinderInstance();
					Movement *moveObject = new Movement_8Cylinder();
					temp->setType(type);
					temp->setId(&id);
					temp->setXpos(&xpos);
					temp->setYpos(&ypos);
					temp->setStartdir(&startDir);
					temp->setAcc(&acc);
					temp->setMovement(moveObject);
					vector_Car1.push_back(temp);
				}
				else
				{
					cout<<"this vehicle type "<<type<<" doesn't exists!!!"<<endl;
				}
			}
		}
}


