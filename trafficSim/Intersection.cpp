/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "intersection.h"

//default constructor
Intersection::Intersection(void)
{
}

//default destructor
Intersection::~Intersection(void)
{
}

//set functions
void Intersection::setID(int *id)
{
	Intersection::m_iID = *id;
}
void Intersection::setXpos(double *x)
{
	Intersection::m_dXpos = *x;
}
void Intersection::setYpos(double *y)
{
	Intersection::m_dYpos = *y;
}

void Intersection::setroadN(char * roadN)
{
	Intersection::m_sRoadN = string(roadN);
}
void Intersection::setroadE(char * roadE)
{
	Intersection::m_sRoadE = string(roadE);
}
void Intersection::setroadS(char * roadS)
{
	Intersection::m_sRoadS = string(roadS);
}
void Intersection::setroadW(char * roadW)
{
	Intersection::m_sRoadW = string(roadW);
}

void Intersection::setnumlanesNS(double numlanes_NS)
{
	m_dNumlanesNS = numlanes_NS;
}

void Intersection::setnumlanesEW(double numlanes_EW)
{
	m_dNumlanesEW = numlanes_EW;
}
//all get functions
int Intersection::getID()
{
	return m_iID;
}
double Intersection::getXpos()
{
	return m_dXpos;
}
double Intersection::getYpos()
{
	return m_dYpos;
}
string Intersection::getroadN()
{
	return m_sRoadN;
}
string Intersection::getroadE()
{
	return m_sRoadE;
}
string Intersection::getroadS()
{
	return m_sRoadS;
}
string Intersection::getroadW()
{
	return m_sRoadW;
}

double Intersection::getnumlanesNS()
{
	return m_dNumlanesNS;
}
double Intersection::getnumelanesEW()
{
	return m_dNumlanesEW;
}
//check if x,y is in the intersection
bool Intersection::isPointInIntersection(double x, double y)
{
	double laneWidth= 3.6;
	double ULX = m_dXpos - ((m_dNumlanesNS/2)*laneWidth);
	double ULY = m_dYpos - ((m_dNumlanesEW/2)*laneWidth);
	double LRX = m_dXpos + ((m_dNumlanesNS/2)*laneWidth);
	double LRY = m_dYpos + ((m_dNumlanesEW/2)*laneWidth);

	if((x >= ULX) && (x <= LRX) && (y >= ULY) && (y <= LRY))
	{
		//point is in the intersection
		return true;
	}

	//point is not in the intersection
	return false;
}
