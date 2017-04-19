/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Road.h"


Road::Road(void)
{
}

Road::~Road(void)
{
}


//all set functions
void Road::setName(char *name)
{
	Road::name = string(name);
}
void Road::setxStart(double *xStart)
{
	Road::m_dXStart = *xStart;
}
void Road::setyStart(double *yStart)
{
	Road::m_dYStart = *yStart;
}
void Road::setxEnd(double *xEnd)
{
	Road::m_dXEnd = *xEnd;
}
void Road::setyEnd(double *yEnd)
{
	Road::m_dYEnd = *yEnd;
}
void Road::setintersStart(int *intersStart)
{
	Road::m_iIntersStart = *intersStart;
}
void Road::setintersEnd(int *intersEnd)
{
	Road::m_iIntersEnd = *intersEnd;
}
void Road::setspdlimit(double *spdlimit)
{
	Road::m_dSpdlimit = *spdlimit;
}
void Road::setnumLanes(int *numLanes)
{
	Road::m_iNumLanes = *numLanes;
}
void Road::setNS_EWroad()
{
	//east-west x_start != x_end, y_start = y_end horizontal road
	if((m_dXStart != m_dXEnd) && (m_dYStart == m_dYEnd))
	{
		m_bIsEWroad = true;
		m_bIsNSroad = false;
	}
	else
	{
		m_bIsEWroad = false;
		m_bIsNSroad = true;
	}
}

//all get functions
string Road::getName()
{
	return name;
}
double Road::getxStart()
{
	return m_dXStart;
}
double Road::getyStart()
{
	return m_dYStart;
}
double Road::getxEnd()
{
	return m_dXEnd;
}
double Road::getyEnd()
{
	return m_dYEnd;
}
int Road::getintersStart()
{
	return m_iIntersStart;
}
int Road::getintersEnd()
{
	return m_iIntersEnd;
}
double Road::getspdlimit()
{
 	return m_dSpdlimit;
}
int Road::getnumLanes()
{
	return m_iNumLanes;
}
bool Road::isPointOnRoad(double x, double y, double dir)
{
	double lanewidth = 3.6;
	//east-west x_start != x_end, y_start = y_end horizontal road
	if(m_bIsEWroad == true)
	{
		double ULX = m_dXStart;
		double ULY = m_dYStart - ((m_iNumLanes/2)*lanewidth);
		double LRX = m_dXEnd;
		double LRY = m_dYEnd + ((m_iNumLanes/2)*lanewidth);
		if((x >= ULX) && (x <= LRX) && (y >= ULY) && (y <= LRY))
			{
				if(dir ==0 || dir == 180)
				{
					return true;
				}
				//point is on the road
				
			}
	}

	//north-south x_start == x_end, y_start != y_end vertical road
	if(m_bIsNSroad == true)
	{
		double ULX = m_dXStart - ((m_iNumLanes/2)*lanewidth);
		double ULY = m_dYStart;
		double LRX = m_dXEnd + ((m_iNumLanes/2)*lanewidth);
		double LRY = m_dYEnd;
		if((x >= ULX) && (x <= LRX) && (y >= ULY) && (y <= LRY))
			{
				if(dir==90 || dir == 270)
				{
				//point is on the road
				return true;
				}
			}
	}
	return false;
}