#include <bits/stdc++.h>


#include "Host.h"

using namespace std;

Host::Host()
{

}

void Host::setMode(string mode)
{
	Mode = mode;
}

void Host::setPlayers(int players)
{
	Players = players;
}

void Host::setIP(string ip)
{
	IP = ip;
}

void Host::setConnectedIPs(vector<string> connips)
{
	ConnectedIPs = connips;
}

void Host::setFPS(double fps)
{
	FPS = fps;
}

string Host::getMode()
{
	return Mode;
}

int Host::getPlayers()
{
	return Players;
}

string Host::getIP()
{
	return IP;
}

vector<string> Host::getConnectedIPs()
{
	return ConnectedIPs;
}

double Host::getFPS()
{
	return FPS;
}