#include <bits/stdc++.h>

using namespace std;
#include "Rectangle.h"
//#include "Vect.h"


struct Message 
{
	Vect* position;
	Vect* speed;
	double radius;
};


class Circle
{
	public:

		double radius;
		Vect* position;
		Vect* speed;
		Circle(double rad, Vect* pos ,Vect* sp);
		void Move(/*double maxxspeed*/);
		int Collision(Message b);
		void Reflection(Rectangle a);
		Vect* pointcollision(Message b);
};
