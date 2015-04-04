#ifndef SYNC_H
#define SYNC_H
#include <bits/stdc++.h>
#include "ServerStorage.h"




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
		string Directory;

	public:
		Sync();
		//get actions for all the files of the user.
		void getaction(Storage* a ,string us , const char* restfiles );
};


#endif