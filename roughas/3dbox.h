#include <bits/stdc++.h>

using namespace std;

struct colorbox
{
	public :
		double r;
		double g;
		double bl;
		double transp;
};

class Create3DBox
{
	public:
		Vect* dimension;
		colorbox color;
		Create3DBox();
		void makeQuads(float** cords,float** color);
		void makeCube();
};
