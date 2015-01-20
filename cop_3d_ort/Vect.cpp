
#include <bits/stdc++.h>
#include "Vect.h"
using namespace std;

Vect::Vect(double x1, double y1, double z1)
{
	x=x1;
	y=y1;
	z=z1;
}

double Vect::dot(Vect* a)
{
	return x*a->x + y*a->y + z*a->z; 
}

double Vect::magnitude()
{
	return sqrt(x*x + y*y +z*z);
} 	

Vect* Vect::addVect(Vect* a)
{
	Vect* b = new Vect(0,0,0);
	b->x = a->x + x;
	b->y = a->y + y;
	b->z = a->z + z;
	return b;
}

Vect* Vect::subVect(Vect* a)
{
	Vect* b = new Vect(0,0,0);
	cout<< x << " sep "<< a->x << endl;
	b->x = x-a->x;
	b->y = y-a->y;
	b->z = z-a->z;
	cout<<"it does not end"<<endl;
	return b;
}

Vect* Vect::multVect(double a)
{
	Vect* b = new Vect(0,0,0);
	b->x = a*x;
	b->y = a*y;
	b->z = a*z;
	return b;
}
