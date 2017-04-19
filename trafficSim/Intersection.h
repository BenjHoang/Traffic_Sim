/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#ifndef Intersection_H
#define Intersection_H
#include <string>
using namespace std;
#pragma once
class Intersection
{
	private:
		int m_iID; //traffic_light's id
		double m_dXpos; //x position
		double m_dYpos; //y position
		string m_sRoadN; //road north
		string m_sRoadE; //road east
		string m_sRoadS; //road south
		string m_sRoadW; //road west
		double m_dNumlanesNS;
		double m_dNumlanesEW;
	public:
		Intersection(void);	//default constructor
		~Intersection(void); //default destructor
		//set funtions
		void setID(int *id);
		void setXpos(double *x);
		void setYpos(double *y);
		void setroadN(char * roadN);
		void setroadE(char * roadE);
		void setroadS(char * roadS);
		void setroadW(char * roadW);
		void setnumlanesNS(double numlanes_NS);
		void setnumlanesEW(double numlanes_EW);
		//get funtions
		int getID(); //return int id value
		double getXpos();
		double getYpos();
		string getroadN();
		string getroadE();
		string getroadS();
		string getroadW();
		double getnumlanesNS();
		double getnumelanesEW();
		bool isPointInIntersection(double x, double y);
};
#endif