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
#include <unistd.h>
#include <netdb.h>
#include <iostream>
#include <errno.h>
#include <ifaddrs.h>
#include <fstream>
#include <vector>
using namespace std;
#define LENGTH 512

void error(const char *msg)
{
	perror(msg);
	exit(1);
}



string ip_address()
{
     struct ifaddrs *ifaddr, *ifa;
   int family, s;
   char host[NI_MAXHOST];

   if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
   }

   for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
                s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                                               host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
                if (s != 0 ) {
                        printf("getnameinfo() failed: %s\n", gai_strerror(s));
                        exit(EXIT_FAILURE);
                }
		if(strcmp(ifa->ifa_name,"lo")!=0){return host;}
		
        }
   }

   return host;
}


int main(int argc, char *argv[])
{
	/* Variable Definition */
	int sockfd; 
	int nsockfd;
	char revbuf[LENGTH]; 
	struct sockaddr_in remote_addr;
	int PORT = atoi(argv[1]);
	                             /* Get the Socket file descriptor */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
	    error("ERROR: Failed to obtain Socket Descriptor!\n");
	}
	                             /* Fill the socket address struct */
	remote_addr.sin_family = AF_INET; 
	remote_addr.sin_port = htons(PORT);
 	  
                            /*   Getting the  ip_address    */
	/*ifstream iss;
	iss.open("ip_config.txt");
	string line;
	getline(iss,line);
	char ip_copy[line.size()];
	for(int i=0;i<line.size();i++)
	{	ip_copy[i]=line[i];  }
	iss.close();*/
	
	char* ip_copy = "10.208.20.156";
    inet_pton(AF_INET,ip_copy, &remote_addr.sin_addr); 
	bzero(&(remote_addr.sin_zero), 8);                                         
   
	                                         /* Try to connect the remote */
	if (connect(sockfd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
	{
	    error("ERROR: Failed to connect to the host!\n");
	    cout<<strerror(errno)<<endl;
		exit(0);
	}
	else 
		printf("[Client] Connected to server at port %d...ok!\n", PORT);
	
	                                /* Receive File from Server  first file */
	
	printf("[Client] Receiveing file from Server and saving it as final.txt...");

                                  /* file with int wriiten */
    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    ifstream is;
    is.open("keyword.txt");
    bzero(revbuf,512);
    string use;
    int k=0;
    while(is>>use)
    { for(int i=0;i<use.size();i++)
    	{ revbuf[k]=use[i];k++;
      	}
      	revbuf[k]='\t';k++;
    }
    int n = write(sockfd, revbuf, strlen(revbuf));
    if (n < 0) 
         error("ERROR writing to socket");
    is.close();
    
    
    close(nsockfd);
    close(sockfd);
}
     
       
