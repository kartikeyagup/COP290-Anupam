//SSL-Server.c
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <resolv.h>
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>          
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#define LENGTH 512
#define FAIL    -1

#include <fstream>

int pos_typefilesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

string int2str(int n)
{   string l="";
    if(n==0)return"0";
    while(n!=0)
    {  l =  char(n%10+48) + l;
        n=n/10;
     }
     return l;
 }




int main()
{		    /* get any certificates */
printf("[Client] Receiveing file from Server and saving it as final.txt...");
vector<char*>  fil;
		fil.push_back("/home/btech/cs1130212/Desktop/13.mp3");
      
      const char* fr_name;
int fur=13;
char buf[1024];
             // change them //
         int i=0;
         int count=0;
		FILE *fr = fopen(fil[i],"r");
		FILE *fr1 = fopen("/home/btech/cs1130212/Desktop/uncoi2.mp3","a");
		while(i<21)
		{ cout<<"fdghb"<<endl;
		 if(i<20)
		{	cout<<i<<endl;
			while(count<=512000)
		{
			fread(buf, sizeof(char) , 	LENGTH , fr );
			fwrite(buf,sizeof(char),  LENGTH, fr1);
			count+=LENGTH;
			cout<<count<<endl;
			bzero(buf,LENGTH);
		}
	}
		else
		{	cout<<"gfg"<<endl;
	
				count=pos_typefilesize(fr_name);
				cout<<count<<endl;
				while(count!=0)
			{if(count<LENGTH)
			{	cout<<count<<endl;
			fread(buf, sizeof(char) , 	count , fr );
				fwrite(buf,sizeof(char),  count, fr1);
				count=0;
			}
			else
			{	fread(buf, sizeof(char) , 	LENGTH , fr );
			fwrite(buf,sizeof(char),  LENGTH, fr1);count-=LENGTH;
			cout<<count<<endl;
		}
			bzero(buf,LENGTH);
		}
	}
		
		
		
			
		cout<<fur<<endl;
		count=0;i++;
		fclose(fr);
                    string l  = ".mp3";
                        l = int2str(fur+1) + l ;
                        l = "/home/btech/cs1130212/Desktop/" +  l;
                        fur ++;    
                         fr_name  = l.c_str();
                         cout<<fr_name<<endl;   
                        fr = fopen(fr_name,"rb");
		}

   /*   //sleep(0.02);
      char msg =  char(EOF);
      char *m =  &msg;
	  cout<<msg<<endl;
*/
	}
     
