#include <bits/stdc++.h>

#include "Board.h"
#include "Bullet.h"
#include "Tank.h"
#include "PowerUps.h"
#include "Walls.h"
#include "Host.h"


struct SendTank
{
	Vector CentrePosition;
	string UserID;
	string TankID;
	bool DeathStatus;
	PowerUp PowUp;
	string Direction;
};

struct SendWalls
{
	string Type;
	string ID;
	Vector Position;
	bool DeathStatus;
};

struct SendBullet
{
	Vector Position	;
	string Type;
	string BulletID;
	string UserID;
	string Direction;
	bool DeathStatus;
};

struct SendPowerUp
{
	string Type;
	string ID;
	Vector Position;
	bool DeathStatus;
};

struct SendHost
{
	string Mode;
	int Players;
	string IP;
	vector<string> ConnectedIPs;
	double FPS;
};



SendTank ConvertTank(Tank a)
{
	SendTank ans;
	ans.CentrePosition = a.getCentre();
	ans.UserID = a.getUserID();
	ans.TankID = a.getTankID();
	ans.DeathStatus = a.getDeathStatus();
	ans.PowUp = a.getPowerUp();
	return ans;
}

SendWalls ConvertWalls(Walls a)
{
	SendWalls ans;
	ans.Type = a.getType();
	ans.ID = a.getID();
	ans.Position = a.getPosition();
	ans.DeathStatus = a.getDeathStatus();
	return ans;
}

SendPowerUp ConvertPowUp(PowerUp a)
{
	SendPowerUp ans;
	ans.Type = a.getType();
	ans.ID = a.getID();
	ans.Position = a.getPosition();
	ans.DeathStatus = a.getDeathStatus();
	return ans;
}

SendBullet ConvertBullet(Bullet a)
{
	SendBullet ans;
	ans.Position = a.getPosition();
	ans.Type = a.getType();
	ans.BulletID = a.getBulletID();
	ans.UserID = a.getUserID();
	ans.Direction = a.getDirection();
	ans.DeathStatus = a.getDeathStatus();
	return ans;
}

SendHost ConvertHost(Host a)
{
	SendHost ans;
	ans.Mode = a.getMode();
	ans.Players = a.getPlayers();
	ans.IP = a.getIP();
	ans.ConnectedIPs = a.getConnectedIPs();
	ans.FPS = a.getFPS();
	return ans; 
}


