/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "VehicleFactory.h"


VehicleFactory::VehicleFactory(void)
{
}


VehicleFactory::~VehicleFactory(void)
{
}

void VehicleFactory::setType(char *type)
{}
void VehicleFactory::setId(int *idptr)
{}
void VehicleFactory::setXpos(double *xpos)
{}
void VehicleFactory::setYpos(double *ypos)
{}
void VehicleFactory::setStartdir(double *startDir)
{}
void VehicleFactory::setAcc(double *acc)
{}
void VehicleFactory::setMovement(Movement *MoveObject)
{
	VehicleFactory::Moveobject = MoveObject;
}
//all get functions
int VehicleFactory::getID()
{
	return m_iId;
}

string VehicleFactory::getType()
{
	return m_sType;
}

double VehicleFactory::getXpos()
{
	return m_dXpos;
}
double VehicleFactory::getYpos()
{
	return m_dYpos;
}
double VehicleFactory::getStartdir()
{
	return m_dStartDir;}
double VehicleFactory::getAcc()
{
	return m_dAcc;
}
void VehicleFactory::MOVE(RoadMap world)
{
	VehicleFactory::Moveobject->MOVE(world, m_dXpos, m_dYpos, m_dStartDir, m_dAcc);

}
void VehicleFactory::PrintReport()
{
	
	cout<<"vehicle "<<m_iId<<endl;
	cout<<"	Type: "<<m_sType<< ", Location: ("<<m_dXpos<<", "<<m_dYpos<<")"<<endl;
	cout<<"	Direction: "<<m_dStartDir<<" degrees, traveling at "<<Moveobject->getVSmph()<<"mph on road "<<Moveobject->getRdName()<<"."<<endl; 
	cout<<"=================================================================="<<endl<<endl;
}
