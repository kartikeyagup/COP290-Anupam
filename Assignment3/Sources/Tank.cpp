#include <bits/stdc++.h>

#include "Vector.h"
#include "Tank.h"
#include "Walls.h"
#include "Bullet.h"
#include "PowerUps.h"
#include "Graphicsrendering.h"


using namespace std;
extern string keypressed;

Tank::Tank()
{
	Vector mytankcentre;
    mytankcentre.setX(0);
    mytankcentre.setY(0);
    mytankcentre.setZ(0);
    CentrePosition = mytankcentre;
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
	PowUp = power;
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

string Tank::getTankID()
{
	return TankID;
}

bool Tank::getDeathStatus()
{
	return DeathStatus;
}

PowerUp Tank::getPowerUp()
{
	return PowUp;
}

string Tank::getDirection()
{
	return Direction;
}

void Tank::Move(string dire)
{

	change.setX(0.0);
	change.setY(0.0);
	change.setZ(0.0);
	if(keypressed == "left")
	{
		change.setX(-10.0)
	}
	else if(keypressed == "right")
	{
		change.setX(10.0);
	}
	else if (keypressed == "up")
	{
		change.setY(10.0);
	}
	else if(keypressed == "down")
	{
		change.setY(-10.0);
	}

	dire = keypressed;
	
	if(Direction == dire)
	{
		CentrePosition = CentrePosition.AddVector(change);
	}
	else 
	{
		Direction = dire;
	}
}

void Tank::Shoot(vector<Bullet>& newbulls)
{
	Bullet bull;
	bull.setDirection(Direction);
	bull.setUserID(UserID);
	newbulls.push_back(bull);

}

void Tank::ApplyPower(PowerUp pow)
{
	PowUp = pow;
}

bool Tank::CollideWithWalls(vector<Walls>& w)
{
	/*if(Direction=="up")
	{
		if(CentrePosition.getY()==0) return true;
		else if(BrickFilled[Position.getX()*(CentrePosition.getY()-1)]!=0) return true;
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
		else if(BrickFilled[(CentrePosition.getX()+1)*Position.getY()]!=0) return true;
		else return false;
	}
	else if(Direction == "left")
	{
		if(Position.getX()==0) return true;
		else if(BrickFilled[(CentrePosition.getX()-1)*Position.getY()]!=0) return true;
		else return false;
	}*/
		return false;
}

bool Tank::CollideWithTank(vector<Tank>& tanks)
{
	for(int i=0;i<tanks.size();i++)
	{
		cout<<(CentrePosition.SubVector(tanks[i].getCentre()).Mod())<<"     subvect"<<endl;
		if((CentrePosition.SubVector(tanks[i].getCentre()).Mod()< 1) &&  (TankID != tanks[i].getTankID()))
		{
			return true;
		}
	}
	return false;
}

bool Tank::CollideWithBullet(vector<Bullet>& bullets)
{
	for(int i=0;i<bullets.size();i++)
	{
		if((CentrePosition.SubVector(bullets[i].getPosition()).Mod()< 100) && (PowUp.getType() != "immune") && (UserID != bullets[i].getUserID()))
		{
			//bullet is not destroyed here as it does not belong to the user 1 It will be destroyed by its owner in same cycle.
			DeathStatus = true; 
			return true;
		}
	}
	return false;
}

bool Tank::TakePowerUp(vector<PowerUp>& powerups)
{
	for(int i=0;i<powerups.size();i++)
	{
		if(CentrePosition.SubVector(powerups[i].getPosition()).Mod()< 100)
		{
			PowUp = powerups[i];
			return true;
		}
	}
	return false;
}
