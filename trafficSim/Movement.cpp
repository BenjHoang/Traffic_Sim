/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Movement.h"

Movement::Movement(void)
{}


Movement::~Movement(void)
{}

void Movement::MOVE(RoadMap world, double &m_dXpos, double &m_dYpos, double &m_dStartDir, double m_dAcc)
{
	
}
double Movement::setNextTurn(Intersection* itr)
{
	//do something
	return 0;
}
void Movement::speed_algorithm(Intersection* itr, int TLstat, double TSDSL, double AB, double SLmps, double &TSDVS)
{
	//do something
}
void Movement::setVSmps(double mps)
{
	VSmps = mps;
}
void Movement::setVSmph(double mph)
{
	VSmph = mph;
}
double Movement::getVSmph()
{
	return VSmph;
}
string Movement::getRdName()
{
	return Rd->getName();
}