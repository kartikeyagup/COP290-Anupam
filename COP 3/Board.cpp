#include <bits/stdc++.h>

#include "Vector.h"
#include "Tank.h"
#include "Bullet.h"
#include "Walls.h"
#include "PowerUps.h"

Board::Board()
{

}

void Board::setTanks(vector<Tank> tanks)
{
	Tanks =  tanks;
}

void Board::setBricks(vector<Walls> walls)
{
	Walls = walls;
}

void Board::setPowerUps(vector<PowerUp> powers)
{
	PowerUps = powers;
}

void Board::setBullets(vector<Bullet> bullets)
{
	Bullets = bullets;
}

vector<Tank> Board::getTanks()
{
	return Tanks;
}

vector<Walls> Board::getBricks()
{
	return Bricks;
}

vector<PowerUp> Board::getPowerUps()
{
	return PowerUps;
}

vector<Bullet> Board::getBullets()
{
	return Bullets;
}


Board GiveChanges()
{
	 Board a ;

	for(int i=0;i<Tanks.size();i++)
	{
		if(Tanks[i].getUserID()== PlayerID)
		{
			bool colwithwalls  = Tanks[i].CollideWithWalls(Bricks);
			bool colwithtanks = Tanks[i].CollideWithTank(Tanks);
			bool colwithbullets = Tanks[i].CollideWithBullets(Bullets);
			if(colwithbullets) a.setTanks(a.getTanks().push_back(Tanks[i]));
			if((!colwithwalls) && (!colwithtanks) && (!colwithbullets))
			{
				Tanks[i].Move();
				a.setTanks(a.getTanks().push_back(Tanks[i]))
			}
		}
	}

	for(int i=0;i<Bullets.size();i++)
	{
		if(Bullets[i].getUserID()== PlayerID)
		{
			bool colwithwalls = Bullets[i].CollideWithWalls(Bricks);
			bool colwithtanks = Bullets[i].CollideWithTank(Tanks);
			bool colwithbullets = Bullets[i].CollideWithBullets(Bullets);
			if((!colwithwalls) && (!colwithtanks) && (!colwithbullets))
			{
				Bullets[i].Move();
				a.setBullets(a.getBullets().push_back(Bullets[i]));
			}
			else
			{
				a.setBullets(a.getBullets().push_back(Bullets[i]));
			}
		}
	}

	for(int i=0;i<Bricks.size();i++)
	{
		if(Bricks[i].getDeathStatus()==true)
		{
			a.setBricks(a.getBricks().push_back(Bricks[i]));
		}
	}

	for(int i=0;i<PowerUps.size();i++)
	{
		if(PowerUps[i].getDeathStatus()==true)
		{
			a.setPowerUps(a.getPowerUps().push_back(PowerUps[i]));
		}
	}

	return a;
}


void UpdateBoard(Board change)
{
	vector<Tank> tanks = change.getTanks();
	vector<Walls> walls = change.getBricks();
	vector<Bullet> bullets = change.getBullets();
	vector<PowerUp> poweups = change.getPowerUps();
	for(int i=0;i<tanks.size();i++)
	{
		for(int j=0;j<Tanks.size();j++)
		{
			if(tanks[i] == Tanks[j])
			{
				if(tanks[i].getDeathStatus()==1)
				{
					Tanks.erase(j);
				}
				else
				{
					Tanks[j]=tanks[i];
				}
			}
		}
	}

	for(int i=0;i<bullets.size();i++)
	{
		for(int j=0;j<Bullets.size();j++)
		{
			if(bullets[i] == Bullets[j])
			{
				if(bullets[i].getDeathStatus()==1)
				{
					Bullets.erase(j);
				}
				else
				{
					Bullets[j]=bullets[i];
				}
			}
		}
	}

	for(int i=0;i<walls.size();i++)
	{
		for(int j=0;j<Bricks.size();j++)
		{
			if(walls[i] == Bricks[j])
			{
				if(walls[i].getDeathStatus()==1)
				{
					Bricks.erase(j);
				}
				else
				{
					Bricks[j]=walls[i];
				}
			}
		}
	}

	for(int i=0;i<powerups.size();i++)
	{
		for(int j=0;j<PowerUps.size();j++)
		{
			if(powerups[i] == PowerUps[j])
			{
				if(powerups[i].getDeathStatus()==1)
				{
					PowerUps.erase(j);
				}
				else
				{
					PowerUps[j]=powerups[i];
				}
			}
		}
	}
}

