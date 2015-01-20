#include <bits/stdc++.h>

using namespace std;
#include "Rectangle1.h"

struct Message
{
	string type;
	double xcord , ycord , xspeed , yspeed,radius;
	int label;
};

class Circle
{
	public:
		int label;
		double radius;
		//int colour;
		double xspeed;
		double yspeed;
		double xcord;
		double ycord;
		double acc_y;
		double pau;
		Circle(double rad,double xs,double ys,double xc,double yc);
		void Move(/*double maxxspeed*/);
		pair<double,double> Collision(Message b/*,int& ch,bool& colli,bool& collj*/);
		void Reflection(Rectangle a,bool ref);
};
