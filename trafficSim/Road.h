/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include<string>
using namespace std;
#pragma once
class Road
{
	private:
		string name;
		double m_dXStart, m_dYStart, m_dXEnd, m_dYEnd;
		int m_iIntersStart, m_iIntersEnd;
		bool m_bIsNSroad;
		bool m_bIsEWroad;
		double m_dSpdlimit;
		int m_iNumLanes;
	public:
		Road(void);
		~Road(void);

		//all set functions
		void setName(char *name);
		void setxStart(double *xStart);
		void setyStart(double *yStart);
		void setxEnd(double *xEnd);
		void setyEnd(double *yEnd);
		void setintersStart(int *intersStart);
		void setintersEnd(int *intersEnd);
		void setspdlimit(double *spdlimit);
		void setnumLanes(int *numLanes);
		void setNS_EWroad();


		//all get functions
		string getName();
		double getxStart();
		double getyStart();
		double getxEnd();
		double getyEnd();
		int getintersStart();
		int getintersEnd();
		double getspdlimit();
		int getnumLanes();
		bool isPointOnRoad(double x, double y, double dir);

};

