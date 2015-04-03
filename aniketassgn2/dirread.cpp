#include <fstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
	

vector<string> path;
int recurse(DIR* dir, string direct, string newlocate)
{	struct dirent* ent;
	if((dir = opendir(direct.c_str()))!= NULL)
	{	while((ent = readdir (dir ))!= NULL)
		{	if((ent->d_name[strlen(ent->d_name)-1]!='~')&&string(ent->d_name)!="."&&string(ent->d_name)!="..")
			{		string same_1 = direct;
					string same_2 = newlocate;
					direct+="/"+string(ent->d_name);
					newlocate+="/"+string(ent->d_name); 
					DIR* directory;
					recurse(directory,direct,newlocate);
					direct = same_1;
					newlocate =  same_2;
			}
		}

	}
	else
	{	path.push_back(newlocate);
	}
	return 0;
}
int main()
{	DIR* dir; string  direct = "/home/btech/cs1130212/aniket/aniket/arrange";
	recurse(dir,direct,"");
	cout<<path.size()<<endl;
	for(int i=0;i<path.size();i++)
	{	cout<<path[i]<<endl;}
}