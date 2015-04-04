#include <bits/stdc++.h>



#include "Vector.h"
#include "Tank.h"
#include "Walls.h"
#include "Bullet.h"
#include "PowerUps.h"


Walls::Walls()
{

}

void Walls::setType(string type)
{
	Type = type;
}

void Walls::setID(string id)
{
	ID= id;
}

void Walls::setPosition(Vector pos)
{
	Position = pos;
}

void Walls::setDeathStatus(bool life)
{
	DeathStatus = life; 
}

string Walls::getType()
{
	return Type;
}

string Walls::getID()
{
	return ID;
}

Vector Walls::getPosition()
{
	return Position;
}

bool Walls::getDeathStatus()
{
	return DeathStatus;
}

bool Walls::CollideWithBullets(vector<Bullet>& bullets)
{
	for(int i=0;i<bullets.size();i++)
	{
		if((Position.SubVector(bullets[i].getPosition()).Mod()<100) && (Type=="brick") )
		{
			DeathStatus = true;
			return true;
		}
	}
	return false;
}
