#ifndef STORAGE_H
#define STORAGE_H

#include <bits/stdc++.h>

using namespace std;


struct filewactions
{
	string filename ;
	int action;
	int filesize;
};

struct filewtime
{
	string filename;
	int filesize;
	int filetime;
};


//struct for keeping files on both sides (server and client)
struct filenames	
{
	string clientname;
	string servername;
};

struct sharedfiles
{
	string filename;
	vector<string> commonusers;
	string servername ;
};

class Storage
{
	private:
		//list of all files in server
		unordered_map<string , int> allfiles;
		//string Directory of all users
		string Directory;
	public:
		//constructor
		Storage();
		string filexists(string filename);
		void renamefile(string filename , string us);
		// us -> username , info -> data that user fills while signup
		//void updatefile(string filename , string us);
		//number of users for all files.
		void setaf(unordered_map<string,int> af);
		unordered_map<string,int> getaf();
		void downloadfiles(vector<string> todown, string user);
		void sharefile(string file , string us1 , string us2 , bool writeable);
		void renamefile(string prevfilename , string newfilename, string us);
		void adduser(string us);
		void addfile(string filename , string clientname  , string us );
		void deletefile(string file, string us);
		void delclientonly(string file, string us);
		void deleteuser(string us);			
		vector<filenames> getfiles(string us );
		vector<filenames> getononly(string us);
		vector<sharedfiles> getshared(string us );
		void setfiles(string us , vector<filenames> files);
		void setononly(string us , vector<filenames> files);
		void setshared(string us , vector<sharedfiles> sharefiles);
		int getnumfile(string us );
		void setnumfile(string us , int numf );
		void setservertime(string us , int numf );
		int getservertime(string us );
	

		//vector<filenames> getfiles(string us )
};
#endif
