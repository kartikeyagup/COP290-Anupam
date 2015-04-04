#ifndef WALLS_H
#define WALLS_H
#include <bits/stdc++.h>

using namespace std;

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

};
#endif