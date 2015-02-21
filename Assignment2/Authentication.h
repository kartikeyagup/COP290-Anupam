#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <bits/stdc++.h>


using namespace std;

struct user
{
	string Name;
	string username;
	string password;
	string Question;
	string answer;
};




class Authentication
{ 
	private:
		unordered_map<string , user> table;
	public:
		Authentication();
		void sett(unordered_map<string , user> tab);
		unordered_map<string , user> gett();
		void adduser();
		void deluser();
		void isAuthenticated(string us , string pass);
		void sec();
		void verify();
};
#endif