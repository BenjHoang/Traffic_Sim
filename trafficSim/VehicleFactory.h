/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "TrafficSimDataParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "RoadMap.h"
#include "Movement_18Wheeler.h"
#include "Movement_LargeTruck.h"
#include "Movement_4Cylinder.h"
#include "Movement_6Cylinder.h"
#include "Movement_8Cylinder.h"
#pragma once

//base class for vehicle
class VehicleFactory
{

protected:
		string m_sType;
		int m_iId;
		double m_dXpos;
		double m_dYpos;
		double m_dStartDir;
		double m_dAcc;
		double vsmph;
		string name;
		Movement *Moveobject;


public:
	VehicleFactory(void);
	~VehicleFactory(void);


	//set functions
	void setMovement(Movement *MoveObject);
	virtual void setType(char *type);
	virtual void setId(int *id);
	virtual void setXpos(double *xpos);
	virtual void setYpos(double *ypos);
	virtual void setStartdir(double *startDir);
	virtual void setAcc(double *acc);
	 void MOVE(RoadMap world); //move function
	//get funtions
		string getType();
		int getID();
		double getXpos();
		double getYpos();
		double getStartdir();
		double getAcc();
		void PrintReport();//print function

};

