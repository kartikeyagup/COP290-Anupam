#ifndef keys.h
#include <bits/stdc++.h>
#include <GL/freeglut.h>
#include "Circle1.h"

using namespace std;


class keys{
	void keyPressed(unsigned char key,int x,int y);
	void keyup (unsigned char key, int x,int y);
	void keyOperations(void);
	keys(vector<Circle*> a);
	bool* keystates;
	int whatallkeys;
	vector<Circle*> balls;
	
};
#endif
