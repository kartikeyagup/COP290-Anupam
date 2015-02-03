#ifndef CIRCLE
#include <bits/stdc++.h>

using namespace std;
#include "Circle11.h"
#include <unistd.h>




Circle::Circle(double rad,double xs,double ys,double xc,double yc)
{
	//label=lab;
	radius = rad;
	//colour = color;
	xspeed = xs;
	yspeed = ys;
	xcord = xc;
	ycord = yc;
	pau=0;
}

void Circle::Move()
{	
	xcord += xspeed*0.0005;
	ycord += yspeed*0.0005;
if(pau==0)
{	if(ycord>radius)
	{acc_y=200;yspeed -= acc_y*0.001;	}
	else if(ycord + radius<=0)
	{	acc_y=200; yspeed += acc_y*0.001;	}
	else 
	{
		double totalvol = (4/3.0)*3.14*radius*radius*radius;
		double cost;
		double convol,volume;
		if(ycord > 0)
		{
			cost = (ycord - 0)/radius;
			volume = totalvol*(1-cost)/2.0;
			double height = ycord;
			convol = (1/3.0)*3.14*(height)*(radius*radius - height*height);
			volume = volume - convol;
		}
		else
		{
			cost = (0 - ycord)/radius;
			volume = totalvol*(1-cost)/2.0;
			double height = -ycord;
			convol = (1/3.0)*3.14*(height)*(radius*radius - height*height);
			volume = totalvol - volume  + convol;
		}
		cout<<(volume<totalvol)<<endl;
		acc_y=(2 - 4*(volume/totalvol))*100;
		yspeed -= (acc_y)*0.001;
			 
	}
}
}

pair<double,double> Circle::Collision(Message b/*,int& ch,bool& colli,bool& collj*/)
{
	
		double dist = sqrt((xcord- b.xcord)*(xcord - b.xcord) + (ycord - b.ycord)*(ycord-b.ycord));
		double v1x =  xspeed, v1y = yspeed , v2x = b.xspeed, v2y= b.yspeed;
		double sint; double cost;
		pair<double,double> store;
		store.first=0;store.second=0;
		if(dist*(1.001) < radius + b.radius  /*&& colli==0 && collj==0*/ )									//radial velocity inverts
		{
			sint = (ycord- b.ycord)/dist;
		 	cost = (b.xcord - xcord)/dist;
			double radial1i = v1x*cost - v1y*sint;
			double tang1 = v1y*cost + v1x*sint;
			double radial2i =  v2x*cost - v2y*sint;
			double tang2 = v2y*cost + v2x*sint;
			double k= pow(b.radius/radius ,3);
			double radial2f = (2*radial1i + (k-1)*radial2i)/(k+1);
			double radial1f = radial2f + radial2i - radial1i; 
			xspeed = radial1f*cost + tang1*sint;
			//b.xspeed = radial2f*cost + tang2*sint;
			yspeed = tang1*cost - radial1f*sint;
			//b.yspeed = tang2*cost - radial2f*sint;
			double overl =( radius +b.radius - dist);
			xcord -= overl*cost/2.0;
			ycord += overl*sint/2.0;
			//b.xcord += overl*cost/2.0;
			//b.ycord -= overl*sint/2.0;
			store.first = xcord  + radius*cost;
			store.second =  ycord -  radius*sint;	
			//double ch1 = b.xcord - b.radius*cost;
			//double ch2 = b.ycord - b.radius*sint;
			//if(int(ch1)==int(store.first)&&int(ch2)==int(store.second))
			//{	cout<<1<<endl; }
			//else
			//{	cout<<0<<endl;	}
		}
		return store;

}

void Circle::Reflection(Rectangle a,bool ref)
{
		bool t = (xcord <= a.vertices[0].first + radius);				//left line of rectangle
		bool z = (xcord + radius >= a.vertices[1].first );				//right line
		bool c = (ycord <= a.vertices[0].second + radius ); 			//bottom line 
		bool d = (ycord +radius >= a.vertices[2].second);				//up lne
		if(t)
		{
			 xspeed = abs(xspeed) ;
			ref=1;
		}
		else if(z) xspeed = -abs(xspeed);
		else if(c /*|| d && ref==0*/)
		{
			  yspeed = abs(yspeed) ;
			ref = 1;
		}
		else if(d) yspeed = -abs(yspeed);
	
}
#endif
