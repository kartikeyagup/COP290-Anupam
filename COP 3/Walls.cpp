#include <bits.stdc++.h>

#include "Walls.h"
#include "Vectoh.h"
#include "Tank.h"

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

string Walls::getPosition()
{
	return Position;
}

bool Walls::getDeathStatus()
{
	return DeathStatus;
}

bool Walls::CollideWithBullets(vector<Bullet> bullets)
{
	for(int i=0;i<bullets.size();i++)
	{
		if((abs(Position-bullets[i].getPosition())<dis) && (Type=="brick") )
		{
			DeathStatus = true;
			return true;
		}
	}
	return false;
}
