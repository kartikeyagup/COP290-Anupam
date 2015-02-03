#ifndef RECTANGLE
#include <bits/stdc++.h>
#include "Rectangle1.h"
using namespace std;
#endif


Rectangle::Rectangle()
{
	length = 10;
	width = 10;
	rcolour = 1;
	gcolour = 1;
	bcolour = 1;
	xcord = 1;
	ycord = 1;
}

void Rectangle::Rectang(double l, double w,double rcolor,double gcolor, double bcolor,double x, double y)
{
	length = l;
	width = w;
	rcolour=rcolor;
	gcolour=gcolor;
	bcolour=bcolor; 
	xcord = x;
	ycord = y;
	//vertices = new pair<double , double >[4];
	vertices[0]=make_pair(x-l/2,y-w/2);
	vertices[1]=make_pair(x+l/2,y-w/2);
	vertices[2]=make_pair(x+l/2,y+w/2);
	vertices[3]=make_pair(x-l/2,y+w/2);
}
