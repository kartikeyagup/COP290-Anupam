#include <bits/stdc++.h>

using namespace std;

#include "Background.h"
#include "Circle.h"
#include "Rectangle.h"

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