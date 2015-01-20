#ifndef CIRCLE.CPP
#include <bits/stdc++.h>

using namespace std;
#include "Circle1.h"
#include <unistd.h>


Circle::Circle(double rad,Vect* pos, Vect* sp)
{
	radius = rad;
	speed = sp;
	position = pos;
}

void Circle::Move()
{	
	double time=0.001;
	sleep(time);
	Vect* b= new Vect(speed->x*time,speed->y*time,speed->z*time);
	position = position->addVect(b);
}
Vect* Circle::pointcollision(Message b)
{	
	
		Vect* rad =  (b.position->subVect(position));
		double d  = rad->magnitude();
		double forward =  radius / (double) d;
		Vect* forw = rad->multVect(forward);
		Vect* wait = position->addVect(forw);
	
	return wait;
}

int  Circle::Collision(Message b)
{
	cout<<"start in circle"<<endl;
	Vect* radialdr = (b.position->subVect(position));
	double d = radialdr->magnitude();
	if(d*1.001 <= radius + b.radius){
	double vrad1im = (speed->dot(radialdr))/(pow(d,2)); 
	double vrad2im = (b.speed->dot(radialdr))/(pow(d,2));  
	double k = pow(b.radius/radius,3);
	double vrad2fm = (2*vrad1im + (k-1)*vrad2im)/(k+1);  
	double vrad1fm = vrad2im + vrad2fm - vrad1im;
	//initial radial velocities
	Vect* vrad1i = radialdr->multVect(vrad1im);
	Vect* vrad2i = radialdr->multVect(vrad2im);
	//tangential velocities	
	Vect* vtang1 = speed->subVect(vrad1i);
	Vect* vtang2 = b.speed->subVect(vrad2i);
	//final radial velocities
	Vect* vrad1f = radialdr->multVect(vrad1fm);
	Vect* vrad2f = radialdr->multVect(vrad2fm);
	//final velocities
	Vect* v1f = vrad1f->addVect(vtang1);
	Vect* v2f = vrad2f->addVect(vtang2);
	speed = v1f;
	//b.speed = v2f; 
	cout<<"end1"<<endl;
	//avoid overlap of balls
	double overlap = (radius + b.radius - d)/(2*d);
	Vect* change = radialdr->multVect(overlap);
	position = position->subVect(change);
	cout<<"end in circle"<<endl;
	//b.position = (b.position->addVect(change));
	return 1;}
	return 0;	
		
}

void Circle::Reflection(Rectangle a)
{	
		bool t = (position->x <= (-a.dimension->x/2.0) + 1.01*radius);
		bool z = (position->x + 1.01*radius >= (a.dimension->x/2.0));				
		bool c = (position->y <= (-a.dimension->y/2.0) + 1.01*radius ); 				
		bool d = (position->y + 1.01*radius >= (a.dimension->y/2.0));
		bool e = (position->z <= (-a.dimension->z/2.0)  + 1.01*radius);
		bool f = (position->z + 1.01*radius >=(a.dimension->z/2.0));
		if(t )
		{
			 speed->x = abs(speed->x) ;
		}
		else if(z) speed->x = -abs(speed->x);
		else if(c )
		{
			speed->y = abs(speed->y) ;
		}
		else if(d) speed->y = -abs(speed->y);
		else if(e) 
		{	speed->z = abs(speed->z);
		}
		else if(f) speed->z = -abs(speed->z);
	
}
#endif