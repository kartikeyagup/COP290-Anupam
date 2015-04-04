#include <bits/stdc++.h>

using namespace std;

bool TestBoard::TestGiveChanges(Board a)
{
	vector<Bullets> b = a.getBullets();
	vector<Tanks> t = a.getTanks();
	vector<PowerUp> p = a.getPowerUps();
	vector<Walls> w = a.getBricks();

	Board ans = Board.GiveChanges(vector< pair<string,string> >)
}