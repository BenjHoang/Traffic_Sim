/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "RoadMap.h"

//default constructor
RoadMap::RoadMap(void)
{
}
//default destructor
RoadMap::~RoadMap(void)
{
}

//all set functions
void RoadMap::setRoad(TrafficSimDataParser *parserObject)
{
	//all variables
	char name[128];
	double xStart; 
	double yStart; 
	double xEnd; 
	double yEnd; 
	int intersStart;
	int intersEnd; 
	double spdLimit; 
	int numLanes;
	m_iRoadNum = parserObject->getRoadCount();
	for (int i = 0; i<m_iRoadNum; i++)
	{
		if(parserObject->getRoadData(name, &xStart,&yStart,&xEnd, &yEnd,&intersStart, &intersEnd, &spdLimit, &numLanes)==true)
		{
			Road *road = new Road();
			road->setName(name);
			road->setxStart(&xStart);
			road->setyStart(&yStart);
			road->setxEnd(&xEnd);
			road->setyEnd(&yEnd);
			road->setintersStart(&intersStart);
			road->setintersEnd(&intersEnd);
			road->setspdlimit(&spdLimit);
			road->setnumLanes(&numLanes);
			road->setNS_EWroad();
			//push to vector
			m_Road_Array.push_back(road);
		}
	}
}

void RoadMap::setIntersection(TrafficSimDataParser *parserObject)
{
	//all variables
	int id;
	double xpos;
	double ypos; 
	char roadN[128]; 
	char roadE[128]; 
	char roadS[128]; 
	char roadW[128];
	
	m_iIntersectionNum = parserObject->getIntersectionCount();
	//setup intersection vector
	for(int i=0; i<m_iIntersectionNum; i++)
	{
		if(parserObject->getIntersectionData(&id, &xpos, &ypos, roadN, roadE, roadS, roadW)==true)
		{
			Intersection *inters = new Intersection();
			inters->setID(&id);
			inters->setXpos(&xpos);
			inters->setYpos(&ypos);
			inters->setroadN(roadN);
			inters->setroadE(roadE);
			inters->setroadS(roadS);
			inters->setroadW(roadW);
			//push intersection to inters_array
			m_Inters_Array.push_back(inters);
	
		
		}
	}

//set numlanes for each side of the intersection
for(int k =0; k<m_iIntersectionNum; k++)
	{
		for(int j = 0; j<m_iRoadNum; j++)
		{
			if(m_Inters_Array[k]->getroadN().empty() != true)
			{
				if(m_Inters_Array[k]->getroadN().compare(m_Road_Array[j]->getName()) == 0)
				{
					//set numlanes for NS/SE direction in intersection
					m_Inters_Array[k]->setnumlanesNS(m_Road_Array[j]->getnumLanes()); 
				}
			}
			if(m_Inters_Array[k]->getroadE().empty() != true)
			{
				if(m_Inters_Array[k]->getroadE().compare(m_Road_Array[j]->getName()) == 0)
				{
					//set numlanes for NS/SE direction in intersection
					m_Inters_Array[k]->setnumlanesEW(m_Road_Array[j]->getnumLanes()); 
				}
			}
			if(m_Inters_Array[k]->getroadS().empty() != true)
			{
				if(m_Inters_Array[k]->getroadS().compare(m_Road_Array[j]->getName()) == 0)
				{
					//set numlanes for NS/SE direction in intersection
					m_Inters_Array[k]->setnumlanesNS(m_Road_Array[j]->getnumLanes()); 
				}
			}
			if(m_Inters_Array[k]->getroadW().empty()!=true)
			{
				if(m_Inters_Array[k]->getroadW().compare(m_Road_Array[j]->getName()) == 0)
				{
					//set numlanes for NS/SE direction in intersection
					m_Inters_Array[k]->setnumlanesEW(m_Road_Array[j]->getnumLanes()); 
				}
			}
		}		
}
/*
//print out value testing
	for(int k =0; k<m_iIntersectionNum; k++)
	{
		if(m_Inters_Array[k]->isPointInIntersection( 1, 1) == true)
		{
			cout<<"point is on intersection id: "<<k<<endl;
		}
		else
		{
			cout<<"point is not on intersection id: "<<k<<endl;
		
		}
		cout<<"intersection id: "<<m_Inters_Array[k]->getID()<<endl;
		cout<<"intersection N: "<<m_Inters_Array[k]->getroadN()<<endl;
		cout<<"intersection W: "<<m_Inters_Array[k]->getroadW()<<endl;
		cout<<"intersection E: "<<m_Inters_Array[k]->getroadE()<<endl;
		cout<<"intersection S: "<<m_Inters_Array[k]->getroadS()<<endl;
		cout<<"numlanes of intersection NS :"<<m_Inters_Array[k]->getnumlanesNS()<<endl;
		cout<<"numlanes of intersection EW :"<<m_Inters_Array[k]->getnumelanesEW()<<endl;
	}
*/
}

