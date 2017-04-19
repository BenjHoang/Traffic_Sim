/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include"Traffic_light.h"


#pragma once
class TrafficManager
{
private:
	 Traffic_light * m_tLight;
public:
	TrafficManager(void);
	~TrafficManager(void);
	int getNSlight();
	int getEWlight();
	void printLight();
	void update(int state);
};

