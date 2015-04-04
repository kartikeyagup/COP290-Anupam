#ifndef POWERUPS_H
#define POWERUPS_H
#include <bits/stdc++.h>

using namespace std;

class PowerUp
{
	private:
		string Type;
		string ID;
		Vector Position;

	public:
		PowerUp();
		void setType(string type);
		void setID(string id);
		void setPosition(Vector pos);

		string getType();
		string getID();
		Vector getPosition();

		bool TakenByTank(Board back);	//Power up taken by tank.
};
#endif