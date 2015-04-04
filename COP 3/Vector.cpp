#include <bits/stdc++.h>

#include "Vector.h"

Vector::Vector()
{

}

void Vector::setX(double xc)
{
	X= xc;
}

void Vector::setY(double yc)
{
	Y = yc;
}

void Vector::setZ(double zc)
{
	Z = zc;
}

Vector Vector::AddVector(Vector toadd)
{
	double newx = X + toadd.getX();
	double newy = Y + toadd.getY();
	double newz = Z + toadd.getZ();
	Vector newvect;
	newvect.setX(newx);
	newvect.setY(newy);
	newvect.setZ(newz);
	return newvect; 
}

Vector Vector::SubVector(Vector tosub)
{
	double newx = X - tosub.getX();
	double newy = Y - tosub.getY();
	double newz = Z - tosub.getZ();
	Vector newvect;
	newvect.setX(newx);
	newvect.setY(newy);
	newvect.setZ(newz);
	return newvect; 
}
