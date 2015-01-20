#include <bits/stdc++.h>

using namespace std;
#include "Rectangle.h"
//#include "Vect.h"

class Circle
{
	public:

		double radius;
		Vect* position;
		Vect* speed;
		Circle(double rad, Vect* pos ,Vect* sp);
		void Move(/*double maxxspeed*/);
		int Collision(Circle& b);
		void Reflection(Rectangle a);
		Vect* pointcollision(Circle &b);
};