void RoadMap::update(int value)
{
	m_TlightManager->update(value);

}

void RoadMap::printLight()
{
	m_TlightManager->printLight();
}
//all get functions
Road* RoadMap::getRoad(char *rdID)
{
	for(int k =0; k< m_iRoadNum; k++)
	{
		if(m_Road_Array[k]->getName().compare(string(rdID)) == 0)
		{
			return m_Road_Array[k];
		}
	}
	return NULL;
}

Road * RoadMap::getRoad(double x, double y, double dir)
{
	for(int k =0; k < m_iRoadNum; k++)
	{	if(m_Road_Array[k]->isPointOnRoad(x, y, dir) == true )
		{
			return m_Road_Array[k];
		}
	}
	return NULL;
}

Intersection* RoadMap::getIntersection(int id)
{
	for (int k = 0; k < m_iIntersectionNum; k++)
	{
	
		if(m_Inters_Array[k]->getID()==id)
		{
			return m_Inters_Array[k];
		}

	}
	return NULL;
}

Intersection* RoadMap::getNextIntersection(double x, double y, double dir)
{
	string curRoad = "";
	double minDist = 65536.999;
	curRoad = getRoad(x, y, dir)->getName();
	Intersection* nextIntersec = NULL;
	for (int k = 0; k < m_iIntersectionNum; k++)
	{
		double center_x = m_Inters_Array[k]->getXpos();
		double center_y = m_Inters_Array[k]->getYpos();
		bool checkIntersection_flag = false;
		if((dir == 0) && (m_Inters_Array[k]->getroadW().compare(curRoad) == 0 ) && (x < center_x))
			{
				checkIntersection_flag = true;
			}
		else if((dir == 90) && (m_Inters_Array[k]->getroadS().compare(curRoad) == 0) && (y > center_y))
			{
				checkIntersection_flag = true;
			}
		else if((dir == 180) && (m_Inters_Array[k]->getroadE().compare(curRoad) == 0) && (x > center_x))
			{
				checkIntersection_flag = true;
			}
		else if((dir == 270) && (m_Inters_Array[k]->getroadN().compare(curRoad) == 0) &&(y < center_y))
			{
				checkIntersection_flag = true;
			}
		if(checkIntersection_flag == true)
		{
			double dist = sqrt(pow(x- center_x, 2.0) + pow(y - center_y, 2.0));
			if(dist < minDist)
			{
				minDist = dist;
				nextIntersec = m_Inters_Array[k];
			}
		}
	}
	return nextIntersec;
}

Intersection* RoadMap::getIntersection(double x, double y)
{
	for (int k = 0; k < m_iIntersectionNum; k++)
	{
		if(m_Inters_Array[k]->isPointInIntersection(x,y) == true)
		{
			return m_Inters_Array[k];
		}
	}
	return NULL;// return nothing if not found
}

void RoadMap::iniTraffic()
{
	m_TlightManager = new TrafficManager();
}
int RoadMap::getEW_light()
{
	return m_TlightManager->getEWlight();
}
int RoadMap::getNS_light()
{
	return m_TlightManager->getNSlight();
}