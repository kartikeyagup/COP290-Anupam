#include <bits/stdc++.h>


#include "ServerSync.h"
#include "ServerStorage.h"
using namespace std;

Sync::Sync()
{

}

/* Rules:
	1	->	server file to be added in client.
	2	->	client file to be deleted.
	3	->	client file to be updated.
	4	->	server file to be updated.
	5	->	share file of one user in another.
	6	->	sync files with server.
*/
void Sync::getaction(Storage* a, string us , const char* restfiles )
{
	int synctime = a->getservertime(us);
	//actions need to be defined for all the files that are not in addfile.txt or deletefiles.txt.
	//str1 for filename and str2  for modified time.
	string str1,str2,str3 = "";
	vector<filewtime> filelist;
	for(int i=0;i<sizeof(restfiles);i++)
	{
		while(restfiles[i]!='\n')
		{
			while(restfiles[i]!='\t')
			{
				str1+=restfiles[i];
				i++;
			}
			while(restfiles[i]!='\t')
			{
				str3+=restfiles[i];
				i++;
			}
			str2+=restfiles[i];
		}
		//
		filewtime newfile;
		newfile.filename = str1;
		newfile.filetime = stoi(str3);
		filelist.push_back(newfile);
	}
	vector<filenames> oldlist;
	oldlist = a->getfiles(us);
	//for those who are in server but not in new list of files that the client wants to sync.
	bool servupdated[oldlist.size()];
	fill_n(servupdated, oldlist.size() , 0);
	filewactions newfile;
	vector<filewactions> actionslist;
	cout<<"loopstart"<<endl;
	//loop for checking that for all files in client list what files are to updated an how.
	for(int i=0;i<filelist.size();i++)
	{
		for(int j=0;j<oldlist.size();j++)
		{
			if(filelist[i].filename == oldlist[j].clientname)
			{
				//filename of output file becomes file name of the file in the client side of list.
				newfile.filename = filelist[i].filename;
				//if client file is more latest.
				if(filelist[i].filetime > synctime )
				{
					newfile.action = 'b';
				}
				//if server file is latest.
				else
				{
					newfile.action = 'a';
				}
				servupdated[j] = 1;
				actionslist.push_back(newfile);
				goto f;
			}
			// if a file needed to be added to the server side.
		}
		newfile.filename = filelist[i].filename;
		newfile.action = 'c';
		actionslist.push_back(newfile);
 		f : ; //reaches here if newfile is already made
	}
	//end of files to be added to client which are not shared.
	cout<<"loopend"<<endl;
	//loop for all files that are in server list and not in client list
	for(int i=0;i<oldlist.size();i++)
	{
		// for all files in server side that have to be deleted ( as they are not present in the client side)
		if(servupdated[i]==0)
		{
			filewactions newf;
			newf.filename = oldlist[i].clientname;
			//newf.filesize = oldfilelist[i].filesize;
			actionslist.push_back(newf);
			a->deletefile(newf.filename , us);
			// TODO : Delete file from server which are present on server 
			//THIS CAN BE DONE IF I KEEP A VARIABLE OF CLASS STORAGE IN PRIVATE OF THIS CLASS and call the deletefile function . 

		}
	}
	//***************************************SHARE FILE SYNC START*****************************//
	
	vector<sharedfiles> share = a->getshared(us);
	bool servshareupdated[share.size()];
	fill_n(servshareupdated, share.size() , 0);
	cout<<"loopstart"<<endl;
	//loop for checking that for all files in client list what files are to updated an how.
	for(int i=0;i<filelist.size();i++)
	{
		for(int j=0;j<share.size();j++)
		{
			if(filelist[i].filename == share[j].filename)
			{
				//filename of output file becomes file name of the file in the client side of list.
				newfile.filename = filelist[i].filename;
				//if client file is more latest.
				if(filelist[i].filetime > synctime )
				{
					newfile.action = 'b';
				}
				//if server file is latest.
				else
				{
					newfile.action = 'a';
				}
				servshareupdated[j] = 1;
				actionslist.push_back(newfile);
				goto g;
			}
			// if a file needed to be added to the server side.
		}
		newfile.filename = filelist[i].filename;
		newfile.action = 'c';
		actionslist.push_back(newfile);
 		g : ; //reaches here if newfile is already made
	}
	//end of files to be added to client which are not shared.
	cout<<"loopend"<<endl;
	//loop for all files that are in server list and not in client list
	for(int i=0;i<oldlist.size();i++)
	{
		// for all files in server side that have to be deleted ( as they are not present in the client side)
		if(servshareupdated[i]==0)
		{
			filewactions newf;
			newf.filename = share[i].filename;
			//newf.filesize = oldfilelist[i].filesize;
			actionslist.push_back(newf);
			a->deletefile(newf.filename , us);
			// TODO : Delete file from server which are present on server 
			//THIS CAN BE DONE IF I KEEP A VARIABLE OF CLASS STORAGE IN PRIVATE OF THIS CLASS and call the deletefile function . 

		}

	}



	ofstream actionlist;
	actionlist.open("/home/anupam/Desktop/actions.txt");
	for(int i=0;i<actionslist.size();i++)
	{
		actionlist<<actionslist[i].action<<"\t";
		actionlist<<actionslist[i].filename<<"\n";
	}
	cout<<"loopend"<<endl;
	actionlist.close();

}

int main()
{}