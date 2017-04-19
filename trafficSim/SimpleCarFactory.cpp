/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "SimpleCarFactory.h"


SimpleCarFactory::SimpleCarFactory(void)
{
}


SimpleCarFactory::~SimpleCarFactory(void)
{
}
VehicleFactory* SimpleCarFactory::create18WheelerInstance()
{
	return Cartype_18Wheeler().getInstance();
}
VehicleFactory* SimpleCarFactory::createLargeTruckInstance()
{
	return Cartype_LargeTruck().getInstance();
}
VehicleFactory* SimpleCarFactory::create4CynlinderInstance()
{
	return Cartype_4Cylinder().getInstance();
}
VehicleFactory* SimpleCarFactory::create6CynlinderInstance()
{
	return Cartype_6Cylinder().getInstance();
}
VehicleFactory* SimpleCarFactory::create8CynlinderInstance()
{
	return Cartype_8Cylinder().getInstance();
}

