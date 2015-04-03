#include <bits/stdc++.h>


#include "Sync.h"
#include "Storage.h"
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
	1	->	server file to be added in client.
	2	->	client file to be deleted.
	3	->	client file to be updated.
	4	->	server file to be updated.
	5	->	share file of one user in another.
	6	->	sync files with server.
*/
void Sync::getaction(Storage* a, string us , const char* restfiles, int synctime )
{
	//
	//actions need to be defined for all the files that are not in addfile.txt or deletefiles.txt.
	//str1 for filename and str2  for modified time.
	string str1,str2,str3 = "";
	vector<filewtime> filelist;
	for(int i=0;i<sizeof(restfiles);i++)
	{
		while(restfiles[i]!='\n')
		{
			while(restfiles[i]!=' ')
			{
				str1+=restfiles[i];
				i++;
			}
			while(restfiles[i]!=' ')
			{
				str3+=restfiles[i];
				i++;
			}
			str2+=restfiles[i];
		}
		//
		filewtime newfile;
		newfile.filename = str1;
		newfile.filesize = stoi(str2);
		newfile.filesize = stoi(str3);
		filelist.push_back(newfile);
	}
	//for those who are in server but not in new list of files that the client wants to sync.
	bool servupdated[oldfilelist.size()];

	fill_n(servupdated, oldfilelist.size() , 0);
	filewactions newfile;
	vector<filewactions> actionslist;
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
				if(filelist[i].filetime > a->getst()[us] )
				{
					newfile.action = 4;
				}
				//if server file is latest.
				else
				{
					newfile.action = 3;
				}
				servupdated[j] = 1;
				actionslist.push_back(newfile);
				goto f;
			}
			// if a file needed to be added to the server side.
		}
		newfile.filename = filelist[i].filename;
		newfile.filesize= filelist[i].filesize;
		newfile.action = 2;
		actionslist.push_back(newfile);
 		f : ; //reaches here if newfile is already made
	}
	cout<<"loopend"<<endl;
	//loop for all files that are in server list and not in client list
	for(int i=0;i<oldfilelist.size();i++)
	{
		// for all files in server side that have to be deleted ( as they are not present in the client side)
		if(servupdated[i]==0)
		{
			filewactions newf;
			newf.filename = oldfilelist[i].filename;
			//newf.filesize = oldfilelist[i].filesize;
			newf.action = 1;
			actionslist.push_back(newf);
			// TODO : Delete file from server which are present on server 
			//THIS CAN BE DONE IF I KEEP A VARIABLE OF CLASS STORAGE IN PRIVATE OF THIS CLASS and call the deletefile function . 

		}
	}
	for(int i=0;i<actionslist.size();i++)
	{
		cout<<actionslist[i].action<<" ";
		cout<<actionslist[i].filename<<"\n";
	}
	ofstream actionlist;
	actionlist.open("/home/anupam/Desktop/actions.txt");
	for(int i=0;i<actionslist.size();i++)
	{
		actionlist<<actionslist[i].action<<" ";
		actionlist<<actionslist[i].filename<<"\n";
	}
	cout<<"loopend"<<endl;
	actionlist.close();
	a->getst()[us] = synctime;

}





 


vector<string> diffplaces(string filename1, string filename2)
{

}


