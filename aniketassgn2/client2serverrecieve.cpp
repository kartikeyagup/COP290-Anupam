#ifndef SEED
#define SEED

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <ctype.h>          
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fstream>
#include <bits/stdc++.h>
#define BACKLOG 5
#define LENGTH 512 
using namespace std;


void file2read(char revbuf[])
{		printf("[Client] Receiveing file from Server and saving it as final.txt...");
		char* fr_name = "/home/btech/cs1130244/Desktop/server_re_file.txt.";
		FILE *fr = fopen(fr_name, "server_re_file");
		if(fr == NULL)
			printf("File %s Cannot be opened.\n", fr_name);
		else
		{
			bzero(revbuf, LENGTH); 
			int	 fr_block_sz = 0;
			fr_block_sz = recv(sockfd, revbuf, LENGTH , 0);
		
		}
						/* OPENING THE name of files */

		while(fr_block_sz > 0 )
			{  	
				{
					int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
		
					if(write_sz < fr_block_sz)
					{
						error("File write failed.\n");
					}
					bzero(revbuf, LENGTH);
					if (fr_block_sz == 0) 
					{ 
						break;
					}
				}
		
					fr_block_sz = recv(sockfd, revbuf, LENGTH , 0);
			}
			
			if(fr_block_sz < 0)
			{
				if (errno == EAGAIN)
				{
					printf("recv() timed out.\n");
				}
				else
				{
					fprintf(stderr, "recv() failed due to errno = %d\n", errno);
					cout<<strerror(errno)<<endl;	
				}
			}
			printf("Ok received from server!\n");
			fclose(fr);
}
