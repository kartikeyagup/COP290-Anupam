#ifndef STORAGE_H
#define STORAGE_H

#include <bits/stdc++.h>

struct user
{
	string password;
	string Question;
	string answer;
};

using namespace std;

class Storage
{
	private:
		unordered_map<string , user> database;
		unordered_map<string , string> locations;
	public:
		Storage();
		void setd(unordered_map<string , user> database);
		unordered_map<string , user> getd();
		void setl(unordered_map<string , string> location);
		unordered_map<string , string> getl();
		void adduser(string us);
		void deleteuser(string us);		
		void openlocation(string us);											//returns location of directory of a user
};
#endif