/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "VehicleFactory.h"

#pragma once
class Cartype_4Cylinder:public VehicleFactory
{
public:
	Cartype_4Cylinder(void);
	~Cartype_4Cylinder(void);

	//all virtual functions here that need to define
	void setType(char *type);
	void setId(int *id);
	void setXpos(double *xpos);
	void setYpos(double *ypos);
	void setStartdir(double *startDir);
	void setAcc(double *acc);
	//singleton design pattern return vehicle type
	static Cartype_4Cylinder* getInstance();
};

