#include <bits/stdc++.h>
#include <boost/filesystem.hpp>
#include "Storage.h"
#include <fstream>
#define DIR "/home/btech/cs1130212/Desktop/Dir/"
using namespace std;

Storage::Storage()
{
	database = new unordered_map<string , user>;
	locations = new unordered_map<string , vector<string> >;
}

void Storage::setd(unordered_map<string , user> dat)
{
	database = dat;
}

unordered_map<string , user> Storage::getd()
{
	return database;
}

void Storage::setl(unordered_map<string , vector<string> > loc)
{
	locations = loc;
}

unordered_map<string , vector<string> > Storage::getl()
{
	return locations;
}

void Storage::setl(unordered_map<string , vector<string> > loc)
{
	users = loc;
}

unordered_map<string , vector<string> > Storage::getl()
{
	return users;
}

void Storage::adduser(string us , user info)
{
	database[us] = info;
	locations[us] = new vector<string> ;
}

void Storage::addfile(string file  , string us )
{
	//substr(file.find_last_of(".") + 1)
	ofstream fil(file);
	if(!file)
	{ 
		users[file] = new vector<string> ;
		users[file].push_back(us);
		locations[us].push_back(DIR + file);
	}
	fil.close();
	
}

void Storage::deletefile(string file, string us)
{
	for(int i=0;i<users[file].size();i++)
	{
		if(users[file].at(i)== us)
		{
			users[file].erase(i);
			break;
		}
	}

	for(int i=0;i<locations[us].size();i++)
	{
		if(locations[us].at(i)== file)
		{
			locations[us].erase(i);
		}
	}

	if(users[file].size() == 0)
	{
		users.erase(file);
	}
}

void Storage::deleteuser(string us)
{
	for(int i=0;i<locations[us].size();i++)
	{
		for(int j=0;j<users[locations[us].at(i)].size();j++)
		{
			if(users[locations[us].at(i)].at(j) == us)
			{
				users[locations[us].at(i)].erase(j);
				break;
			}
		}
	}
}