#include <bits/stdc++.h>

using namesapce std;

bool TestVector::TestAddVector(Vector a , Vector b)
{
	double one = a.getX() + b.getX();
	double two = a.getY() + b.getY();
	double three = a.getZ() + b.getZ();

	Vector ans = a.AddVector(b);

	cout<<((one==ans.getX()) && (two==ans.getY()) && (three.getZ()))<<endl;

}



bool TestVcetor::TestSubVector(Vector a , Vector b)
{
	double one = a.getX() - b.getX();
	double two = a.getY() - b.getY();
	double three = a.getZ() - b.getZ();

	Vector ans = a.AddVector(b);

	cout<<((one==ans.getX()) && (two==ans.getY()) && (three.getZ()))<<endl;
}