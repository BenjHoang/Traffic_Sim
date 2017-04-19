/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Traffic_light.h"

//default constructor
Traffic_light::Traffic_light(void)
{
	NS = green;
	WE = red;
}

//default destructor
Traffic_light::~Traffic_light(void)
{
}
//set functions(useless)
void Traffic_light::setNS()
{}
void Traffic_light::setWE()
{}

//get functions
int Traffic_light::getNS_light()
{
	int status;
	if(NS == green)
	{
		status = 0;
	}
	if(NS == amber)
	{
		status = 1;
	}
	if(NS == red)
	{
		status = 2;
	}

	return status;
}
int Traffic_light::getWE_light()
{
	int status;
	if(WE == green)
	{
		status = 0;
	}
	if(WE == amber)
	{
		status = 1;
	}
	if(WE == red)
	{
		status = 2;
	}
	return status;
}
//update traffic light
void Traffic_light::light_update(int state_value)
{
	while (state_value > 100)
	{
		state_value = state_value - 100;
	}
	if(state_value == 45) //45 secs after run sim
	{
		NS = amber;
		WE = red;
	}
	if(state_value == 50)//50 secs after run sim
	{
		NS = red;
		WE = green;
	}
	if(state_value == 95)//95 secs after run sim
	{
		NS = red;
		WE = amber;
	}
	if(state_value == 100)// 100 secs after run sim. => repeat cycle value back to 1.
	{
		NS = green;
		WE = red;
	}
}


