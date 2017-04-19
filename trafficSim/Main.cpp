/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include<iostream> //this is function for cout and cin
#include<string>
#include<cstring>
#include<fstream>
#include "Simulation.h"


using namespace std;
int main()
{
	srand((unsigned int)(time(NULL)));//for random generating 

	char file[127] = "" ;
	int counter = 0;
	bool flag = true;
	cout<<"Traffic Simulation"<<endl;
	cout<<"=================="<<endl;
	cout<<"PLease enter name of data file (file.xml): "<<endl;
	cin>>file;
	
	while(flag)
	{
	cout<<"do you want to run this simulation in 1X, 2X or 5X : ";
	cin>>counter;
	if(counter == 1 || counter == 2 || counter ==5)
		{
			flag = false;
		}
	}
	//build simulation
	Simulation *ts = new Simulation();
	//run simulation
	ts->runSim(file, counter);

	return 0;
}