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
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#define LENGTH 1024
#define FAIL    -1
 


string int2str(int n)
{   string l="";
    if(n==0)return"0";
    while(n!=0)
    {  l =  char(n%10+48) + l;
        n=n/10;
     }
     return l;
 }




int OpenListener(int port)
{   int sd;
    struct sockaddr_in addr;
 
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        perror("can't bind port");
        abort();
    }
    if ( listen(sd, 10) != 0 )
    {
        perror("Can't configure listening port");
        abort();
    }
    return sd;
}
 
int isRoot()
{
    if (getuid() != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
 
}
SSL_CTX* InitServerCTX(void)
{   const SSL_METHOD *method;
    SSL_CTX *ctx;
 
    OpenSSL_add_all_algorithms();  /* load & register all cryptos, etc. */
    SSL_load_error_strings();   /* load all error messages */
    method = SSLv3_server_method();  /* create new server-method instance */
    ctx = SSL_CTX_new(method);   /* create new context from method */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}
 
void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile)
{
    /* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if ( SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* verify private key */
    if ( !SSL_CTX_check_private_key(ctx) )
    {
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}
 
void ShowCerts(SSL* ssl)
{   X509 *cert;
    char *line;
 
    cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);
        X509_free(cert);
    }
    else
        printf("No certificates.\n");
}
  int count2=0;
void Servlet(SSL* ssl, int server, char* fileparts) /* Serve the connection -- threadable */
{  // char buf[1024];
    char reply[1024];
char buf[LENGTH];    
    int sd, bytes;
    const char* HTMLecho="<html><body><pre>%s</pre></body></html>\n\n";
 
    if ( SSL_accept(ssl) == FAIL )     /* do SSL-protocol accept */
        ERR_print_errors_fp(stderr);
    else
    {
        ShowCerts(ssl);
	    /* get any certificates */
printf("[Client] Receiveing file from Server and saving it as final.txt...");
vector<char*>  fil;
		fil.push_back("/home/btech/cs1130212/Desktop/6.pdf");
      
int fur=6;
             // change them //
         int i=0;
		FILE *fr = fopen(fil[i],"a");
	
		if(fr == NULL)
			printf("File %s Cannot be opened.\n", fil[i]);
		else
		{
			bzero(buf, LENGTH); 
			
	  
            

        }
        int count1=0;
         int fr_block_sz = SSL_read(ssl, buf,sizeof(buf));
        
		printf("grfr\n");				/* OPENING THE name of files */
		while( fr_block_sz > 0 )
		{  	  
               count1++;
				{
					//int write_sz = fwrite(buf, sizeof(char), fr_block_sz, fr);
                    if(count2<=512000)
                        {   
                            count2=count2+fr_block_sz;
                            fwrite(buf, sizeof(char) , fr_block_sz , fr );
                        }
                    else 
                    {   fclose(fr);
                        string l  = ".pdf";
                        l = int2str(fur+1) + l ;
                        l = "/home/btech/cs1130212/Desktop/" +  l;
                        fur ++;
                     
                        i++;
                        count2=0;    
                        const char* fr_name  = l.c_str();
                         cout<<fr_name<<endl;   
                        FILE *fr = fopen(fr_name,"a");
                        count2=count2+fr_block_sz;
                        fwrite(buf, sizeof(char) , fr_block_sz , fr );
                    }

    		            bzero(buf, LENGTH);
				//	if(write_sz < fr_block_sz)
				//	{
				//		printf("not\n");exit(0);//error("File write failed.\n");
				//	}
					
			
				}
		           fr_block_sz = SSL_read(ssl, buf,sizeof(buf));
                  // fwrite(buf, sizeof(char), fr_block_sz, fr);
                   //fr_block_sz = SSL_read(ssl, buf,sizeof(buf));
		}
		printf("%i\n",count1);
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
      //  bytes = SSL_read(ssl, buf, sizeof(buf)); /* get request */
    
     /*   if ( bytes > 0 )
        {
            buf[bytes] = 0;
            printf("Client msg: \"%s\"\n", buf);
            sprintf(reply, HTMLecho, buf);   /* construct reply */
       //     SSL_write(ssl, reply, strlen(reply)); /* send reply */
        //}
       // else
     //       ERR_print_errors_fp(stderr);
    }
    sd = SSL_get_fd(ssl);       /* get socket connection */
    SSL_free(ssl);         /* release SSL state */
    close(sd);          /* close connection */
}
    
int main(int count, char *strings[])
{   SSL_CTX *ctx;
int server;
    char *portnum;
    char* fileparts  = new char[2097152];
 
   
    if ( count != 2 )
    {
        printf("Usage: %s <portnum>\n", strings[0]);
        exit(0);
    }
    SSL_library_init();
 
    portnum = strings[1];
    ctx = InitServerCTX();        /* initialize SSL */
    LoadCertificates(ctx, "mycert.pem", "mycert.pem"); /* load certs */
    server = OpenListener(atoi(portnum));    /* create server socket */

    
    {   struct sockaddr_in addr;    // another socket descriptor //
        socklen_t len = sizeof(addr);
        SSL *ssl;
		
        int client = accept(server, (struct sockaddr*)&addr, &len);  /* accept connection as usual */
        printf("Connection: %s:%d\n",inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        ssl = SSL_new(ctx);              /* get new SSL state with context */
        SSL_set_fd(ssl, client);      /* set connection socket to SSL state */
        Servlet(ssl,server,fileparts);         /* service connection */
    }
    close(server);          /* close server socket */
    SSL_CTX_free(ctx);         /* release context */
}
