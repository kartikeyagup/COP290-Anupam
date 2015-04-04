#include <bits/stdc++.h>

using namespace std;




struct sharedfiles
{
	string filename;
	vector<string> commonusers;
	vector<string> serverparts;
};



vector<sharedfiles> getshared(string us , string Directory)
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
		vector<string> serverfiles;
		vector<string> comuser;
		while(i<temp.size())
		{
			while(temp[i]!='\t')
			{
				str+= temp[i];
				i++;
			}
			cout<<str<<" "<<endl;
			i++;
			serverfiles.push_back(str);
			str="";
		}
		newfile.serverparts = serverfiles;
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


void setshared(string us , vector<sharedfiles> sharefiles,string Directory1, string Directory2)
{
	string filestxt = Directory1 + us + "_shared.txt";
	string filestxt1 = Directory2 + us + "_shared.txt";
	remove(filestxt.c_str());

	ofstream ofile(filestxt1.c_str());
	for(int i=0;i<sharefiles.size();i++)
	{
		ofile<<sharefiles[i].filename<<'\t';
		cout<<sharefiles[i].filename<<'\t';
		for(int j=0;j<sharefiles[i].serverparts.size();j++)
		{
			cout<<sharefiles[i].serverparts[j]<<'\t';	
			ofile<<sharefiles[i].serverparts[j]<<'\t';
		}
		ofile<<'\n';
		for(int j=0;j<sharefiles[i].commonusers.size();j++)
		{
			cout<<sharefiles[i].commonusers[j]<<'\t';
			ofile<<sharefiles[i].commonusers[j]<<'\t';
		}
		ofile<<'\n';
	}
	ofile.close();
}




int main()
{
	vector<sharedfiles> share;
	//cout<<"dads"<<endl;
	share = getshared("anupam" , "/home/anupam/Desktop/");
	//cout<<share[0].filename <<endl;
	//cout<<share[0].commonusers.size()<<endl;
	setshared("anupam",share,"/home/anupam/Desktop","/home/anupam/Downloads/");

}