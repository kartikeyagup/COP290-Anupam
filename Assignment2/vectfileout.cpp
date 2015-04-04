#include <bits/stdc++.h>
#include <fstream>
#include "Make3file.h"

using namespace std;






void make3files(string prevfil , string currentsync)
{
	ifstream ifile;
	ifile.open(prevfil.c_str());
	vector<string> prevfiles;
	vector<string> prevtime;
	vector<string> currfiles;
	vector<string> currtime;	
	string s ;
	int i=0;
	while(getline(ifile , s))
	{
		i=0;
		string str = "";
		while(s[i] != '\t')
		{
			str += s[i];
			i++;
		}
		i++;
		prevfiles.push_back(str);
		str="";
		while(i<s.size())
		{
			str += s[i];
			i++;
		}
		prevtime.push_back(str);
	}
	ifile.close();
	ifstream ifile1(currentsync.c_str());
	while(getline(ifile1 , s))
	{
		i=0;
		string str = "";
		while(s[i] != '\t')
		{
			str += s[i];
			i++;
		}
		i++;
		currfiles.push_back(str);
		str="";
		while(i<s.size())
		{
			str += s[i];
			i++;
		}
		currtime.push_back(str);
	}
	ifile1.close();
	vector<string> addfiles;
	vector<string> addtime;
	vector<string> delfiles;
	vector<string> deltime;
	vector<string> restfiles;
	vector<string> resttime; 
	bool updatedcurr[currfiles.size()];
	fill_n(updatedcurr , 0 , currfiles.size());
	for(int i=0;i<prevfiles.size();i++)
	{
		for(int j=0;j<currfiles.size();j++)
		{
			if(prevfiles[i]==currfiles[j])
			{
				restfiles.push_back(prevfiles[i]);
				resttime.push_back(currtime[j]);
				updatedcurr[j] = 1;
				goto g ;
			}

		}
		delfiles.push_back(prevfiles[i]);
		deltime.push_back(prevtime[i]);
		g : ;

	}
	for(int i=0;i<currfiles.size();i++)
	{
		if(updatedcurr[i]==0)
		{
			addfiles.push_back(currfiles[i]);
			addtime.push_back(currtime[i]);
		}
	}
	ofstream ofile1("/home/anupam/Downloads/a.txt");
	for(int i=0;i<addfiles.size();i++)
	{
		ofile1<<addfiles[i]<<"\t"<<addtime[i]<<"\n";
	}
	ofile1.close();

	ofstream ofile2("/home/anupam/Downloads/b.txt");
	for(int i=0;i<delfiles.size();i++)
	{
		ofile2<<delfiles[i]<<"\t"<<deltime[i]<<"\n";
	}
	ofile2.close();
	
	ofstream ofile3("/home/anupam/Downloads/c.txt");
	for(int i=0;i<restfiles.size();i++)
	{
		ofile3<<restfiles[i]<<"\t"<<resttime[i]<<"\n";
	}
	ofile3.close();
}


int main()
{
	string file1 = "/home/anupam/Desktop/a.txt";
	string file2 = "/home/anupam/Desktop/b.txt";
	make3files(file1 , file2);
}