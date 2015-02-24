//READ  THE COMMENTS WRITTEN IN CAPS CAREFYLLY . THEY ARE FOR LEFT OUT WORKS.


#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdio>
#include "Storage.h"
#include <fstream>
#define DIR "/home/btech/cs1130212/Desktop/Dir/"
using namespace std;



std::vector<std::string> readpath(std::string pathname)
{
	 std::string temppath="";
	 std::vector<std::string> a;
	 for(int i=1;i< pathname.size();i++)
	 {
	 	 if(pathname[i]=='/')
	 	 {
	 	 	 a.push_back(temppath);
	 	 	 temppath="";
	 	 } 
	 	 else
	 	 {
	 	 	 temppath = temppath + pathname[i];
	 	  } 
	 }
	 a.push_back(temppath);
	 return a; 
}

string resultfilename(string prevfilename , string us1 , string us2)
{
	vector<string> slashdiff = readpath(prevfilename);
	for(int i=0;i<slashdiff.size();i++)
	{
		if(slashdiff[i]==us1) slashdiff[i]= us2 + "/Shared";
	}
	string ans = "";
	for(int i=0;i<slashdiff.size();i++)
	{
		ans= ans + "/" + slashdiff[i];
	}
	return ans;

}





//getting file size of a file for later comparison
long GetFileSize(string file)
{
	ifstream in(file.c_str(), ifstream::ate | ifstream::binary );
	return in.tellg();
}

Storage::Storage()
{	
	nextnum =0;
}

void Storage::setaf(unordered_map<string,int> af)
{
	allfiles = af;
}

unordered_map<string,int> Storage::getaf()
{
	return allfiles;
}

void Storage::setu(unordered_map<string , vector<filenames> > utfl)
{
	usertofilelist = utfl;
}

unordered_map<string , vector<filenames> > Storage::getu()
{
	return usertofilelist;
}



void Storage::setuof(unordered_map<string , vector<filenames> > useronline)
{
	useronlineonly = useronline;
}

unordered_map<string , vector<filenames> > Storage::getuof()
{
	return useronlineonly;
}

void Storage::adduser(string us)
{

	vector<filenames> a;
	usertofilelist[us] = a ;
}
//check whether a file with exact same contents exist .
string Storage::filexists(string filename)
{
	/*for(auto it = allfiles.cbegin(); it!=allfiles.cend(); ++it)
	{
		if(it->first != "")
		{
			string serverfile = it->first;
			//case when file size is different
			if(GetFileSize(filename)!= GetFileSize(it->first))
			{
				continue;
			}
			//case when file extension is different
			else if(filename.substr(filename.find_last_of(".") + 1) != (*(it)).first.substr((*(it)).first.find_last_of(".") + 1))				
			{
				continue;
			}	
			else
			{
				//when whole file memory is same . NEED TO CORRECT IT!!!!
				//if(memcmp(filename.c_str(),((*(it)).first).c_str()) == 0) return (*(it)).first;
				//else return "";
				return "";
			}
		}
	}*/
		return "";
}



void Storage::addfile(string filename , vector<string> fileparts  , string us )
{
	cout<<"Adding file : "<<filename <<" in user : "<<us <<endl;
	//substr(file.find_last_of(".") + 1)	
	filenames newfile;
	newfile.clientname = filename;
	//when file does not exist
	for(int i=0;i<fileparts.size();i++)
	{
		/*if(filexists(fileparts[i]) == "" )
		{
			//add a part of the file or whole file(if file is small)
			newfile.serverparts.push_back(string(to_string(nextnum)));
			nextnum++;
			allfiles[newfile.serverparts[i]] = 1 ;
		}
		//if file exists
		else
		{
			//
			newfile.serverparts.push_back(filexists(fileparts[i]));
			allfiles[newfile.serverparts[i]] += 1;
		}*/
		newfile.serverparts.push_back(fileparts[i]);
	}
	usertofilelist[us].push_back(newfile);
}

void Storage::deletefile(string file, string us)
{
	cout<<"Deleting file : "<<file <<" from user : "<<us <<endl;
	for(int j=0;j<usertofilelist[us].size();j++)
	{
		if(usertofilelist[us].at(j).clientname == file)
		{
			for(int i=0;i<usertofilelist[us].at(j).serverparts.size();i++)
			{
				//decrease in number of users by 1
				allfiles[usertofilelist[us].at(j).serverparts[i]] -= 1;
				//if no user exists , then delete file
				if(allfiles[usertofilelist[us].at(j).serverparts[i]] == 0)
				{
					allfiles.erase(usertofilelist[us].at(j).serverparts[i]);
					// write code for erase from directory .REMEMBER !!!!!!!!!!!!
				}
			}
			//delete file from user to file list
			usertofilelist[us].erase(usertofilelist[us].begin() + j);
		}
	}
}



