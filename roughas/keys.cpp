#ifndef keys.cpp
#include <bits/stdc++.h>
#include <GL/freeglut.h>
//#include "Circle1.h"
#include "keys.h"
using namespace std;

keys::keys(vector<Circle*> b){
	keystates=new bool[256];
	for(int i=0;i<256;i++){
		keystates[i]=0;
	}
	balls=b;
}

void keys::keyPressed(unsigned char a,int x,int y){
	keystates[a]=1;
	if(int(a) >=48 && int(a) <= 57){
		whatallkeys=10*whatallkeys+a-48;
	}
}

void keys::keyup(unsigned char a,int x,int y){
	keystates[a]=0;
}

void keys::keyOperations(void){
	int i;
	if(keystates[int('\n')]){
		i=whatallkeys;}
	if(keystates[int('x')]){
		balls[i]->xspeed=whatallkeys;
	}
	if(keystates[int('y')]){
		balls[i]->yspeed=whatallkeys;
	}
	whatallkeys=0;
	
}
#endif
