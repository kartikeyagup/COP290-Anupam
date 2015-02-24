#ifndef SYNC_H
#define SYNC_H
#include <bits/stdc++.h>




using namespace std;


struct filechars
{
	string filename ;
	int filemodtime;
};


//file with output actions
struct filewactions
{
	string filename ;
	int action;
};

class Sync
{
	private:
		string username;
		//list of files of user sent by client
		vector<filechars> filelist;
		//list of old files of users
		vector<filechars> oldfilelist;
		//gets the user to work upon

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
		void getaction();
		//ouputs the blocks of difference ( for minimal data usage )
		vector<string> diffplaces(string filename1, string filename2);
};


#endif