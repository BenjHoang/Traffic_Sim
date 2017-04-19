/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Cartype_18Wheeler.h"


Cartype_18Wheeler::Cartype_18Wheeler(void)
{
	Moveobject = new Movement_18Wheeler();
}

Cartype_18Wheeler::~Cartype_18Wheeler(void)
{
}

void Cartype_18Wheeler::setType(char *type)
{
	Cartype_18Wheeler::m_sType = string(type);
}
void Cartype_18Wheeler::setId(int *idptr)
{
	Cartype_18Wheeler::m_iId = *idptr;
}
void Cartype_18Wheeler::setXpos(double *xpos)
{
	Cartype_18Wheeler::m_dXpos = *xpos;
}
void Cartype_18Wheeler::setYpos(double *ypos)
{
	Cartype_18Wheeler::m_dYpos = *ypos;
}
void Cartype_18Wheeler::setStartdir(double *startDir)
{
	Cartype_18Wheeler::m_dStartDir = *startDir;
}
void Cartype_18Wheeler::setAcc(double *acc)
{
	Cartype_18Wheeler::m_dAcc = *acc;
}
//singleton design pattern return vehicle type
Cartype_18Wheeler* Cartype_18Wheeler::getInstance()
{
	static Cartype_18Wheeler* theInstance;
	
	if(theInstance==NULL)
	{
		theInstance = new Cartype_18Wheeler();
	}
	return theInstance;
}