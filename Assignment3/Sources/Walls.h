#ifndef WALLS_H
#define WALLS_H
#include <bits/stdc++.h>

using namespace std;

#include "Vector.h"
#include "Bullet.h"


class Bullet;
class Walls
{
	private:

		string Type;
		string ID;
		Vector Position;
		bool DeathStatus;

	public:
		Walls();
		void setType(string type);
		void setID(string id);
		void setPosition(Vector pos);
		void setDeathStatus(bool life);


		string getType();
		string getID();
		Vector getPosition();
		bool getDeathStatus();

		bool CollideWithBullets(vector<Bullet>&);

};
#endif