void Storage::delclientonly(string file, string us)
{
	cout<<"Deleting file : "<<file <<"from user : "<<us <<"'s client side only . Still saved on server"<<endl;
	for(int j=0;j<usertofilelist[us].size();j++)
	{
		if(usertofilelist[us].at(j).clientname == file)
		{
			for(int i=0;i<usertofilelist[us].at(j).serverparts.size();i++)
			{
				//decrease in number of users by 1
				allfiles[usertofilelist[us].at(j).serverparts[i]] -= 1;
				//if no user exists , then delete file
				if(allfiles[usertofilelist[us].at(j).serverparts[i]] == 0)
				{
					allfiles.erase(usertofilelist[us].at(j).serverparts[i]);
					// file does not need to be deleted from server in this case.
				}
			}
			//delete file from user to file list
			useronlineonly[us].push_back(*(usertofilelist[us].begin() + j));
			usertofilelist[us].erase(usertofilelist[us].begin() + j);
		}
	}
}





void Storage::deleteuser(string us)
{
	cout<< "Deleting User : "<<us<<endl;
	for(int i=0;i<usertofilelist[us].size();i++)
	{
		deletefile(usertofilelist[us].at(i).clientname, us);
	}
	usertofilelist.erase(us);
}

/*void Storage::updatefile(string filename , string us)
{
	cout<<"Updating file  : "<<filename<<endl;
	for(int i=0;i<usertofilelist[us].size();i++)
	{
		if(usertofilelist[us].at(i).clientname == filename )
		{
			//TODO : REMEMBER to write the code for updating file , i.e. replaacing file with new file
		}
	}
}*/



/*oid Storage::syncfiles(string us , vector<filewactions> files)
{
	//to send the list of actions to aniket to be forwarded to Ronak.
	
	for(int i=0;i<files.size();i++)
	{
		switch(files[i].action)
		{
			case 1:
			{
				actionslist<<1<<" "<<files[i]
			}
			case 2:
			{
				vector<string> fileparts;
				addfile(files[i].filename , fileparts ,  us);
			} 
			case 3:
			{
				//WRITE CODE TO UPDATE THE CLIENT SIDE FILE BY SENDING
			}
			default:
			{
				deletefile(files[i].filename , us);
				addfile(files[i].filename, us);
			}
		}
	}		
}*/





void Storage::sharefile(string file , string us1 , string us2 , bool writeable)
{
	for(int i=0;i<usertofilelist[us1].size();i++)
	{

		//find the server parts of the file and add them to second user.
		if(usertofilelist[us1].at(i).clientname == file && writeable == 1)
		{
			//REMEMBER to change file(clientname) name as user has changed !!!!!!
			filenames temp = usertofilelist[us1].at(i);
			temp.clientname = resultfilename(temp.clientname, us1 , us2);

			usertofilelist[us2].push_back(temp) ;
			//add readable property here
		}
	}
	cout<<file<<" shared by : "<<us1<<" in folder of : "<<us2<<endl; 
}


void Storage::renamefile(string prevfilename , string newfilename, string us)
{
	cout<<"file renamed from : "<<prevfilename<<" to "<<newfilename<<endl;
	for(int i=0;i<usertofilelist[us].size();i++)
	{
		if(usertofilelist[us].at(i).clientname == prevfilename )
		{
			usertofilelist[us].at(i).clientname = newfilename;
		}
	}
}





/*void Storage::syncsel(filewactions file , string us)
{
	switch(file.action)
	{


			case 1:
			{
				deletefile(file.filename , us);
			}
			case 2:
			{
				vector<string> fileparts;
				addfile(file.filename , fileparts , us);
			} 
			case 3:
			{
				//WRITE CODE TO UPDATE THE CLIENT SIDE FILE BY SENDING
			}
			default:
			{
				deletefile(file.filename , us);
				addfile(file.filename, us);
			}
	}	
}*/



void Storage::downloadfiles(vector<string> todown, string user)
{
	ofstream  ofile;
	ofile.open("/home/anupam/Desktop/downfiles.txt");
	for(int i=0;i<todown.size();i++)
	{
		for(int j=0;j<usertofilelist[user].size();j++)
		{
			if(usertofilelist[user].at(j).clientname == todown[i])
			{
				ofile<<usertofilelist[user].at(j).clientname<<" ";
				for(int k=0;k<usertofilelist[user].at(j).serverparts.size();k++)
				{
					ofile<<usertofilelist[user].at(j).serverparts[k]<<" ";
				}
				ofile<<"\n";
			}
		}
	}
	ofile.close();
}
