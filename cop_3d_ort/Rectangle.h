#include <bits/stdc++.h>

using namespace std;
#include "Vect.h"

class Rectangle
{
	public:

		Vect* position;
		Vect* dimension;
		Vect* colour;
		Rectangle();
		void Rectang(Vect* dim,Vect* col,Vect* pos);
};
