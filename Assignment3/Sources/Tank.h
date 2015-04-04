#ifndef TANK_H
#define TANK_H
#include <bits/stdc++.h>

#include "Vector.h"
#include "Walls.h"
#include "Bullet.h"
#include "PowerUps.h"


using namespace std;

class PowerUp;



class Tank
{
	private:
		Vector CentrePosition;
		Vector Dimensions;
		Vector Velocity;
		string UserID;
		string TankID;
		bool DeathStatus;
		PowerUp PowUp;
		string Direction;
		bool CreatedNow;
	public:

		Tank();
		void setCentre(Vector centre);
		void setDimensions(Vector dimen);
		void setVelocity(Vector vel);
		void setUserID(string user);
		void setTankID(string tank);
		void setDeathStatus(bool life);
		void setPowerUp(PowerUp power);
		void setDirection(string dire);

		Vector getCentre();
		Vector getDimensions();
		Vector getVelocity();
		string getUserID();
		string getTankID();
		bool getDeathStatus();
		PowerUp getPowerUp();
		string getDirection();

		void Move(string direction);					//Required to move tank.
		void Shoot(vector<Bullet>&);								//Shoot  bullet.
		void ApplyPower(PowerUp pow);					//Applies power up.
		bool CollideWithWalls(vector<Walls>&);			//Check if collides with wall.
		bool CollideWithTank(vector<Tank>&);		//Check if collides with other tank.
		bool CollideWithBullet(vector<Bullet>&);		//Check if collides with a bullet.
		bool TakePowerUp(vector<PowerUp>& powerups);	//Pick up Power Up.
};
#endif


