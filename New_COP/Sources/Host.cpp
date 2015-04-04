#include <bits/stdc++.h>

#include "Vector.h"
#include "Walls.h"
#include "Board.h"
#include "Bullet.h"
#include "PowerUps.h"
#include "Tank.h"

using namespace std;

Host::Host()
{

}

void setMode(string mode)
{
	Mode = mode;
}

void setPlayers(int players)
{
	Players = players;
}

void setIP(string ip)
{
	IP = ip;
}

void setConnectedIPs(vector<string> connips)
{
	ConnectedIPs = connips;
}

void setFPS(double fps)
{
	FPS = fps;
}

string getMode()
{
	return Mode;
}

int getPlayers()
{
	return Players;
}

string getIP()
{
	return IP;
}

vector<string> getConnectedIPs()
{
	return ConnectedIPs;
}

double getFPS()
{
	return FPS;
}