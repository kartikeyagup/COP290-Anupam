#include <bits/stdc++.h>

#include <PowerUps.h>
#include "Tank.h"
#include "Board.h"

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

bool PowerUp::TakenByTank(Board back)
{
	vector<Tank> tanks = back.getTanks();
	for(int i=0;i<tanks.size();i++)
	{
		if(abs(Position - tanks[i].getCentre())< dis)
		{
			// the poweup is taken by the tank
			return true;
		}
	}
	return false;
}