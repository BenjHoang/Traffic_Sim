/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include"Movement.h"
#pragma once
class Movement_4Cylinder:public Movement
{
public:
	Movement_4Cylinder(void);
	~Movement_4Cylinder(void);

	//get functions
	double getVSmph();
	//override methods
	void setVSmps(double mps);
	void setVSmph(double mph);
	void MOVE(RoadMap world, double &m_dXpos, double &m_dYpos, double &m_dStartDir, double m_dAcc);
	double setNextTurn(Intersection* itr, double m_dStartDir);
	void speed_algorithm(Intersection* itr, int TLstat, double TSDSL, double AB, double SLmps, double &TSDVS, double m_dAcc);
};

