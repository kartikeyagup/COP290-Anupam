#ifndef SENDING
#define SENDING

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



void file2send()
{	char* fs_name = "/home/btech/cs1130244/Desktop/file_name.txt";
	char sdbuf[LENGTH]; 
	printf("[Client] Sending %s to the Server...", fs_name);
	FILE *fs = fopen(fs_name, "r");
	
		if(fs == NULL)
		{
		    printf("ERROR: File %s not found.\n", fs_name);
			exit(1);
		}

		bzero(sdbuf, LENGTH); 
		int fs_block_sz = 0 ; 
		//int success = 0;
		fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs);
		while(fs_block_sz >0)
	    {
	        if(send(sockfd, sdbuf, fs_block_sz, 0) < 0)
	        {
	            printf("ERROR: Failed to send file %s.\n", fs_name);
	            break;
	        }
	        bzero(sdbuf, LENGTH);
	        fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs);
	    }
	    printf("Ok File %s from Client was Sent!\n", fs_name);
}