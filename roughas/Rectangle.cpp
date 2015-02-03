#ifndef RECTANGLE
#define RECTANGLE
#include <bits/stdc++.h>
#include "Rectangle.h"
using namespace std;


Rectangle::Rectangle()
{
	dimension = new Vect(10,10,10);
	colour = new Vect(1,1,1);
	position= new Vect(0,0,0);
}

void Rectangle::Rectang(Vect* dim,Vect* col,Vect* pos_r)
{ 
	position= pos_r;	
	dimension = dim;
	colour =col;
}

#endif
