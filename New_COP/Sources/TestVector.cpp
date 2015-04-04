#include <bits/stdc++.h>
#include "TestVector.h"
#include "Vector.h"
using namespace std;

bool TestVector::TestAddVector(Vector a , Vector b)
{
	double one = a.getX() + b.getX();
	double two = a.getY() + b.getY();
	double three = a.getZ() + b.getZ();

	Vector ans = a.AddVector(b);

	bool fir = (one==ans.getX());
	bool sec = (two==ans.getY());
	bool third = (three==ans.getZ());

	return (fir && sec && third);
}



bool TestVector::TestSubVector(Vector a , Vector b)
{
	double one = a.getX() - b.getX();
	double two = a.getY() - b.getY();
	double three = a.getZ() - b.getZ();

	Vector ans = a.SubVector(b);

	bool fir = (one==ans.getX());
	bool sec = (two==ans.getY());
	bool third = (three==ans.getZ());

	return (fir && sec && third);
}

int main()
{
	Vector a ;
	Vector b;

	a.setX(1);
	a.setY(2);
	a.setZ(3);

	b.setX(2);
	b.setY(3);
	b.setZ(4);

	TestVector test;

	cout<<test.TestAddVector(a,b)<<endl;
	cout<<test.TestSubVector(a,b)<<endl;

}