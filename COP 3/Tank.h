#ifndef TANK_H
#define TANK_H
#include <bits/stdc++.h>

using namespace std;

class Tank
{
	private:
		Vector CentrePosition;
		Vector Dimensions;
		Vector Velocity;
		string UserID;
		string TankID;
		bool DeathStatus;
		PowerUp PowerUp;
		string Direction;
	public:
		Tank();
		void setCentre(Vector centre);
		void setDimensions(Vector dimen);
		void setVelocity(Vector vel);
		void setUserID(string user);
		void setTankID(string tank);
		void setDeathStatus(bool life);
		void setPowerUp(string power);
		void setDirection(string dire);

		Vector getCentre();
		Vector getDimensions();
		Vector getVelocity();
		string getUserID();
		string getTankID();
		bool getDeathStatus();
		string getPowerUp();
		string getDirection();
		s

		void Move(Vector change);					//Required to move tank.
		void Shoot();								//Shoot  bullet.
		void ApplyPower(PowerUp pow);					//Applies power up.
		bool CollideWithWall(Board back);			//Check if collides with wall.
		bool CollideWithTank(Board back);		//Check if collides with other tank.
		bool CollideWithBullet(Board back);		//Check if collides with a bullet.
		bool TakePowerUp(vector<PowerUp> powerups);	//Pick up Power Up.
};
#endif