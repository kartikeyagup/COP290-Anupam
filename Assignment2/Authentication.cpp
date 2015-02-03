#include <bits/stdc++.h>
#include "Authentication.h"
using namespace std;

struct user
{
	string password;
	string Question;
	string answer;
};


Authentication::Authentication()
{
	table = new unordered_map<string , user>();
}

void Authentication::sett(unordered_map<string , user> tab)
{
	table = tab;
}
unordered_map<string , user> Authentication::gett()
{
	return table;
}

bool Authentication::isAuthenticated(string us , string pass)
{
	if(table[us].password == pass) return true;
	else return false;
}

string Authentication::fp(string s , string a)
{
	if(a == table[s].answer) return table[s].password ;
	else return "Wrong answer. Please try again."; 
}