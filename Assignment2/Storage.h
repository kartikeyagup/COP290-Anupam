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
		unordered_map<string , vector<string> > locations;
		unordered_map<string , vector<string> > users;
	public:
		Storage();
		void setd(unordered_map<string , user> database);
		unordered_map<string , user> getd();
		void setl(unordered_map<string , vector<string> > location);
		unordered_map<string , vector<string> > getl();
		void setu(unordered_map<string , vector<string> > location);
		unordered_map<string , vector<string> > getu();
		void adduser(string us , user info);
		void addfile(string file , string us);
		void deletefile(string file);
		void deleteuser(string us);		
		//void openlocation(string us);											//returns location of directory of a user
};
#endif