#ifndef POWERUPS_H
#define POWERUPS_H
#include <bits/stdc++.h>

#include "Vector.h"
#include "Tank.h"



using namespace std;

class Tank;
class PowerUp
{
	private:
		string Type;
		string ID;
		Vector Position;
		bool DeathStatus;

	public:
		PowerUp();
		void setType(string type);
		void setID(string id);
		void setPosition(Vector pos);
		void setDeathStatus(bool life);

		string getType();
		string getID();
		Vector getPosition();
		bool getDeathStatus();

};
#endif