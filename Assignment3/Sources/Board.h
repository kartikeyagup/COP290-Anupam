#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h>


#include "Vector.h"
#include "Tank.h"
#include "Walls.h"
#include "Bullet.h"
#include "PowerUps.h"



using namespace std;

class Board
{
	private:
		vector<Tank> Tanks;
		vector<Walls> Bricks;
		vector<PowerUp> PowerUps;
		vector<Bullet> Bullets;
		string PlayerID;
		int Rows;
		int Columns;
		Vector Colour;
		vector<Vector> Vertices;
		int* BrickFilled;
		double x;
		double y;

	public:
		Board();
		void setTanks(vector<Tank> ts);
		void setBricks(vector<Walls> brs);
		void setPowerUps(vector<PowerUp> pups);
		void setBullets(vector<Bullet> buls);
		void setPlayerID(string user);
		void setColour(Vector);
		void setVertices(vector<Vector>);

		vector<Tank> getTanks();
		vector<Walls> getBricks();
		vector<PowerUp> getPowerUps();
		vector<Bullet> getBullets();
		string getPlayerID();
		Vector getColour();
		vector<Vector> getVertices();

		Board GiveChanges(vector< pair<string,string> > , vector< pair<string,string> >);				//Tells the changes to be made in the board.
		void UpdateBoard(Board change);		//Update the board with the change provided. 	
};
#endif