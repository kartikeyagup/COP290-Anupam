
#include <bits/stdc++.h>

using namespace std;

class Vect
{
	public:

		double x;
		double y;
		double z;
		Vect(double x1 , double y1, double z1);
		double dot(Vect* a);
		double magnitude();
		Vect* addVect(Vect* a);
		Vect* subVect(Vect* a);
		Vect* multVect(double a);
};	
