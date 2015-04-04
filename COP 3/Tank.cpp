#include <bits/stdc++.h>
#include "Vector.h"
#include "Tank.h"

using namespace std;

Tank::Tank()
{

}

void Tank::setCentre(Vector pos)
{
	CentrePosition = pos;
}

void Tank::setDimensions(Vector dim)
{
	Dimensions = dim;
}

void Tank::setVelocity(Vector vel)
{
	Velocity = vel;
}

void Tank::setUserID(string user)
{
	UserID = user;
}

void Tank::setTankID(string tank)
{
	TankID = tank;
}

void Tank::setDeathStatus(bool life)
{
	DeathStatus =  life;
}

void Tank::setPowerUp(PowerUp power)
{
	PowerUp = power;
}

void Tank::setDirection(string dire)
{
	Direction = dire;
}

Vector Tank::getCentre()
{
	return CentrePosition;
}

Vector Tank::getDimensions()
{
	return Dimensions;
}

Vector Tank::getVelocity()
{
	return Velocity;
}

string Tank::getUserID()
{
	return UserID;
}

string Tank::getTankID();
{
	return TankID;
}

bool Tank::getDeathStatus()
{
	return DeathStatus;
}

PowerUp Tank::getPowerUp()
{
	return PowerUp;
}

string Tank::getDirection()
{
	return Direction;
}

void Tank::Move(string dire, Vector change, Board back)
{

		if(Direction == dire)
		{
			CentrePosition = CentrePosition.AddVector(change);
		}
		else 
		{
			Direction = dire;
		}
}

void Tank::Shoot(Board back)
{
	Bullet bull;
	bull.Direction = Direction;
	bull.setUserID(UserID);
	back.setBullets(back.getBullets().push_back(bull));
}

void Tank::ApplyPower(PowerUp pow);
{
	PowerUp = pow;
}

bool Tank::CollideWithWalls(int* BrickFilled, int Rows,  int Columns)
{
	if(Direction=="up")
	{
		if(Position.getY()==0) return true;
		else if(BrickFilled[Position.getX()*(Position.getY()-1)]!=0) return true;
		else return false;
	}

	else if(Direction=="down")
	{
		if(Position.getY()==Rows - 1) return true;
		else if(BrickFilled[CentrePosition.getX()*(CentrePosition.getY()+1)]!=0) return true;
		else return false;
	}
	else if(Direction=="right")
	{
		if(Position.getX()==Columns-1) return true;
		else if(BrickFilled[(Position.getX()+1)*Position.getY()]!=0) return true;
		else return false;
	}
	else if(Direction == "left")
	{
		if(Position.getX()==0) return true;
		else if(BrickFilled[(Position.getX()-1)*Position.getY()]!=0) return true;
		else return false;
	}
}

bool Tank::CollideWithTank(vector<Tank> tanks)
{
	for(int i=0;i<tanks.size();i++)
	{
		if((abs(CentrePosition - tanks[i].getCentre())< dis) &&  (TankID != tanks[i].getTankID))
		{
			return true;
		}
	}
	return false;
}

bool Tank::CollideWithBullet(vector<Bullet> bullets)
{
	for(int i=0;i<bullets.size();i++)
	{
		if((abs(CentrePosition - bullets[i].getPosition())< dis) && (PowerUp != "immune") && (UserID != bullets[i].getUserID()`122))
		{
			//bullet is not destroyed here as it does not belong to the user 1 It will be destroyed by its owner in same cycle.
			DeathStatus = true; 
			return true;
		}
	}
	return false;
}

bool Tank::TakePowerUp(vector<PowerUp> powerups)
{
	for(int i=0;i<powerups.size();i++)
	{
		if(abs(CentrePosition - powerups[i].getPosition())< dis)
		{
			PowerUp = powerups[i];
			return true;
		}
	}
	return false;
}
