/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Cartype_4Cylinder.h"


Cartype_4Cylinder::Cartype_4Cylinder(void)
{
	Moveobject = new Movement_4Cylinder();
}


Cartype_4Cylinder::~Cartype_4Cylinder(void)
{
}

void Cartype_4Cylinder::setType(char *type)
{
	Cartype_4Cylinder::m_sType = string(type);
}
void Cartype_4Cylinder::setId(int *idptr)
{
	Cartype_4Cylinder::m_iId = *idptr;
}
void Cartype_4Cylinder::setXpos(double *xpos)
{
	Cartype_4Cylinder::m_dXpos = *xpos;
}
void Cartype_4Cylinder::setYpos(double *ypos)
{
	Cartype_4Cylinder::m_dYpos = *ypos;
}
void Cartype_4Cylinder::setStartdir(double *startDir)
{
	Cartype_4Cylinder::m_dStartDir = *startDir;
}
void Cartype_4Cylinder::setAcc(double *acc)
{
	Cartype_4Cylinder::m_dAcc = *acc;
}

//singleton design pattern return vehicle type
Cartype_4Cylinder* Cartype_4Cylinder::getInstance()
{
	static Cartype_4Cylinder* theInstance;
	if(theInstance==NULL)
	{
		theInstance = new Cartype_4Cylinder();
	}
	return theInstance;
}