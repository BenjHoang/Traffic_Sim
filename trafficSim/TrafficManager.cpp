/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "TrafficManager.h"


TrafficManager::TrafficManager(void)
{
	m_tLight = new Traffic_light();
}


TrafficManager::~TrafficManager(void)
{
}
int TrafficManager::getNSlight()
{
	//return Light_object->getNS_light();
	return m_tLight->getNS_light();
}

int TrafficManager::getEWlight()
{
	//return Light_object->getWE_light();
	return m_tLight->getWE_light();
}
void TrafficManager::update(int state)
{
	m_tLight->light_update(state);
}
void TrafficManager::printLight()
{
	//light for NS
	if(m_tLight->getNS_light() ==0 )
	{ 
		cout<<"NS traffic light status GREEN"<<endl;
	}
	else if(m_tLight ->getNS_light() ==1 )
	{
		cout<<"NS traffic light status AMBER"<<endl;
	}
	else if(m_tLight ->getNS_light() ==2 )
	{
		cout<<"NS traffic light status RED"<<endl;
	}
	//light for WE
	if(m_tLight ->getWE_light() ==0 )
	{
		cout<<"WE traffic light status GREEN"<<endl;
	}
	else if(m_tLight ->getWE_light() ==1 )
	{
		cout<<"WE traffic light status AMBER"<<endl;
	}
	else if(m_tLight ->getWE_light() ==2 )
	{
		cout<<"WE traffic light status RED"<<endl;
	}
}