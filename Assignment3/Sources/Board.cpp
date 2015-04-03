#include <bits/stdc++.h>

#include "Vector.h"
#include "Tank.h"
#include "Board.h"
#include "Walls.h"
#include "Bullet.h"
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
	Bricks = walls;
}

void Board::setPowerUps(vector<PowerUp> powers)
{
	PowerUps = powers;
}

void Board::setBullets(vector<Bullet> bullets)
{
	Bullets = bullets;
}

void Board::setColour(Vector col)
{
	Colour = col;
}

void Board::setVertices(vector<Vector> ver)
{
	Vertices = ver ;
}

void Board::setPlayerID(string p)
{
	PlayerID = p;
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

Vector Board::getColour()
{
	return Colour;
}

vector<Vector> Board::getVertices()
{
	return Vertices;
}

string Board::getPlayerID()
{
	return PlayerID;
}

Board Board::GiveChanges(Vector tankchange,Vector bullchange)
{
	 Board a ;

	for(int i=0;i<Tanks.size();i++)
	{
		if(Tanks[i].getUserID()== PlayerID)
		{
			bool colwithwalls  = Tanks[i].CollideWithWalls(Bricks);
			bool colwithtanks = Tanks[i].CollideWithTank(Tanks);
			bool colwithbullets = Tanks[i].CollideWithBullet(Bullets);
			if(colwithbullets) 
			{
				vector<Tank> t = a.getTanks();
				t.push_back(Tanks[i]); 
				a.setTanks(t);
			}
			if((!colwithwalls) && (!colwithtanks) && (!colwithbullets))
			{
				Tanks[i].Move("up",tankchange);
				vector<Tank> t = a.getTanks();
				t.push_back(Tanks[i]); 
				a.setTanks(t);
			}
		}
	}

	for(int i=0;i<Bullets.size();i++)
	{
		if(Bullets[i].getUserID()== PlayerID)
		{
			bool colwithwalls = Bullets[i].CollideWithWalls(Bricks);
			bool colwithtanks = Bullets[i].CollideWithTanks(Tanks);
			bool colwithbullets = Bullets[i].CollideWithBullet(Bullets);
			if((!colwithwalls) && (!colwithtanks) && (!colwithbullets))
			{
				Bullets[i].Move("up",bullchange);
				vector<Bullet> t = a.getBullets();
				t.push_back(Bullets[i]); 
				a.setBullets(t);
			}
			else
			{
				vector<Bullet> t = a.getBullets();
				t.push_back(Bullets[i]); 
				a.setBullets(t);
			}
		}
	}

	for(int i=0;i<Bricks.size();i++)
	{
		if(Bricks[i].getDeathStatus()==true)
		{
			vector<Walls> t = a.getBricks();
				t.push_back(Bricks[i]); 
				a.setBricks(t);
		}
	}

	for(int i=0;i<PowerUps.size();i++)
	{
		if(PowerUps[i].getDeathStatus()==true)
		{
			vector<PowerUp> t = a.getPowerUps();
				t.push_back(PowerUps[i]); 
				a.setPowerUps(t);
		
		}
	}

	return a;
}


void Board::UpdateBoard(Board change)
{
	vector<Tank> tanks = change.getTanks();
	vector<Walls> walls = change.getBricks();
	vector<Bullet> bullets = change.getBullets();
	vector<PowerUp> powerups = change.getPowerUps();
	for(int i=0;i<tanks.size();i++)
	{
		int j=0;
		while(j<Tanks.size())
		{
			if(tanks[i].getTankID() == Tanks[j].getTankID())
			{
				if(tanks[i].getDeathStatus()==1)
				{
					Tanks.erase(Tanks.begin()+j);
				}
				else
				{
					Tanks[j]=tanks[i];
				}
				break;
			}
			j++;
		}

		if(j==Tanks.size())
		{
			Tanks.push_back(tanks[i]);
		}
	}

	for(int i=0;i<bullets.size();i++)
	{
		int j=0;
		while(j<Bullets.size())
		{
			if(bullets[i].getBulletID() == Bullets[j].getBulletID())
			{
				if(bullets[i].getDeathStatus()==1)
				{
					Bullets.erase(Bullets.begin()+j);
				}
				else
				{
					Bullets[j]=bullets[i];
				}
				break;
			}
			j++;
		}
		if(j==Bullets.size())
		{
			Bullets.push_back(bullets[i]);
		}
	}

	for(int i=0;i<walls.size();i++)
	{
		int j=0;
		while(j<Bricks.size())
		{
			if(walls[i].getID() == Bricks[j].getID())
			{
				if(walls[i].getDeathStatus()==1)
				{
					Bricks.erase(Bricks.begin() + j);
				}
				else
				{
					Bricks[j]=walls[i];
				}
				break;
			}
			j++;
		}
		if(j==Bricks.size())
		{
			Bricks.push_back(walls[i]);
		}
	}

	for(int i=0;i<powerups.size();i++)
	{
		int j=0;
		while(j<PowerUps.size())
		{
			if(powerups[i].getID() == PowerUps[j].getID())
			{
				if(powerups[i].getDeathStatus()==1)
				{
					PowerUps.erase(PowerUps.begin() + j);
				}
				else
				{
					PowerUps[j]=powerups[i];
				}
				break;
			}
			j++;
		}
		if(j==PowerUps.size())
		{
			PowerUps.push_back(powerups[i]);
		}
	}
}



