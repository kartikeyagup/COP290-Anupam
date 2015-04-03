#ifndef SYNC_H
#define SYNC_H
#include <bits/stdc++.h>
#include "Storage.h"




using namespace std;


struct filechars
{
	string filename ;
	int filemodtime;
};


//file with output actions
class Sync
{
	private:
		string username;
		//list of files of user sent by client
		vector<filechars> filelist;
		//list of old files of users
		vector<filechars> oldfilelist;
		//list of files to be deletedp

	public:
		Sync();
		//setting and getting functions
		void setuser(string username);
		string getuser();
		void setf(vector<filechars>);
		vector<filechars> getf();
		void seto(vector<filechars>);
		vector<filechars> geto();
		//get the action as per which the file has to act
		void getaction(Storage* a, string us , const char* restfiles, int synctime );

		//ouputs the blocks of difference ( for minimal data usage )
		vector<string> diffplaces(string filename1, string filename2);
};


#endif