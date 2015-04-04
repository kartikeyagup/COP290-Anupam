//READ  THE COMMENTS WRITTEN IN CAPS CAREFYLLY . THEY ARE FOR LEFT OUT WORKS.


#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdio>
#include "ServerStorage.h"
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
	Directory = "/home/btech/cs1130212/serverCOP/allusers/";
}


vector<filenames> Storage::getfiles(string us )
{
	vector<filenames> v;
	string topen = Directory + us +"_files.txt";
	ifstream ifile(topen.c_str());
	filenames newfile;
	string temp ;
	while(getline(ifile,temp))
	{
		string str="";
		int i=0;
		//get username
		while(temp[i]!='\t')
		{
			str+=temp[i];
			i++;
		}
		i++;
	
		newfile.clientname = str;
			str="";
			while(temp[i]!='\t')
			{
				str+= temp[i];
				i++;
			}
			i++;
			newfile.servername  = str;
			str="";
		v.push_back(newfile);
	}
	return v;
}



vector<filenames> Storage::getononly(string us)
{
	vector<filenames> v;
	string topen = Directory + us +"_onlineonly.txt";
	ifstream ifile(topen.c_str());
	filenames newfile;
	string temp ;
	while(getline(ifile,temp))
	{
		string str="";
		int i=0;
		//get username
		while(temp[i]!='\t')
		{
			str+=temp[i];
			i++;
		}
		i++;
		str="";
		newfile.clientname = str;
			while(temp[i]!='\t')
			{
				str+= temp[i];
				i++;
			}
			i++;
			newfile.servername = str;
			str= "";
		v.push_back(newfile);
	}
	return v;
}


vector<sharedfiles> Storage::getshared(string us )
{

	vector<sharedfiles> v;
	string topen = Directory + us +"_shared.txt";
	ifstream ifile(topen.c_str());
	//cout<<(bool)ifile<<endl;
	sharedfiles newfile;
	string temp ;
	while(getline(ifile,temp))
	{
		//cout<<temp<<"\n"<<"\n"<<"\n";
		string str="";
		int i=0;
		//get username

		while(temp[i]!='\t')
		{
			str += temp[i];
			i++;
		}
		i++;
		newfile.filename = str;
		str="";
		vector<string> comuser;
		while(temp[i]!='\t')
		{
			str+= temp[i];
			i++;
		}
		i++;
		newfile.servername = str;
		str="";
		getline(ifile,temp);
		i=0;
		//cout<<temp<<"\n"<<"\n"<<"\n";
		while(i<temp.size())
		{
			while(temp[i]!='\t')
			{
				str+=temp[i];
				i++;
			}
			i++;
			comuser.push_back(str);
			str = "";
		}
		newfile.commonusers = comuser;
		v.push_back(newfile);

	}
	ifile.close();
	return v;
}



void Storage::setfiles(string us , vector<filenames> files)
{
	string filestxt = Directory + us + "_files.txt";
	remove(filestxt.c_str());
	ofstream ofile(filestxt.c_str());
	for(int i=0;i<files.size();i++)
	{
		ofile<<files[i].clientname<<"\t";
		ofile<<files[i].servername<<"\t";
		ofile<<"\n";
	}
	ofile.close();
}


void Storage::setononly(string us , vector<filenames> files)
{
	string filestxt = Directory + us + "_onlineonly.txt";
	remove(filestxt.c_str());
	ofstream ofile(filestxt.c_str());
	for(int i=0;i<files.size();i++)
	{
		ofile<<files[i].clientname<<"\t";
		ofile<<files[i].servername <<"\t";
		ofile<<"\n";
	}
	ofile.close();
}



void Storage::setshared(string us , vector<sharedfiles> sharefiles)
{
	string filestxt = Directory + us + "_shared.txt";
	remove(filestxt.c_str());

	ofstream ofile(filestxt.c_str());
	for(int i=0;i<sharefiles.size();i++)
	{
		ofile<<sharefiles[i].filename<<'\t';
		ofile<<sharefiles[i].servername<<'\t';
		ofile<<'\n';
		for(int j=0;j<sharefiles[i].commonusers.size();j++)
		{
			ofile<<sharefiles[i].commonusers[j]<<'\t';
		}
		ofile<<'\n';
	}
	ofile.close();
}



int Storage::getnumfile(string us )
{
	string numfilename = Directory + us + "_numfile.txt";
	ifstream ifile(numfilename.c_str());
	int num;
	ifile>>num;
	ifile.close();
	cout<<num<<endl;
	return num;
}

