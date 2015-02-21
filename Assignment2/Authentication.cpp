#include <bits/stdc++.h>
#include <fstream>
#include "Authentication.h"
using namespace std;



Authentication::Authentication()
{

}

void Authentication::sett(unordered_map<string , user> tab)
{
	table = tab;
}
unordered_map<string , user> Authentication::gett()
{
	return table;
}


void Authentication::adduser()
{
	string username;
	user data;
	ifstream file;
	file.open("/home/btech/cs1130212/Desktop/a.txt");
	string s;
	char ch = '\n';
	getline(file,s,ch);
	username = s;
	int i=0;
	while(getline(file , s,ch))
	{
		switch(i)
		{
			case 0 :
				data.Name = s;
			case 1:
				data.password = s;
			case 2:
				data.Question = s;
			default:
				data.answer = s;
		}		
		i++;						 
	}
	file.close();
	table[username] = data;
	remove("/home/btech/cs1130212/Desktop/a.txt"); 
}

void Authentication::deluser()
{
	ifstream file;
	file.open("/home/btech/cs1130212/Desktop/b.txt");
	string s;
	char ch = '\n';
	getline(file, s, ch);
	file.close();
	table.erase(s);
	remove("/home/btech/cs1130212/Desktop/b.txt");
}

void Authentication::isAuthenticated(string us , string pass)
{
	ofstream ofile;
	ofile.open("/home/btech/cs1130212/Desktop/out.txt");
	if(table[us].password == pass)
	{
		ofile<<"1";	
	}
	else 
	{
		ofile<<"0";
	}
	ofile.close();
}



void Authentication::sec()
{
	ifstream file ;
	file.open("/home/btech/cs1130212/Desktop/username.txt");
	string a;
	char ch = '\n';
	getline(file,a,ch);
	file.close();

	
	string ques;	
	if(table.find(a) != table.end())
	{
		ques = table[a].Question;
		remove("/home/btech/cs1130212/Desktop/username.txt");
	}
	else
	{
		ques = "0";
	}
	ofstream ofile;
	ofile.open("/home/btech/cs1130212/Desktop/secure.txt");
	ofile<<ques;
	ofile.close();
}

void Authentication::verify()
{
	ifstream file;
	file.open("/home/btech/cs1130212/Desktop/verify.txt");
	string ans;
	char ch = '\n';
	getline(file, ans , ch);
	file.close();
	remove("/home/btech/cs1130212/Desktop/verify.txt");

	ifstream ifile ;
	ifile.open("/home/btech/cs1130212/Desktop/username.txt");
	string a;
	getline(file,a,ch);
	ifile.close();
	ofstream ofile;
	ofile.open("/home/btech/cs1130212/Desktop/verified.txt");
	ofile<<(table[a].answer==ans);
	ofile.close();
	remove("/home/btech/cs1130212/Desktop/username.txt");
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
