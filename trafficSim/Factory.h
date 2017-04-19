/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "VehicleFactory.h"

#pragma once
class Factory
{
public:
	Factory(void);
	~Factory(void);
	virtual VehicleFactory* create18WheelerInstance() = 0;
    virtual VehicleFactory* createLargeTruckInstance() = 0;
	virtual VehicleFactory* create4CynlinderInstance() = 0;
	virtual VehicleFactory* create6CynlinderInstance() = 0;
	virtual VehicleFactory* create8CynlinderInstance() = 0;
};

