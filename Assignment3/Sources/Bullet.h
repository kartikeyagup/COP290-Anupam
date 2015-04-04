#ifndef BULLET_H
#define BULLET_H
#include <bits/stdc++.h>

#include "Vector.h"
#include "Tank.h"
#include "Walls.h"



using namespace std;

class Walls;
class Tank;
class Bullet
{
	private:
		Vector Position	;
		string Type;
		string BulletID;
		string UserID;
		Vector Velocity;
		string Direction;
		bool DeathStatus;

	public:
		Bullet();
		void setPosition(Vector pos);
		void setType(string type);
		void setBulletID(string id);
		void setUserID(string user);
		void setVelocity(Vector vel);
		void setDirection(string dire);
		void setDeathStatus(bool life);

		Vector getPosition();
		string getType();
		string getBulletID();
		string getUserID();
		Vector getVelocity();
		string getDirection();
		bool getDeathStatus();

		void Move(string);						//Move bullet.

		bool CollideWithTanks(vector<Tank>& tanks);      //Collision with tank
//		bool CollideWithTanks(Tank tank);	//Check if Bullet collides with tank. 
		bool CollideWithWalls(vector<Walls>&);	//Chechek if collides with wall.
		bool CollideWithBullet(vector<Bullet>&);	//Check if collides with another bullet.

};
#endif