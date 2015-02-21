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
void error(const char *msg)
{
	perror(msg);
	exit(1);
}
char revbuf[LENGTH]; // Receiver buffer
char* func (int nsockfd)
{    bzero(revbuf,512);

     int n = read(nsockfd,revbuf,511);
     if (n < 0) error("ERROR reading from socket");
     char* identity =  new  char[strlen(revbuf)];
     identity =  revbuf;
     return identity;
}
int main(int argc, char** argv)
{	
	/* Defining Variables */
	int sockfd; 
	int nsockfd; 
	int num;
	int PORT = atoi(argv[1]);
	int sin_size; 
	struct sockaddr_in addr_local; /* client addr */
	struct sockaddr_in addr_remote; /* server addr */


	/* Get the Socket file descriptor */
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
	{
		fprintf(stderr, "ERROR: Failed to obtain Socket Descriptor. (errno = %d)\n", errno);
		exit(1);
	}
	else 
		printf("[Server] Obtaining socket descriptor successfully.\n");

	/* Fill the client socket address struct */
	addr_local.sin_family = AF_INET; // Protocol Family
	addr_local.sin_port = htons(PORT); // Port number
	addr_local.sin_addr.s_addr = INADDR_ANY; // AutoFill local address
	bzero(&(addr_local.sin_zero), 8); // Flush the rest of struct

	/* Bind a special Port */
	if( bind(sockfd, (struct sockaddr*)&addr_local, sizeof(struct sockaddr)) == -1 )
	{
		fprintf(stderr, "ERROR: Failed to bind Port. (errno = %d)\n", errno);
		exit(1);
	}
	else 
		printf("[Server] Binded tcp port %d in addr 127.0.0.1 sucessfully.\n",PORT);
while(1)
{
	/* Listen remote connect/calling */
	
	if(listen(sockfd,BACKLOG) == -1)
	{
		fprintf(stderr, "ERROR: Failed to listen Port. (errno = %d)\n", errno);
		exit(1);
	}
	else
		printf ("[Server] Listening the port %d successfully.\n", PORT);

	int success = 0;	
	sin_size = sizeof(struct sockaddr_in);
	socklen_t abc = (socklen_t) sin_size;
		/* Wait a connection, and obtain a new socket file despriptor for single connection */

{
	if ((nsockfd = accept(sockfd, (struct sockaddr *)&addr_remote, &abc)) == -1) 
		{
		    fprintf(stderr, "ERROR: Obtaining new Socket Despcritor. (errno = %d)\n", errno);
			exit(1);
		}
		else 
		{	printf("[Server] Server has got connected from %s.\n", inet_ntoa(addr_remote.sin_addr));
			
		}
	}

//	 char* inp = func(nsockfd);
  //   printf("Here is the authentication name: %s\n",inp);
}
	close(nsockfd);
	close(sockfd);
    
}
