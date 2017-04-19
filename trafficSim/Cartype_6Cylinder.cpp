/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Cartype_6Cylinder.h"


Cartype_6Cylinder::Cartype_6Cylinder(void)
{
	Moveobject = new Movement_6Cylinder();
}


Cartype_6Cylinder::~Cartype_6Cylinder(void)
{
}

void Cartype_6Cylinder::setType(char *type)
{
	Cartype_6Cylinder::m_sType = string(type);
}
void Cartype_6Cylinder::setId(int *idptr)
{
	Cartype_6Cylinder::m_iId = *idptr;
}
void Cartype_6Cylinder::setXpos(double *xpos)
{
	Cartype_6Cylinder::m_dXpos = *xpos;
}
void Cartype_6Cylinder::setYpos(double *ypos)
{
	Cartype_6Cylinder::m_dYpos = *ypos;
}
void Cartype_6Cylinder::setStartdir(double *startDir)
{
	Cartype_6Cylinder::m_dStartDir = *startDir;
}
void Cartype_6Cylinder::setAcc(double *acc)
{
	Cartype_6Cylinder::m_dAcc = *acc;
}

//singleton design pattern return vehicle type
Cartype_6Cylinder* Cartype_6Cylinder::getInstance()
{
	static Cartype_6Cylinder* theInstance;
	if(theInstance==NULL)
	{
		theInstance = new Cartype_6Cylinder();
	}
	return theInstance;
}