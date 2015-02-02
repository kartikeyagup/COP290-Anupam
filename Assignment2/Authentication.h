#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <bits/stdc++.h>
#include "Storage.h"



using namespace std;




class Authentication
{ 
	private:
		unordered_map<string , user> table;
	public:
		Authentication();
		void sett(unordered_map<string , user> tab);
		unordered_map<string , user> gett();
		bool isAuthenticated(string us , string pass);
		string fp(string a);
};
#endif