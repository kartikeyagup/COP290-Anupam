//SSL-Client.c
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;


#define LENGTH 512
#define FAIL    -1
 
                    //   global variables  //

int sd;
struct hostent *host;
struct sockaddr_in addr;
SSL_CTX *ctx;
int server;
SSL *ssl;
char buf[10240];
int bytes;
char sdbuf[LENGTH]; 
char *hostname, *portnum;
char ch=EOF;
              // end here    //  


string int2str(int n)
{   string l="";
    if(n==0)return"0";
    while(n!=0)
    {  l =  char(n%10+48) + l;
        n=n/10;
     }
     return l;
}




int OpenConnection(const char *hostname, int port)
{   

    if ( (host = gethostbyname(hostname)) == NULL )
    {   
        perror(hostname);
        abort();
    }
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    if ( connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        close(sd);
        perror(hostname);
        abort();
    }
    return sd;
}
 
SSL_CTX* InitCTX(void)
{   const SSL_METHOD *method;
    SSL_CTX *ctx;
 
    OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
    SSL_load_error_strings();   /* Bring in and register error messages */
    method = SSLv3_client_method();  /* Create new client-method instance */
    ctx = SSL_CTX_new(method);   /* Create new context */
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
 
    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);       /* free the malloc'ed string */
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);       /* free the malloc'ed string */
        X509_free(cert);     /* free the malloc'ed certificate copy */
    }
    else
        printf("No certificates.\n");
}
 
void file2server(char *fs_name)
{   
   
    printf("[Client] Sending %s to the Server...", fs_name);
    FILE *fs = fopen(fs_name, "r");
    
        if(fs == NULL)
        {
            printf("ERROR: File %s not found.\n", fs_name);
            exit(1);
        }

        bzero(sdbuf, LENGTH); 
        int fs_block_sz = 0 ;
        int count=0;
        fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs);
        printf("%i\n",fs_block_sz);
        while(fs_block_sz >0)
        {  
            count++;
            if(fs_block_sz==512)
            { if(SSL_write(ssl, sdbuf, sizeof(sdbuf)) < 0)
            {
                printf("ERROR: Failed to send file %s.\n", fs_name);
                break;
            }
            }   
            else if(fs_block_sz!=512)
            {   printf("one\n"); SSL_write(ssl,sdbuf,fs_block_sz) ;}     
            bzero(sdbuf, LENGTH);
            fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs);
        }
        printf("Ok File %s from Client was Sent!\n", fs_name);
  }

 void  file4server(char* fs_name)
 {      printf("[Client] Receiveing file from the server..");
        FILE *fr = fopen(fs_name, "a");
        int  fr_block_sz = 0;
        if(fr == NULL)
            printf("File %s Cannot be opened.\n", fs_name);
        else
        {
            bzero(sdbuf, LENGTH); 
        }
        fr_block_sz = SSL_read(ssl,sdbuf, sizeof(sdbuf) );
                            /* OPENING THE name of files */
        while( fr_block_sz > 0 )
        {     
                
            int write_sz = fwrite(sdbuf, sizeof(char) , fr_block_sz , fr );
            bzero(sdbuf, LENGTH);
            if(write_sz < fr_block_sz)
                {
                      printf("not\n");exit(0);//error("File write failed.\n");
                }
            fr_block_sz = SSL_read(ssl, sdbuf,sizeof(sdbuf));
                  // fwrite(buf, sizeof(char), fr_block_sz, fr);
                   //fr_block_sz = SSL_read(ssl, buf,sizeof(buf));
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


void text2server(string textname)
{   ifstream is;
    is.open(textname.c_str());
    bzero(buf,10240);
    string use;
    int k=0;
    while(is>>use)
    { for(int i=0;i<use.size();i++)
        { buf[k]=use[i];k++;
        }
        buf[k]='\t';k++;
    }
    int n = SSL_write(ssl, buf, strlen(buf));
    if (n < 0) 
    {  printf("ERROR writing to socket");
        exit(0);
    }
    is.close();
}

int main(int count, char *strings[])
{  
 
    if ( count != 3 )
    {
        printf("usage: %s <hostname> <portnum>\n", strings[0]);
        exit(0);
    }
    SSL_library_init();
    hostname=strings[1];
    portnum=strings[2];
 
    ctx = InitCTX();
    LoadCertificates(ctx, "mycert1.pem", "mycert1.pem"); 
    server = OpenConnection(hostname, atoi(portnum));

    ssl = SSL_new(ctx);      /* create new SSL connection state */
 
    SSL_set_fd(ssl, server);    /* attach the socket descriptor */
    if ( SSL_connect(ssl) == FAIL )   /* perform the connection */
        ERR_print_errors_fp(stderr);
    else
    {   //char *msg = "Hello???";
 
        printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
        ShowCerts(ssl);        /* get any certs */
        file2server("/home/btech/cs1130212/Desktop/java_tutorial.pdf");
        printf("pewrf\n");
        char *msg ="?FWQC";
        SSL_write(ssl,msg,strlen(msg));
	    file2server("/home/btech/cs1130212/Desktop/qw1.mp3");
           printf("pewrf\n");
      //  SSL_write(ssl, msg, strlen(msg));   /* encrypt & send message */
      //  bytes = SSL_read(ssl, buf, sizeof(buf)); /* get reply & decrypt */
   //     buf[bytes] = 0;
     //   printf("Received: \"%s\"\n", buf);
        SSL_free(ssl);        /* release connection state */
    }
    close(server);         /* close socket */
    SSL_CTX_free(ctx);        /* release context */
    return 0;
}
