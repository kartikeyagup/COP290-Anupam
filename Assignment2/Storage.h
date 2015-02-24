#ifndef STORAGE_H
#define STORAGE_H

#include <bits/stdc++.h>

using namespace std;


struct filewactions
{
	string filename ;
	int action;
};

struct user
{
	string password;
	string Question;
	string answer;
};


//struct for keeping files on both sides (server and client)
struct filenames	
{
	string clientname;
	vector<string> serverparts;
	int timeinserver;
};

class Storage
{
	private:
		//list of all files in server
		unordered_map<string , int> allfiles;
		//user to file list mapping
		unordered_map<string , vector<filenames> > usertofilelist;
		//list of files which are online only	
		unordered_map<string , vector<filenames> > useronlineonly;
		//for name of files in server
		int nextnum;		
		//list of files shared with a user

		//for checking if a file exists in the user's folder
		bool ifilexists(string fileinuser);
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
		//set the user to file list map 
		void setuof(unordered_map<string , vector<filenames> > useronlineonly);
		//get the user to file list map
		unordered_map<string , vector<filenames> > getuof();
		//whether a file with same content already exists
		string filexists(string filename);
		void renamefile(string filename , string us);
		// us -> username , info -> data that user fills while signup
		//void updatefile(string filename , string us);

		void downloadfiles(vector<string> todown, string user);
		void sharefile(string file , string us1 , string us2 , bool writeable);
		void renamefile(string prevfilename , string newfilename, string us);
		void adduser(string us);
		void addfile(string filename ,vector<string> fileparts ,  string us);
		void deletefile(string file, string us);
		void delclientonly(string file, string us);
		void deleteuser(string us);			
};
#endif