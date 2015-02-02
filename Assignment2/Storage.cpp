#include <bits/stdc++.h>
#include "Storage.h"
#define DIR ""
using namespace std;

Storage::Storage()
{
	database = new unordered_map<string , user>;
	locations = new unordered_map<string , string>;
}

void Storage::setd(unordered_map<string , user> dat)
{
	database = dat;
}

unordered_map<string , user> Storage::getd()
{
	return database;
}

void Storage::setl(unordered_map<string , string> loc)
{
	locations = loc;
}

unordered_map<string , string> getl()
{
	return locations;
}

void adduser(string us , user info)
{
	database[us] = info;
	int stat;
    stat = mkdir(DIR);
    if (!stat)
       printf("Directory created\n");
    else
    {
       printf("Unable to create directory\n");
       exit(1);
    }
}

void addfile(string file  , string us )
{
	
}