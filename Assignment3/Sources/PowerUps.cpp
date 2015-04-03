#include <bits/stdc++.h>


#include "Vector.h"
#include "Tank.h"
#include "Walls.h"
#include "Bullet.h"
#include "PowerUps.h"

PowerUp::PowerUp()
{

}

void PowerUp::setType(string type)
{
	Type = type;
}

void PowerUp::setID(string id)
{
	ID = id;
}

void PowerUp::setPosition(Vector pos)
{
	Position = pos;
}

void PowerUp::setDeathStatus(bool life)
{
	DeathStatus = life;
}

string PowerUp::getType()
{
	return Type;
}

string PowerUp::getID()
{
	return ID;
}

Vector PowerUp::getPosition()
{
	return Position;
}

bool PowerUp::getDeathStatus()
{
	return DeathStatus;
}

bool PowerUp::TakenByTank(vector<Tank> tanks)
{
	for(int i=0;i<tanks.size();i++)
	{
		if(Position.SubVector(tanks[i].getCentre()).Mod()< 100)
		{
			// the poweup is taken by the tank
			return true;
		}
	}
	return false;
}