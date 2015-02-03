#ifndef Rectangle_h
#include <bits/stdc++.h>

using namespace std;

class Rectangle
{
	public:

		double length;
		double width;
		double xcord;
		double ycord;
		double rcolour;
		double gcolour;
		double bcolour;
		pair<double,double> vertices[4];
		Rectangle();
		void Rectang(double l, double w,double rcolor,double gcolor, double bcolor,double x, double y);
};
#endif
