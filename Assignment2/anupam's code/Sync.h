#include <bits/stdc++.h>

using namespace std;

class Sync
{
	private:
		string username;
		//list of files of user sent by client
		string* filelist;
		//list of old files of users
		string* oldfilelist;
		//equate bases of time of 2 machines (required for persistent storage)
		int timequate(string clientfile , string serverfile);
		void getuser(string user);
	public:
		void Diff
		//gets the action to be done as per modified time
		vector<int> getaction();
		//ouputs the blocks of difference ( for minimal data usage )
		vector<string> diffplaces(string filename1, string filename2);
		//syncs the file on both client and server side as per action
		void syncfile(string us , string file);
}