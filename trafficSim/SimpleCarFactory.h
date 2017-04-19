/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include"Factory.h"
#include "Cartype_18Wheeler.h"
#include "Cartype_LargeTruck.h"
#include "Cartype_4Cylinder.h"
#include "Cartype_6Cylinder.h"
#include "Cartype_8Cylinder.h"
#pragma once
class SimpleCarFactory: public Factory
{
public:
	SimpleCarFactory(void);
	~SimpleCarFactory(void);
	
	VehicleFactory* create18WheelerInstance();
    VehicleFactory* createLargeTruckInstance();
	VehicleFactory* create4CynlinderInstance();
	VehicleFactory* create6CynlinderInstance();
	VehicleFactory* create8CynlinderInstance();

};

