/*******************************************************************
	*   CS 307 Programming Assignment 2
	*   Author: Benjmin hoang
	*   Desc: traffic simulation
	*   Date: 4/15/2017
	*   I attest that this program is entirely my own work
	*******************************************************************/
#include "Movement_LargeTruck.h"


Movement_LargeTruck::Movement_LargeTruck(void)
{
	VSmph = 0.0;//default speed
	VSmps = 0.0;//dafault speed
	m_dMPH = 0.0;//vehicle speed in mile per hour
	m_dMPS = 0.0;// vehicle speed in mile per sec
	turndecided_flag = false;
}


Movement_LargeTruck::~Movement_LargeTruck(void)
{
}

void Movement_LargeTruck::MOVE(RoadMap world, double &m_dXpos, double &m_dYpos, double &m_dStartDir, double m_dAcc)
{	
	double LaneWidth = 3.6;
	bool flag = false;
	Rd = NULL;
	Rd = world.getRoad(m_dXpos, m_dYpos, m_dStartDir);

	//catch road == null error
	if(Rd == NULL)
	{
		flag = true;
	}
	while( flag == true)
	{
			if (m_dStartDir == 0)
			{
				m_dXpos = m_dXpos + LaneWidth *2.0;
			}
			else if(m_dStartDir == 90)
			{
				m_dYpos = m_dYpos - LaneWidth *2.0;
			}
			else if(m_dStartDir == 180)
			{
				m_dXpos = m_dXpos - LaneWidth *2.0;
			}
			else if(m_dStartDir == 270)
			{
				m_dYpos = m_dYpos + LaneWidth *2.0;
			}
			//try again to set Rd
			Rd = world.getRoad(m_dXpos, m_dYpos, m_dStartDir);
			if(Rd != NULL)
			{
				flag = false;
			}
	}
	

	
	double BC = 0.0; 
	double AC = 0.0;// speed limit on this road
	//double VS; //vehicle speed
	double SL= Rd->getspdlimit();//speed limit on this road
	int TLstat; //traffic light status (0 green, 1 amber, 2 red)
	//get next intersection
	Intersection *itr = world.getNextIntersection(m_dXpos, m_dYpos, m_dStartDir);
	//get current road speed limit
	double SLMPH = Rd->getspdlimit();
	double SLmph = Rd->getspdlimit() * 1609.344;//convert from mile/hour to meter/hour
	double SLmps = Rd->getspdlimit() * 0.44704;//get speed to meter per sec
	double TSDSL = 1.1 * SLMPH + 0.06 * SLMPH * SLMPH;//stop distant in mile/hour
	TSDSL *= 0.3048; //convert safe stopping distant to meter
	double TSDVS = 1.1 * VSmph + 0.06 * VSmph * VSmph; //total stop distant of vehicle
	TSDVS *= 0.3048; //convert vehicle stopping distant to meter

	
	if(turndecided_flag == false)
	{
		next_turn = setNextTurn(itr, m_dStartDir);
		if(m_dStartDir == 0 && next_turn == -90)
		{
			next_turn = 270;
		}
		else if(m_dStartDir == 270 && next_turn == 90)
		{
			next_turn = 0;
		}
		else
		{
			next_turn = next_turn + m_dStartDir;
		}
		turndecided_flag = true;
	}
	
	if(m_dStartDir == 0 || m_dStartDir == 180)
	{
		TLstat =  world.getEW_light(); //if vehicle travelling EW, get EW traffic_light 
	}
	else
	{
		TLstat = world.getNS_light(); //if vehicle travelling else, get NS traffic_light
	}
	//get xy center of intersection
	double CX = itr->getXpos();
	double CY = itr->getYpos();

	//dir == east(0)
	if(m_dStartDir == 0)
	{
		//variable for east direction
		//data garthering here
		BC = (itr->getnumlanesNS() == 4)?(LaneWidth * 2.0):(LaneWidth * 1.0);
		AC = itr->getXpos() - m_dXpos; 
		double AB = AC - BC; //distant from current x to next intersection center x
		speed_algorithm(itr, TLstat, TSDSL, AB, SLmps, TSDVS, m_dAcc);
		m_dXpos = m_dXpos + VSmps;//set x pos of vehicle
		m_dYpos = m_dYpos;//keep y pos same  

		//turn 
		if(m_dXpos > CX)
		{
			if(next_turn == 90 )//go left
			{
				double A_C = VSmps;
				double B_D = (itr->getnumlanesNS() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = CX - m_dXpos;
				double B_C = A_C - A_D - B_D;

				m_dXpos = CX + B_D;
				m_dYpos = m_dYpos + B_C;
				m_dStartDir = 90;
			}
			else if(next_turn == 270 )//go right
			{
				double A_C = VSmps;
				double B_D = (itr->getnumlanesNS() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = CX - m_dXpos;
				double B_C = A_C - A_D + B_D;

				m_dXpos = CX - B_D;
				m_dYpos = m_dYpos +B_C;
				m_dStartDir = 270;
			}
			turndecided_flag = false;
		}
	}
	//dir == north(90)
	else if(m_dStartDir == 90)
	{
		//variable for east direction
		//data garthering here
		BC = (itr->getnumelanesEW() == 4)?(LaneWidth * 2.0):(LaneWidth * 1.0);
		AC = m_dXpos - itr->getXpos(); 
		double AB = AC - BC; //distant from current x to next intersection center x
		speed_algorithm(itr, TLstat, TSDSL, AB, SLmps, TSDVS, m_dAcc);
		m_dXpos = m_dXpos;//set x pos of vehicle
		m_dYpos = m_dYpos - VSmps;//keep y pos same  

		//turn 
		if(m_dYpos < CY)
		{
			if(next_turn == 180 )//go left
			{
				double A_C = VSmps;
				double B_D = (itr->getnumelanesEW() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = m_dYpos - CY;
				double B_C = A_C - A_D - B_D;

				m_dXpos = m_dXpos - B_C;
				m_dYpos = CY - B_D;
				m_dStartDir = 180;
			}
			else if(next_turn == 0 )//go right
			{
				double A_C = VSmps;
				double B_D = (itr->getnumelanesEW() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = m_dYpos - CY;
				double B_C = A_C - A_D + B_D;

				m_dXpos = m_dXpos + B_C;
				m_dYpos = CY + B_D;//m_dYpos +B_C;
				m_dStartDir = 0;
			}
			turndecided_flag = false;
		}

	}
	//dir == west(180)
	else if(m_dStartDir == 180)
	{
		//variable for east direction
		//data garthering here
		BC = (itr->getnumlanesNS() == 4)?(LaneWidth * 2.0):(LaneWidth * 1.0);
		AC = m_dXpos - itr->getXpos(); 
		double AB = AC - BC; //distant from current x to next intersection center x
		speed_algorithm(itr, TLstat, TSDSL, AB, SLmps, TSDVS, m_dAcc);
		m_dXpos = m_dXpos - VSmps;//set x pos of vehicle
		m_dYpos = m_dYpos;//keep y pos same  

		//turn 
		if(m_dXpos < CX)
		{
			if(next_turn == 270 )//go left
			{
				double A_C = VSmps;
				double B_D = (itr->getnumlanesNS() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = m_dXpos - CX;
				double B_C = A_C - A_D - B_D;

				m_dXpos = CX - B_D;
				m_dYpos = m_dYpos + B_C;
				m_dStartDir = 270;
			}
			else if(next_turn == 90 )//go right
			{
				double A_C = VSmps;
				double B_D = (itr->getnumlanesNS() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = m_dXpos - CX;
				double B_C = A_C - A_D + B_D;

				m_dXpos = CX + B_D;
				m_dYpos = m_dYpos - B_C;
				m_dStartDir = 90;
			}
			turndecided_flag = false;
		}
	
	}
	//dir == south(270)
	else
	{
		//variable for east direction
		//data garthering here
		BC = (itr->getnumelanesEW() == 4)?(LaneWidth * 2.0):(LaneWidth * 1.0);
		AC = itr->getYpos() - m_dYpos; 
		double AB = AC - BC; //distant from current x to next intersection center x
		speed_algorithm(itr, TLstat, TSDSL, AB, SLmps, TSDVS, m_dAcc);
		m_dXpos = m_dXpos;	//set x pos of vehicle
		m_dYpos = m_dYpos + VSmps;	//keep y pos same  

		//turn 
		if(m_dYpos > CY)
		{
			if(next_turn == 0 )//go left
			{
				double A_C = VSmps;
				double B_D = (itr->getnumelanesEW() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = CY - m_dYpos;
				double B_C = A_C - A_D - B_D;

				m_dXpos = m_dXpos + B_C;
				m_dYpos = CY + B_D;
				m_dStartDir = 0;
			}
			else if(next_turn == 180 )//go right
			{
				double A_C = VSmps;
				double B_D = (itr->getnumelanesEW() == 4)?(LaneWidth * 1.5):(LaneWidth * 0.5);
				double A_D = CY - m_dYpos;
				double B_C = A_C - A_D + B_D;

				m_dXpos = m_dXpos - B_C;
				m_dYpos = CY-B_D;//m_dYpos +B_C;
				m_dStartDir = 180;
			}
			turndecided_flag = false;
		}
	}
}

double Movement_LargeTruck::setNextTurn(Intersection* itr, double m_dStartDir)
{
	string north = "";
	string east = "";
	string south = "";
	string west = "";

	//set for each road;
	north = itr->getroadN();
	east = itr->getroadE();
	south = itr->getroadS();
	west = itr->getroadW();
	double direction;
	bool left = false;
	bool right = false;
	bool straight= false;
	//go east
	if(m_dStartDir == 0)
	{
		if(east.empty() != true)
			{
				straight = true;
			}
		if(south.empty() != true)
			{
				right = true;
			}
		if(north.empty() != true)
			{
				left = true;
			}
	}
	//go north
	else if(m_dStartDir == 90)
	{
		if(east.empty() != true)
			{
				right = true;
			}
		if(north.empty() != true)
			{
				straight = true;
			}
		if(west.empty() != true)
			{
				left = true;
			}
	}
	//go west
	else if(m_dStartDir == 180)
	{
		if(south.empty() != true)
			{
				left = true;
			}
		if(north.empty() != true)
			{
				right = true;
			}
		if(west.empty() != true)
			{
				straight = true;
			}
	}
	//go south
	else
	{
		if(south.empty() != true)
			{
				straight = true;
			}
		if(east.empty() != true)
			{
				left = true;
			}
		if(west.empty() != true)
			{
				right = true;
			}
	}

	if(left == false && right == false && straight == true)
	{
		direction = 0;
	}
	else if(left == true && right == false && straight == false)
	{
		direction = 90;
	}
	else if(left == false && right == true && straight == false)
	{
		direction = -90;
	}
	else if(left == true && right == true && straight == true)
	{
		int intValue = (rand() % 9)+1;
		if(intValue >= 1 && intValue <= 3)
		{
			direction = 90;
		}
		else if(intValue >= 4 && intValue <= 6)
		{
			direction = -90;
		}
		else
		{
			direction = 0;
		}
	}
	else if(left == true && right == false && straight == true)
	{
		int intValue = (rand() % 9)+1;
		if(intValue >= 1 && intValue <= 4)
		{
			direction = 90;
		}
		if(intValue >= 5 && intValue <= 10)
		{
			direction = 0;
		}
	}
	else if(left == false && right == true && straight == true)
	{
		int intValue = (rand() % 9)+1;
		if(intValue >= 1 && intValue <= 4)
		{
			direction = -90;
		}
		if(intValue >= 5 && intValue <=10)
		{
			direction = 0;
		}
	}
	else if(left == true && right == true && straight == false)
	{
		int intValue = (rand() % 9)+1;
		if(intValue >= 1 && intValue <= 5)
		{
			direction = 90;
		}
		if(intValue>=6 && intValue <=10)
		{
			direction = -90;
		}
	}

	//return something
	return direction;
}
void Movement_LargeTruck::speed_algorithm(Intersection* itr, int TLstat, double TSDSL, double AB, double SLmps, double &TSDVS, double m_dAcc)
{
	if((TLstat == 2) || (TLstat == 1))	//light is red and amber
	{
		if(TSDSL < AB)	//check if it is still far away from intersection
		{
			if(VSmps < SLmps)	//still far away, increase speed 
			{
				VSmps += m_dAcc;	//increase speed by value of acceleration
				VSmph = VSmps/0.44704;	//convert to mile per hour
				if(VSmps > SLmps)//check speed limit
				{
					VSmps = SLmps;
					VSmph = VSmps/0.44704;
				}		
			}
			
		}
		//if dis to stop > dist to intersection then decelerate
		else if((TSDVS > AB) && (VSmps !=0))//this is else for if(TSDSL < AB)
		{
			while((TSDVS > AB) && (AB > 3.6) && (VSmps > 0))
			{
				VSmps -= m_dAcc;
				VSmph = VSmps/0.44704;
				if(VSmps<0)
				{
					VSmps = 0;
					VSmph = 0;
				}
				TSDVS = 1.1 * VSmph + 0.06 * VSmph * VSmph;
				TSDVS *= 0.3048; //convert mile to meter
				if(VSmps == 0) break;
			}	
		}
		if(AB < 3.6)
		{
			VSmps = 0;
			VSmph = 0;
		}
	}
	else//ligh is green
	{
		if(VSmps < SLmps)
		{
			VSmps = VSmps + m_dAcc;
			VSmph = VSmps/0.44704;
			if(VSmps > SLmps)
			{
				VSmps = SLmps;
				VSmph = VSmps/0.44704;
			}
		}

	}
	//set vehicle speed in vehicle object
	m_dMPH = VSmph;//set new mile per hour to vehicle
	m_dMPS = VSmps;//set new meter per sec to vehicle
}
