/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include"string.h"
#include <iostream>
#include "RoadMap.h"

using namespace std;
#pragma once
class Movement
{
protected:
		double m_dMPH;//vehicle speed in mile per hour
		double m_dMPS;// vehicle speed in meter per sec
		double VSmps; //vehicle speed meter per sec
		double VSmph; //vehicle speed mile per hour
		bool turndecided_flag;//turn flag
		double next_turn;//next turn 
		Road *Rd;//current road
public:
	Movement(void);
	~Movement(void);
	
	//get functions
	double getVSmph();
	string getRdName();
	virtual void MOVE(RoadMap world, double &m_dXpos, double &m_dYpos, double &m_dStartDir, double m_dAcc);
	void setVSmps(double mps);
	void setVSmph(double mph);
	virtual double setNextTurn(Intersection* itr);
	virtual void speed_algorithm(Intersection* itr, int TLstat, double TSDSL, double AB, double SLmps, double &TSDVS);

};

