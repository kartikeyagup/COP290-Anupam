#ifndef colors
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h> 
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <vector>
#include <GL/glu.h>
#include "Vect.h"
using namespace std;


void addcolors(){
	Vect* color;
	vector<Vect*> colvector;
	color=new Vect(26, 188, 156);
	colvector.push_back(color);
	color=new Vect(46, 204, 113);
	colvector.push_back(color);
	color=new Vect(52, 152, 219);
	colvector.push_back(color);
	color=new Vect(155, 89, 182);
	colvector.push_back(color);
	color=new Vect(52, 73, 94);
	colvector.push_back(color);
	color=new Vect(192, 57, 43);
	colvector.push_back(color);
	color=new Vect(22, 160, 133);
	colvector.push_back(color);
	color=new Vect(39, 174, 96);
	colvector.push_back(color);
	color=new Vect(142, 68, 173);
	colvector.push_back(color);
	color=new Vect(44, 62, 80);
	colvector.push_back(color);
	color=new Vect(230, 126, 34);
	colvector.push_back(color);
	color=new Vect(231, 76, 60);
	colvector.push_back(color);
	color=new Vect(236, 240, 241);
	colvector.push_back(color);
	color=new Vect(149, 165, 166);
	colvector.push_back(color);
	color=new Vect(243, 156, 18);
	colvector.push_back(color);
	color=new Vect(211, 84, 0);
	colvector.push_back(color);
	color=new Vect(189, 195, 199);
	colvector.push_back(color);
	color=new Vect(127, 140, 141);
}
int main(){
	addcolor();
	return(0);
}
#endif