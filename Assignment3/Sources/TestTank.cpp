#include <bits/stdc++.h>

#include "TestTank.h"
#include "Bullet.h"

using namespace std;

bool TestTank::TestMove(Tank a)
{
	Vector change;
	change.setX(0);
	change.setY(-1);
	change.setZ(-2);
	a.Move("up",change);
	Vector ans = a.getCentre();
	bool firstcheck = (ans.getX()==1) && (ans.getY()==1) && (ans.getZ()==1);

	a.Move("right",change);
	Vector ans2 =  a.getCentre();
	bool secondcheck = (a.getDirection() == "right") && (ans2.getX()==1) && (ans2.getY()==1) && (ans2.getZ()==1);
	return (firstcheck && secondcheck);
}

bool TestTank::TestShoot(Tank a)
{
	vector<Bullet> bulls ;
	cout<<"InitialSize  "<<bulls.size()<<endl;
	a.Shoot(bulls);
	cout<<"Final Size   "<<bulls.size()<<endl;
	return ((bulls.size()==1) &&(bulls[0].getDirection()==a.getDirection()));
}

bool TestTank::TestCollideWithTank(Tank a , Tank b)
{
	vector<Tank> t;
	t.push_back(b);
	return a.CollideWithTank(t);
}



int main()
{
	TestTank testt;
	Tank a ;
	a.setUserID("user1");
	a.setTankID("Tank1");
	Vector centre;
	centre.setX(1);
	centre.setY(2);
	centre.setZ(3);

	Tank b ;
	b.setUserID("user1");
	b.setTankID("Tank2");
	Vector centre1;
	centre1.setX(1);
	centre1.setY(1.9);
	centre1.setZ(3);

	a.setDirection("up");
	a.setCentre(centre);
	b.setCentre(centre1);
	cout<<testt.TestMove(a)<<"   Move Function Testing"<<endl;
	cout<<testt.TestShoot(a)<<" Shoot Function Testing"<<endl;
	cout<<testt.TestCollideWithTank(a,b)<<" Collision Testing"<<endl;
	//cout<<testt.TestTakePowerUp()
}