#ifndef BOARD_H
#define BOARD_H
#include <bits/std.c++>

using namespace std;

class Board
{
	private:
		vector<Tank> Tanks;
		vector<Walls> Bricks;
		vector<PowerUp> PowerUps;
		vector<Bullet> Bullets;
		string UserID;
		int Rows;
		int Columns;
		int BrickFilled[Rows*Columns];

	public:
		Board();
		void setTanks(vector<Tank> ts);
		void setBricks(vector<Walls> brs);
		void setPowerUps(vector<PowerUp> pups);
		void setBullets(vector<Bullet> buls);
		void setUserID(string user);

		vector<Tank> getTanks();
		vector<Walls> getBricks();
		vector<PowerUp> getPowerUps();
		vector<Bullet> getBullets();
		string getUserID();

		Board GiveChanges()					//Tells the changes to be made in the board.
		void UpdateBoard(Board change);		//Update the board with the change provided. 	
};
#endif