/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Cartype_LargeTruck.h"


Cartype_LargeTruck::Cartype_LargeTruck(void)
{
	Moveobject = new Movement_LargeTruck();
}


Cartype_LargeTruck::~Cartype_LargeTruck(void)
{
}

void Cartype_LargeTruck::setType(char *type)
{
	Cartype_LargeTruck::m_sType = string(type);
}
void Cartype_LargeTruck::setId(int *idptr)
{
	Cartype_LargeTruck::m_iId = *idptr;
}
void Cartype_LargeTruck::setXpos(double *xpos)
{
	Cartype_LargeTruck::m_dXpos = *xpos;
}
void Cartype_LargeTruck::setYpos(double *ypos)
{
	Cartype_LargeTruck::m_dYpos = *ypos;
}
void Cartype_LargeTruck::setStartdir(double *startDir)
{
	Cartype_LargeTruck::m_dStartDir = *startDir;
}
void Cartype_LargeTruck::setAcc(double *acc)
{
	Cartype_LargeTruck::m_dAcc = *acc;
}

//singleton design pattern return vehicle type
Cartype_LargeTruck* Cartype_LargeTruck::getInstance()
{
	static Cartype_LargeTruck* theInstance;
	if(theInstance==NULL)
	{
		theInstance = new Cartype_LargeTruck();
	}
	return theInstance;
}