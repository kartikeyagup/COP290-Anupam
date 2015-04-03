#ifndef TESTTANK_H
#define TESTTANK_H
#include <bits/stdc++.h>

#include "Tank.h"
#include "Bullet.h"

using namespace std;

class TestTank
{
	public :
		bool TestMove(Tank a);
		bool TestCollideWithTank(Tank a, Tank b);
		/*bool TestCollideWithBullet(Tank a , Bullet b);*/
		bool TestShoot(Tank a);
		//bool TestTakePowerUp(Tank a);
};
#endif