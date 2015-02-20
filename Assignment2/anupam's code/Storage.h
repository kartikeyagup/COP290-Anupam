#ifndef STORAGE_H
#define STORAGE_H

#include <bits/stdc++.h>

using namespace std;

struct user
{
	string password;
	string Question;
	string answer;
};

using namespace std;


//struct for keeping files on both sides (server and client)
struct filenames	
{
	string clientname;
	vector<string> serverparts;
};


class Storage
{
	private:
		//list of all files in server
		unordered_map<string , int> allfiles;
		//user to file list mapping
		unordered_map<string , vector<filenames> > usertofilelist;	
		//for name of files in server
		int nextnum;		
	public:
		//constructor
		Storage();
		//set the list of all files
		void setaf(unordered_map<string,int>);
		//get all files list
		unordered_map<string,int> getaf();
		//set the user to file list map 
		void setu(unordered_map<string , vector<filenames> > usertofilelist);
		//get the user to file list map
		unordered_map<string , vector<filenames> > getu();
		//whether a file with same content already exists
		string filexists(string filename);
		// us -> username , info -> data that user fills while signup
		void sharefile(string filename , string user1 , string user2, bool permission);
		void adduser(string us);
		void addfile(string filename , string us);
		void deletefile(string file, string us);
		void deleteuser(string us);			
};
#endif