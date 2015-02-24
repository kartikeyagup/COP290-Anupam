#include <bits/stdc++.h>


#include "Sync.h"
using namespace std;

Sync::Sync()
{
	username = "";
}

void Sync::setuser(string user)
{
	username = user;
}

string Sync::getuser()
{
	return username;
}

void Sync::setf(vector<filechars> files)
{
	filelist = files;
}

vector<filechars> Sync::getf()
{
	return filelist;
}

void Sync::seto(vector<filechars> oldlist)
{
	oldfilelist = oldlist;
}

vector<filechars> Sync::geto()
{
	return oldfilelist;
}


/* Rules:

	0 	->	no change.
	1	->	server file to be deleted.
	2	->	client file to be added in server.
	3	->	client file to be updated.
	4	->	server file to be updated.
	5	->	share file of one user in another.
	6	->	sync files with server.
*/
void Sync::getaction(Storage* a)
{
	//for those who are in server but not in new list of files that the client wants to sync.
	bool updated[oldfilelist.size()];
	fill_n(updated, oldfilelist.size() , 0);
	filewactions newfile;
	vector<filewactions> actionlist;
	cout<<"loopstart"<<endl;
	//loop for checking that for all files in client list what files are to updated an how.
	for(int i=0;i<filelist.size();i++)
	{
		for(int j=0;j<oldfilelist.size();j++)
		{
			if(filelist[i].filename == oldfilelist[j].filename)
			{
				//filename of output file becomes file name of the file in the client side of list.
				newfile.filename = filelist[i].filename;
				//if client file is more latest.
				if(filelist[i].filemodtime > oldfilelist[j].filemodtime )
				{
					newfile.action = 4;
				}
				//if server file is latest.
				else
				{
					newfile.action = 3;
				}
				updated[j] = 1;
				actionlist.push_back(newfile);
				goto f;

			}
			// if a file needed to be added to the server side.
		}
		newfile.filename = filelist[i].filename;
		newfile.action = 2;
		actionlist.push_back(newfile);
 		f : ; //reaches here if newfile is already made
	}
	cout<<"loopend"<<endl;
	//loop for all files that are in server list and not in client list
	for(int i=0;i<oldfilelist.size();i++)
	{
		// for all files in server side that have to be deleted ( as they are not present in the client side)
		if(updated[i]==0)
		{
			a->deletefile(oldfilelist[i], username);
			// TODO : Delete file from server which are present on server 
			//THIS CAN BE DONE IF I KEEP A VARIABLE OF CLASS STORAGE IN PRIVATE OF THIS CLASS and call the deletefile function . 

		}
	}
	for(int i=0;i<actionlist.size();i++)
	{
		cout<<actionlist[i].action<<" ";
		cout<<actionlist[i].filename<<"\n";
	}
	ofstream actionslist;
	actionslist.open("/home/anupam/Desktop/actions.txt");
	for(int i=0;i<actionlist.size();i++)
	{
		actionslist<<actionlist[i].action<<" ";
		actionslist<<actionlist[i].filename<<"\n";
	}
	cout<<"loopend"<<endl;
	actionslist.close();

}



void deletefiles(vector<string> delfilelist ,  )
{

}





void downloadfiles(vector<string> todown)
{
	for(int i=0;i<)
} 


vector<string> diffplaces(string filename1, string filename2)
{

}


