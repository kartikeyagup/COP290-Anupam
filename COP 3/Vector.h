#ifndef VECTOR_H
#define VECTOR_H
#include <bits/stdc++.h>

using namespace std;

class Vector
{
	private:
		double X;
		double Y;
		double Z;
	public:
		Vector();
		void getX(double xc);
		void getY(double yc);
		void getZ(double zc);

		double getX();
		double getY();
		double getZ();

		Vector AddVector(Vector toadd);	//Adds Vector toadd	
		Vector SubVector(Vector tosub); //Subtracts Vector tosub

};
#endif