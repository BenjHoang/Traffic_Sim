/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Cartype_8Cylinder.h"


Cartype_8Cylinder::Cartype_8Cylinder(void)
{
	Moveobject = new Movement_8Cylinder();
}


Cartype_8Cylinder::~Cartype_8Cylinder(void)
{
}

void Cartype_8Cylinder::setType(char *type)
{
	Cartype_8Cylinder::m_sType = string(type);
}
void Cartype_8Cylinder::setId(int *idptr)
{
	Cartype_8Cylinder::m_iId = *idptr;
}
void Cartype_8Cylinder::setXpos(double *xpos)
{
	Cartype_8Cylinder::m_dXpos = *xpos;
}
void Cartype_8Cylinder::setYpos(double *ypos)
{
	Cartype_8Cylinder::m_dYpos = *ypos;
}
void Cartype_8Cylinder::setStartdir(double *startDir)
{
	Cartype_8Cylinder::m_dStartDir = *startDir;
}
void Cartype_8Cylinder::setAcc(double *acc)
{
	Cartype_8Cylinder::m_dAcc = *acc;
}

//singleton design pattern return vehicle type
Cartype_8Cylinder* Cartype_8Cylinder::getInstance()
{
	static Cartype_8Cylinder* theInstance;
	if(theInstance==NULL)
	{
		theInstance = new Cartype_8Cylinder();
	}
	return theInstance;
}