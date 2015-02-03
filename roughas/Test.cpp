#include <bits/stdc++.h>

using namespace std;

#include "Rectangle.cpp"
#include "Circle.cpp"
#include "Background.cpp"
#include "Rectangle.h"
#include "Circle.h"
#include "Background.h"

/*class Rectangle
{
	public:

		double length;
		double width;
		int colour;
		pair<int,int>* vertices;
		Rectangle();
};

Rectangle::Rectangle(int l, int w,int color)
{
	length = l;
	width = w;
	colour=color;
	vertices = new pair<int , int >*[4];
}

class Circle
{
	public:

		double radius;
		int colour;
		double xspeed;
		double yspeed;
		double xcord;
		double ycord;
		Circle();
		void Move(double xspeed,double yspeed);
		void Collision(Circle b);
		void Reflection(Rectangle a )
};

Circle::Circle(int rad,int color,int xs,int ys,int xc,int yc)
{
	radius = rad;
	colour = color;
	xspeed = xs;
	yspeed = ys;
	xcord = xc;
	ycord = yc;
}

void Circle::Move(double time)
{

	xcord += xspeed*time;
	ycord += yspeed*time;
}

void Circle::Collision(Circle b)
{
	double dist = sqrt(pow(xcord- b.xcord ,2) + pow(ycord - b.ycord ,2));
	double v1x =  xspeed, v1y = yspeed , v2x = b.xpeed, v2y= b.yspeed;

	if(dist <= radius + b.radius)									//radial velocity inverts
	{
		double sint = (ycord- b.ycord)/dist;
		double cost = (b.xcord - xcord)/dist;
		double radial1 = v1x*cost - v1y*sint;
		double tang1 = v1y*cost + v1x*sint;
		double radial2 =  v2x*cost - v2y*sint;
		double tang2 = v2y*cost + v2x*sint;
		swap(radial1,radial2);
		xspeed = radial1*cost + tang1*sint;
		b.xspeed = radial2*cost + tang2*sint;
		yspeed = tang1*cost - radial1*sint;
		b.yspeed = tang2*cost - radial2*sint;
	}
	bool a = (xcord = a.vertices[0].first + radius); 				//left line of rectangle
	bool b = (xcord + radius = a.vertices[1].first );				//right line
	bool c = (ycord = a.vertices[0].second + radius ); 				//bottom line 
	bool d = (ycord +radius = a.vertices[2].second);				//up lne
	if(a || b) xspeed -= 2*xspeed ;
	else if(c || d)  yspeed -= 2*yspeed ; 

}

void Circle::Reflection(Rectangle a)
{
	bool a = (xcord = a.vertices[0].first + radius); 				//left line of rectangle
	bool b = (xcord + radius = a.vertices[1].first );				//right line
	bool c = (ycord = a.vertices[0].second + radius ); 				//bottom line 
	bool d = (ycord +radius = a.vertices[2].second);				//up lne
	if(a || b) xspeed -= 2*xspeed ;
	else if(c || d)  yspeed -= 2*yspeed ; 
}


class Background
{
	public :

		vector<Circle> balls;
		Rectangle a;
		Background();
		void RunBackground();
};

Background::Background(vector<Circle> circs,Rectangle b)
{
	balls = circs;
	a = b;
}

void Background::RunBackground()
{
	for(int i=0;i<balls.size();i++)
	{
		for(int j= i+1;j<balls.size();j++)
		{
			balls[i].Collision(balls[j]);
		}
	}
	for(int i=0;i<balls.size();i++)
	{
		balls[i].Move();
	}
}
*/
int main()
{ 
	while(1)
	{
		usleep(10000);
		Back.RunBackground();
	}
}