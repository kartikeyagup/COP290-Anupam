//PLACES WHERE SEG FAULT IS POSSIBLE ARE IN CAPS

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


void Authentication::adduser(char* inf)
{
	user data;
	string us;
	string user = string(inf);
	int co=0;
	for(int i=0;i<user.size();i++)
	{
		string str;
		for(int j=i;(user[j]!='\t' | j<user.size());j++)
		{
			str += user[i];
		}
		co++;
		switch(co)
		{
			case 1 :
				us = str;
			case 3:
				data.password = str;
			case 4:
				data.Question = str;
			default:
				data.answer = str;
		}		
	}
	table[us] = data;
}

void Authentication::deluser(char* todel)
{
	string s = string(todel);	
	table.erase(s);
}

void Authentication::isAuthenticated(char* usandpass)
{
	string us = "", pass = "";
	bool tabdetect = 0;
	for(int i=0;i<sizeof(usandpass);i++)
	{
		if(tabdetect == 0)
		{
			us += usandpass[i];
		}
		else if(usandpass[i]=='\t')
		{
			tabdetect = 1;
		}
		else
		{
			pass += usandpass[i]; 
		}
	}

	ofstream ofile;
	ofile.open("/home/btech/cs1130212/Desktop/out.txt");
	//SEG FAULT : no such username detected and so unable to access table[us].
	if(table[us].password == pass)
	{
		ofile<<"1";	
		username = us;
	}
	else 
	{
		ofile<<"0";
	}
	ofile.close();
}



void Authentication::sec(char* usernam)
{
	string us = string(usernam);
	string ques;	
	if(table.find(us) != table.end())
	{
		ques = table[us].Question;
		username = us;
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

void Authentication::verify(char* an)
{
	string ans = string(an);
	ofstream ofile;
	ofile.open("/home/btech/cs1130212/Desktop/verified.txt");
	ofile<<(table[username].answer==ans);
	ofile.close();
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
