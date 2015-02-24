#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdio>
#include "Storage.h"
#include <fstream>

using namespace std;



int main()
{
	Storage* store =  new Storage();
	store->adduser("anupam");
	store->adduser("ronak");
	store->adduser("aniket");
	vector<string> fileps1;
	fileps1.push_back("1.cpp"); 
	fileps1.push_back("2.cpp");
	fileps1.push_back("3.cpp");
	vector<string> fileps2;
	fileps2.push_back("4.cpp"); 
	fileps2.push_back("5.cpp");
	fileps2.push_back("6.cpp");
	vector<string> fileps3;
	fileps3.push_back("7.cpp"); 
	fileps3.push_back("8.cpp");
	fileps3.push_back("9.cpp");
	store->addfile("/anupam/a.cpp",fileps1 , "anupam");
	store->addfile("/ronak/b.cpp",fileps2 , "ronak");
	store->addfile("/aniket/c.cpp",fileps3 , "aniket");
	cout<<(store->getu())["anupam"].at(0).clientname<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[0]<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[1]<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[2]<<endl;
	store->deletefile("/anupam/a.cpp","anupam");
	cout<<(store->getu())["anupam"].size()<<endl;
	store->sharefile("/ronak/b.cpp", "ronak", "anupam", 1);
	cout<<(store->getu())["anupam"].at(0).clientname<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[0]<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[1]<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[2]<<endl;
	store->renamefile("/anupam/Shared/b.cpp","/anupam/Shared/r.cpp","anupam");
	cout<<(store->getu())["anupam"].at(0).clientname<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[0]<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[1]<<endl;
	cout<<(store->getu())["anupam"].at(0).serverparts[2]<<endl;
	store->delclientonly("/anupam/Shared/r.cpp","anupam");
	cout<<(store->getuof())["anupam"].at(0).clientname<<endl;
	cout<<(store->getuof())["anupam"].at(0).serverparts[0]<<endl;
	cout<<(store->getuof())["anupam"].at(0).serverparts[1]<<endl;
	cout<<(store->getuof())["anupam"].at(0).serverparts[2]<<endl;


	vector<string> v;
	v.push_back("/ronak/b.cpp");
	store->downloadfiles(v, "ronak");
}