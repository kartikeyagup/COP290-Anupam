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
 
                            //  global //
int sd;
struct sockaddr_in addr;
char reply[1024];
char buf[LENGTH];     
int nsd, bytes;
 SSL_CTX *ctx;
int server;
    char *portnum;
char ch = EOF;
                                // end here //
char *msg ="?FWQC";


long long pos_typefilesize(const char* filename)
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

char* func (SSL *ssl)
{    bzero(buf,512);

     int n = SSL_read(ssl,buf,511);
    // if (n < 0) error("ERROR reading from socket");
     char* identity =  new  char[strlen(buf)];
     identity =  buf;
     return identity;
}


int OpenListener(int port)
{
 
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
int fur=5;
int syncd=1;
int file4client(SSL* ssl, const char* fr_name , string locate  , string extension, long long size)
{       /* get any certificates */
    printf("[Client] Receiveing file from Server and saving it as final.txt...");
      

             // change them //
    int i=0;
     string l  = extension;
               l = int2str(fur+1) + l ;
               l = locate +  l;
               fur ++;
                 fr_name  = l.c_str();
    FILE *fr = fopen(fr_name,"a");
    
        if(fr == NULL)
            printf("File %s Cannot be opened.\n", fr_name);
        else
        {
            bzero(buf, LENGTH); 
            
      
            

        }
        int count2=0;
                int detected=0;
         int fr_block_sz = SSL_read(ssl, buf,sizeof(buf));


        printf("grfr\n");  
long long check=0;
                /* OPENING THE name of files */
   {     while( fr_block_sz > 0 )
        {    while(check!=size)
            {   
               // if(buf==msg){cout<<"happen"<<endl;return 0;}
              //  if(detected==1&&syncd==1){syncd++;return detected;}
                   check+=fr_block_sz;
              
                {
                    //int write_sz = fwrite(buf, sizeof(char), fr_block_sz, fr);
                    if(count2<=512000)
                        {   
                            count2=count2+fr_block_sz;
                            fwrite(buf, sizeof(char) , fr_block_sz , fr );
                        }
                    else 
                    {   fclose(fr);
                        l  = extension;
                        l = int2str(fur+1) + l ;
                        l = locate +  l;
                        fur ++;

                        i++;
                        count2=0;    
                         fr_name  = l.c_str();
                         cout<<fr_name<<endl;   
                        FILE *fr = fopen(fr_name,"a");
                        count2=count2+fr_block_sz;
                        cout<<fur<<endl;
                        fwrite(buf, sizeof(char) , fr_block_sz , fr );
                    }

                        bzero(buf, LENGTH);

            
                }
                   fr_block_sz = SSL_read(ssl, buf,sizeof(buf));

                  // fwrite(buf, sizeof(char), fr_block_sz, fr);
                   //fr_block_sz = SSL_read(ssl, buf,sizeof(buf));
        }
        return 0;
        }
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
            return detected;
           
}


void Servlet(SSL* ssl, int server, char* fileparts) /* Serve the connection -- threadable */
{  // char buf[1024];
    
    const char* HTMLecho="<html><body><pre>%s</pre></body></html>\n\n";
 
    if ( SSL_accept(ssl) == FAIL )     /* do SSL-protocol accept */
        ERR_print_errors_fp(stderr);
    else
    {   char* fr_name1 = "/home/btech/cs1130212/Desktop/java_tutorial.pdf";

        ShowCerts(ssl);
        file4client(ssl,"/home/btech/cs1130212/Desktop/","/home/btech/cs1130212/Desktop/",".pdf",pos_typefilesize(fr_name1));
        fr_name1 = "/home/btech/cs1130212/Desktop/qw1.mp3";
        file4client(ssl,"/home/btech/cs1130212/Desktop/","/home/btech/cs1130212/Desktop/",".mp3", pos_typefilesize(fr_name1));

      //  bytes = SSL_read(ssl, buf, sizeof(buf)); /* get request */
//		char* msg = func(ssl);
//		printf("%s\n",msg);
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
    nsd = SSL_get_fd(ssl);       /* get socket connection */
    SSL_free(ssl);         /* release SSL state */
    close(nsd);          /* close connection */
}
    
int main(int count, char *strings[])
{  
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
