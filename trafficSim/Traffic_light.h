/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include<iostream>

#pragma once
using namespace std;

class Traffic_light
{

	private:
		enum light_color {green, amber, red};
		light_color NS;
		light_color WE;

	public:
		//default constructor, destructor
		Traffic_light(void);
		~Traffic_light(void);
		void light_update(int state_value);
	

		//set functions
		void setNS();
		void setWE();

		//get functions
		void getlight();
		int getNS_light();
		int getWE_light();



};

