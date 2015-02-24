#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <bits/stdc++.h>


using namespace std;

struct user
{
	string password;
	string Question;
	string answer;
};




class Authentication
{ 
	private:
		string username;
		unordered_map<string , user> table;
	public:
		Authentication();
		void sett(unordered_map<string , user> tab);
		unordered_map<string , user> gett();
		void adduser(char* inf);
		void deluser(char* b);
		void isAuthenticated(char* usandpass);
		void sec(char* a);
		void verify(char* a);
};
#endif