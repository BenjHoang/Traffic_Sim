/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Intersection.h"
#include "Road.h"
#include "TrafficSimDataParser.h"
#include "TrafficManager.h"
#include <vector>
#pragma once
class RoadMap
{
	private:
		vector<Road*> m_Road_Array;
		vector<Intersection*> m_Inters_Array;
		TrafficManager *m_TlightManager;
		int m_iRoadNum;
		int m_iIntersectionNum;
	public:
		RoadMap(void);
		~RoadMap(void);
		//set functions
		void setRoad(TrafficSimDataParser *parserObject);
		void setIntersection(TrafficSimDataParser *parserObject);
		void iniTraffic();
		void update(int value);
		//get functions
		void printLight();
		Road *getRoad(char *rdID);
		Road *getRoad(double x, double y, double dir);
		Intersection *getIntersection(int id);//get a pointer to an intersection given the ID
		Intersection *getNextIntersection(double x, double y, double dir);//get the next intersection
		Intersection *getIntersection(double x, double y);//get intersection at given point
		int getEW_light();
		int getNS_light();
};