void Storage::setnumfile(string us , int numf )
{
	string numfilename = Directory + us + "_numfile.txt";
	ofstream ofile(numfilename.c_str());
	ofile<<numf;
	ofile.close();
	return ;
}
	
int Storage::getservertime(string us )
{
	string numfilename = Directory + us + "_servertime.txt";
	ifstream ifile(numfilename.c_str());
	int num;
	ifile>>num;
	ifile.close();
	//cout<<num<<endl;
	return num;
}

void Storage::setservertime(string us , int numf )
{
	string numfilename = Directory + us + "_servertime.txt";
	ofstream ofile(numfilename.c_str());
	ofile<<numf;
	ofile.close();
	return ;
}
	


void Storage::setaf(unordered_map<string,int> af)
{
	allfiles = af;
}



unordered_map<string,int> Storage::getaf()
{
	return allfiles;
}




void Storage::adduser(string us)
{

	string newuser1 = Directory + us +"_files.txt";
	string newuser2 = Directory + us +"_onlineonly.txt";
	string newuser3 = Directory + us +"_shared.txt";
	string newuser4 = Directory + us + "_numfile.txt";
	string newuser5 = Directory + us + "_servertime.txt";
	//creating txt to store files for the new user.
	ofstream ofile(newuser1.c_str());
	ofile.close();
	//creating txt to store files which are online only.
	ofstream ofile1(newuser2.c_str());
	ofile1.close();
	//creating txt for files which are shared either by him or the other users.
	ofstream ofile2(newuser3.c_str());
	ofile2.close();
	//creating file for storing numfile.
	ofstream ofile3(newuser4.c_str());
	ofile3<<0;
	ofile3.close();
	//creating file for time of last sync with server.
	ofstream ofile4(newuser5.c_str());
	ofile4<<0;
	ofile4.close();
	
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



void Storage::addfile(string servername , string clientname  , string us )
{
	cout<<"Adding file : "<<clientname <<" in user : "<<us <<endl;
	//substr(file.find_last_of(".") + 1)	
	filenames newfile;
	newfile.clientname = clientname;
	//when file does not exist
	newfile.servername = servername ;
	vector<filenames> addafile = getfiles(us);
	addafile.push_back(newfile);
	setfiles(us , addafile);
	setnumfile( us , getnumfile(us )+1 );
}

void Storage::deletefile(string file, string us)
{
	vector<filenames> delafile = getfiles(us );
	cout<<"Deleting file : "<<file <<" from user : "<<us <<endl;
	for(int j=0;j<delafile.size();j++)
	{
		if(delafile.at(j).clientname == file)
		{
			//decrease on number of users by 1
			allfiles[delafile.at(j).servername] -= 1;
			//if no user exists , then delete file
			if(allfiles[delafile.at(j).servername] == 0)
			{
				allfiles.erase(delafile.at(j).servername);
				remove(delafile.at(j).servername.c_str());
					// write code for erase from directory .REMEMBER !!!!!!!!!!!!
			}
		}
			//delete file from user to file list
			delafile.erase(delafile.begin() + j);
			setfiles(us , delafile );
			return;
	}

	//get all shared files of the user.
	vector<sharedfiles> usershare = getshared(us );
	for(int j=0;j<usershare.size();j++)
	{
		if(usershare.at(j).filename == file)
		{
			allfiles[usershare.at(j).servername] -=usershare[j].commonusers.size();
			if(allfiles[usershare.at(j).servername] == 0)
			{
				allfiles.erase(usershare.at(j).servername);              //  ***   change herte  ****** /////////
				remove(delafile.at(j).servername.c_str());

					// write code for erase from directory .REMEMBER !!!!!!!!!!!!
			}

			for(int i=0;i<usershare[j].commonusers.size();i++)                 //  ***   change herte  ****** /////////
			{
				//get the shared files for all the other users
				string user2 = usershare[j].commonusers[i];
				vector<sharedfiles> us2shared = getshared(user2 );
				for(int k=0;k<us2shared.size();k++)
				{
					//delete file from the users with which it is shared.
					us2shared.erase(us2shared.begin()+k);
					setshared(user2 , us2shared );
				}

			}
			//erase the file from the user side.
			usershare.erase(usershare.begin() + j);
		}

	}
	//put back the shared file directory of the user in his text file .
	setshared(us , usershare );
}



void Storage::delclientonly(string file, string us)
{
	cout<<"Deleting file : "<<file <<"from user : "<<us <<"'s client side only . Still saved on server"<<endl;
	vector<filenames> delci = getfiles(us );
	vector<filenames> onlineonly = getononly(us);
	for(int j=0;j<delci.size();j++)
	{
		if(delci.at(j).clientname == file)
		{
				//decrease in number of users by 1
				allfiles[delci.at(j).servername] -= 1;
				//if no user exists , then delete file
				if(allfiles[delci.at(j).servername] == 0)
				{
					allfiles.erase(delci.at(j).servername);
					// file does not need to be deleted from server in this case.
				}
			//delete file from user to file list
			onlineonly.push_back(*(delci.begin() + j));
			delci.erase(delci.begin() + j);
		}
	}
	setfiles(us , delci );
	setononly(us , onlineonly );
}





void Storage::deleteuser(string us)
{
	cout<< "Deleting User : "<<us<<endl;
	vector<filenames> delus = getfiles(us);
	for(int i=0;i<delus.size();i++)
	{
		deletefile(delus.at(i).clientname, us);
	}
	string str = Directory + us + "_shared.txt";
	string str1 = Directory + us + "_onlineonly.txt";
	string str2 = Directory + us + "_files.txt";
	string str3 = Directory + us + "_numfile.txt";
	string str4 = Directory + us + "_servertime.txt";
	remove(str.c_str());
	remove(str1.c_str());
	remove(str2.c_str());
	remove(str3.c_str());
	remove(str4.c_str());	
	
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



/*void Storage::syncfiles(string us , vector<filewactions> files)
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





/*void Storage::sharefile(string file , string us1 , string us2 , bool writeable)
{

	for(int i=0;i<usertofilelist[us1].size();i++)
	{

		//find the server parts of the file and add them to second user.
		//if permission is set as allowed towrite .
		if(usertofilelist[us1].at(i).clientname == file && writeable == 1)
		{
			//REMEMBER to change file(clientname) name as user has changed !!!!!!
			filenames temp = usertofilelist[us1].at(i);
			temp.clientname = resultfilename(temp.clientname, us1 , us2);

			sharedfiles[us2].filename== temp.clientname ;
			if(sharedfiles[us2].commonusers(
		}
		//if permission is user read only
		else if(usertofilelist[us1].at(i).clientname == file && writeable == 0)
		{
			// if only reading permisiion , treat it as addfile in us2.
			filenames temp = usertofilelist[us1].at(i);
			temp.clientname = resultfilename(temp.clientname, us1 , us2);
			usertofilelist[us2].push_back(temp) ;
		}
	}
	cout<<file<<" shared by : "<<us1<<" in folder of : "<<us2<<endl; 
}*/


void Storage::renamefile(string prevfilename , string newfilename, string us)
{
	vector<filenames> renam = getfiles(us );
	for(int i=0;i<renam.size();i++)
	{
		if(renam.at(i).clientname == prevfilename )
		{
			renam.at(i).clientname = newfilename;
		}
	}
	setfiles(us , renam);
	cout<<"file renamed from : "<<prevfilename<<" to "<<newfilename<<endl;
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
	//get all files list
	vector<filenames> down = getfiles(user);
	ofstream  ofile;
	//output the code and the files to be downloaded with the filenames.
	ofile.open("/home/anupam/Desktop/downfiles.txt");
	for(int i=0;i<todown.size();i++)
	{
		for(int j=0;j<down.size();j++)
		{
			if(down.at(j).clientname == todown[i])
			{
				ofile<<down.at(j).clientname<<"\t";
				ofile<<down[j].servername<<"\t";
				ofile<<"\n";
			}
		}
	}
	//set the files back again
	setfiles(user , down);
	ofile.close();
}



void Storage::sharefile(string file , string us1 , string us2 , bool permission)
{
	//get the shared files list of both users and other file list of user 1(who is sharing).
	vector<sharedfiles> us1shared = getshared(us1 );
	vector<sharedfiles> us2shared = getshared(us2 );
	vector<filenames> us1files =  getfiles(us1 );
	vector<filenames> us2files = getfiles(us2 );
	if(permission == 1)
	{
		for(int i=0;i<us1files.size();i++)
		{
			if(us1files[i].clientname == file)
			{
				string sfile = us1files[i].servername;
				for(int j=0;j<us2files.size();j++)
				{
					//case when file is present in both on the client and server as non-saved.
					if(us2files[j].servername == sfile)
					{
						sharedfiles us2enter ;
						sharedfiles us1enter ;
						us1enter.filename = us1files[i].clientname;
						us2enter.filename = us1files[i].clientname;
						us1enter.commonusers.push_back(us2); 
						us2enter.commonusers.push_back(us1);
						us1enter.servername = us1files[i].servername;
						us2enter.servername = us1files[i].servername;
						us1shared.push_back(us1enter);
						us2shared.push_back(us2enter);
						us1files.erase(us1files.begin() + i);
						us2files.erase(us2files.begin() + j);
						setfiles(us2 , us2files );
						setfiles(us1 , us1files );
						setshared(us1 ,us1shared );
						setshared(us2 , us2shared );
						return;
					}
				}
					
				for(int j=0;j<us2shared.size();j++)
				{
					//case when file is in non-shared part of server but already shared in client
					if(us2shared[j].servername == sfile )
					{
						sharedfiles us1enter ;
						us1enter.filename = us1files[i].clientname;
						us1enter.commonusers.push_back(us2); 
						us1enter.servername = us1files[i].servername;
						us1shared.push_back(us1enter);
						us2shared[j].commonusers.push_back(us1);
						us1files.erase(us1files.begin() + i);
						setfiles(us2 , us2files );
						setfiles(us1 , us1files );
						setshared(us1 ,us1shared );
						setshared(us2 , us2shared );
						return;
					}
				}
				//case when file is not there in server.
				sharedfiles us2enter ;
				sharedfiles us1enter ;
				us1enter.filename = us1files[i].clientname;
				us2enter.filename = us1files[i].clientname;
				us1enter.commonusers.push_back(us2); 
				us2enter.commonusers.push_back(us1);
				us1enter.servername = us1files[i].servername;
				us2enter.servername = us1files[i].servername;
				us1shared.push_back(us1enter);
				us2shared.push_back(us2enter);
				us1files.erase(us1files.begin() + i);
				setfiles(us2 , us2files );
				setfiles(us1 , us1files );
				setshared(us1 ,us1shared );
				setshared(us2 , us2shared );
				return;
			}
		}
		//file present in already shared files.
		for(int i=0;i<us1shared.size();i++)
		{
			if(us1shared[i].filename == file)
			{
				string sfile = us1files[i].servername;
				for(int j=0;j<us2files.size();j++)
				{
					//case when file is present in the client as saved  and server as non-saved.
					if(us2files[j].servername == sfile)
					{
						sharedfiles us2enter ;
						us2enter.filename = us2files[j].clientname; 
						us2enter.commonusers.push_back(us1);
						us2enter.servername = us1files[i].servername;
						us2shared.push_back(us2enter);
						us1shared[i].commonusers.push_back(us2);
						us2files.erase(us2files.begin() + j);
						setfiles(us2 , us2files );
						setfiles(us1 , us1files );
						setshared(us1 ,us1shared );
						setshared(us2 , us2shared );
						return;
					}
				}
					
				for(int j=0;j<us2shared.size();j++)
				{
					//case when file is in non-shared part of server but already shared in client
					if(us2shared[j].servername == sfile )
					{
						us2shared[j].commonusers.push_back(us1);
						us1shared[i].commonusers.push_back(us2);
						setfiles(us2 , us2files );
						setfiles(us1 , us1files );
						setshared(us1 ,us1shared );
						setshared(us2 , us2shared);
						return;
					}
				}
				//case when file is not there in server.
				//TODO: Editing required.
				sharedfiles us2enter ;
				us2enter.commonusers.push_back(us1);
				us2enter.servername = us1files[i].servername;
				us2shared.push_back(us2enter);
				setfiles(us2 , us2files );
				setfiles(us1 , us1files );
				setshared(us1 ,us1shared );
				setshared(us2 , us2shared );
				return;
			}

				/*sharedfiles us2enter ;
				sharedfiles us1enter ;
				us1enter.filename = us1files[i].clientname;
				us2enter.filename = us1files[i].clientname;
				us1enter.commonusers,push_back(us2); 
				us2enter.commonusers.push_back(us1);
				us1enter.servername = us1files[i].servername;
				us2enter.servername = us1files[i].servername;
				us1shared.push_back(us1enter);
				us2shared.push_back(us2enter);
				us1files.erase(us1files[i].begin() + i);
				setfiles(us1 , us1files , Directory);
				setshared(us1 ,us1shared , Directory);
				setshared(us2 , us2shared , Directory);ni
				goto g ;*/
		}
	}
	else
	{
		for(int i=0;i<us1files.size();i++)
		{
			if(us1files[i].clientname == file)
			{
				addfile(us1files[i].servername , file , us2);
			}
			return;
		}
		for(int i=0;i<us1shared.size();i++)
		{
			if(us1shared[i].filename == file)
			{
				addfile(us1shared[i].servername , file , us2);
			}
			return;
		}
				
	} 

} 

