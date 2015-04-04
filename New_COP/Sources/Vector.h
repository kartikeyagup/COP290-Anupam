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
		void setX(double);
		void setY(double);
		void setZ(double);


		double getX();
		double getY();
		double getZ();

		Vector AddVector(Vector toadd);	//Adds Vector toadd	
		Vector SubVector(Vector tosub); //Subtracts Vector tosub
		double Mod();

};
#endif