#ifndef BULLET_H
#define BULLET_H
#include bits/stdc++.h>

using namespace std;

class Bullet
{
	private:
		Vector Position;
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
		bool setDeathStatus(bool life);

		Vector getPosition();
		string getType();
		string getBulletID();
		string getUserID();
		Vector getVelocity();
		string getDirection();
		bool getDeathStatus();

		void Move(string , Vector);						//Move bullet.
//		bool CollideWithTanks(Tank tank);	//Check if Bullet collides with tank. 
		bool CollideWithWall(Board);	//Chechek if collides with wall.
		bool CollideWithBullet(Board);	//Check if collides with another bullet.

};
#endif