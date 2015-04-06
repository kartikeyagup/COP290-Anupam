#include <bits/stdc++.h>


//TODO : add other haeder files , FOR OTHER FILES , DO THE SAME THING TOO


#include "Vector.h"
#include "Tank.h"
#include "Bullet.h"
#include "Walls.h"
#include "PowerUps.h"

Bullet::Bullet()
{
	//cout<<"Bullet created successfully"<<endl;
}


void Bullet::setPosition(Vector pos)
{
	Position = pos;
}

void Bullet::setType(string type)
{
	Type = type;
}

void Bullet::setBulletID(string id)
{
	BulletID = id;
}

void Bullet::setUserID(string user)
{
	UserID = user;
}

void Bullet::setVelocity(Vector vel)
{
	Velocity = vel;
}


void Bullet::setDeathStatus(bool life)
{
	DeathStatus = life;
}

void Bullet::setDirection(string dire)
{
	Direction = dire;
}

Vector Bullet::getPosition()
{
	return Position;
}

string Bullet::getType()
{
	return Type;
}

string Bullet::getBulletID()
{
	return BulletID;
}

string Bullet::getUserID()
{
	return UserID;
}

Vector Bullet::getVelocity()
{
	return Velocity;
}

bool Bullet::getDeathStatus()
{
	return DeathStatus;
}

string Bullet::getDirection()
{
	return Direction;
}

void Bullet::Move(string dire)
{

	Vector change;
	change.setX(0);
	change.setY(0);
	change.setZ(0);

	if(dire=="up")
	{
		change.setY(20);
	}
	else if(dire == "down")
	{
		change.setY(-20);
	}
	else if(dire=="left")
	{
		change.setX(-20);
	}

	else if(dire== "right")
	{
		change.setX(20);
	}

	if(Direction == dire)
	{
		Position = Position.AddVector(change);
	}
	else 
	{
		Direction = dire;
	}
}

bool Bullet::CollideWithTanks(vector<Tank>& tanks)
{
	for(int i=0;i<tanks.size();i++)
	{
		if((Position.SubVector(tanks[i].getCentre()).Mod()<100) && (UserID != tanks[i].getUserID()))
		{
			DeathStatus = true;
			return true;
		}
	}
	return false;
}

bool Bullet::CollideWithWalls(vector<Walls>& w)
{

	for(int i=0;i<w.size();i++)
	{
		if(Position.SubVector(w[i].getPosition()).Mod()<1)
		{
			DeathStatus = true;
			return true;
		}
	}
	return false;
	/*TODO : modify the maths part . Area A divided into m*n square for walls
			for a position (x,y), it lies inside the square number (x mod n , y mod m)
	*/

	/*if(Direction=="up")
	{
		if(Position.getY()==0)
		{
			DeathStatus = true;
			return true;
		}

	}

	else if(Direction=="down")
	{
		if((Position.getY()%Rows)==Rows - 1)
		{
			DeathStatus = true;
			return true;
		}
	}

	else if(Direction=="right")
	{
		if(Position.getX()==Columns-1)
		{
			DeathStatus = true;
			return true;
		}
	}

	else if(Direction == "left")
	{
		if(Position.getX()==0)
		{
			DeathStatus = true;
			return true;
		}
	}

	else if(BrickFilled[(Position.getX()%Columns)*(Position.getY()%Rows)]!=0)
	{
		DeathStatus = true;
		return true;
	}	
	
	else return false;*/
}

bool Bullet::CollideWithBullet(vector<Bullet>& bullets)
{
	for(int i=0;i<bullets.size();i++)
	{
		if((Position.SubVector(bullets[i].getPosition()).Mod()< 100) && (BulletID != bullets[i].getBulletID()))
		{
			//bullet collides with another bullet i
			DeathStatus= true;
			return true;
		}
	}
	return false;
}
