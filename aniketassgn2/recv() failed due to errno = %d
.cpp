iled due to errno = %d\n", errno);
					exit(1);
	            }
        	}
			printf("Ok received from client!\n");
			fclose(fr); 
		}

		/* Call the Script */

		/* Send File to Client */
		//if(!fork())
		//{
		    char* fs_name = "/home/btech/cs1130212/Desktop/1. Unconditionally.mp3";
		    char sdbuf[LENGTH]; // Send buffer
		    printf("[Server] Sending %s to the Client...", fs_name);
		    FILE *fs = fopen(fs_name, "r");
		    if(fs == NULL)
		    {
		        fprintf(stderr, "ERROR: File %s not found on server. (errno = %d)\n", fs_name, errno);
				exit(1);
		    }
		    bzero(sdbuf, LENGTH); 
		    int fs_block_sz; 
		    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0)
		    {
		        if(send(nsockfd, sdbuf, fs_block_sz, 0) < 0)
		        {
		            fprintf(stderr, "ERROR: Failed to send file %s. (errno = %d)\n", fs_name, errno);
		            exit(1);
		        }
		        bzero(sdbuf, LENGTH);
		    }
		    printf("Ok sent to client!\n");
		    success = 1;
		    close(nsockfd);
		    printf("[Server] Connection with Client closed. Server will wait now...\n");
		    while(waitpid(-1, NULL, WNOHANG) > 0);
		//}
	}
}
iled due to errno = %d\n", errno);
					exit(1);
	            }
        	}
			printf("Ok received from client!\n");
			fclose(fr); 
		}

		/* Call the Script */

		/* Send File to Client */
		//if(!fork())
		//{
		    char* fs_name = "/home/btech/cs1130212/Desktop/1. Unconditionally.mp3";
		    char sdbuf[LENGTH]; // Send buffer
		    printf("[Server] Sending %s to the Client...", fs_name);
		    FILE *fs = fopen(fs_name, "r");
		    if(fs == NULL)
		    {
		        fprintf(stderr, "ERROR: File %s not found on server. (errno = %d)\n", fs_name, errno);
				exit(1);
		    }
		    bzero(sdbuf, LENGTH); 
		    int fs_block_sz; 
		    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0)
		    {
		        if(send(nsockfd, sdbuf, fs_block_sz, 0) < 0)
		        {
		            fprintf(stderr, "ERROR: Failed to send file %s. (errno = %d)\n", fs_name, errno);
		            exit(1);
		        }
		        bzero(sdbuf, LENGTH);
		    }
		    printf("Ok sent to client!\n");
		    success = 1;
		    close(nsockfd);
		    printf("[Server] Connection with Client closed. Server will wait now...\n");
		    while(waitpid(-1, NULL, WNOHANG) > 0);
		//}
	}
}
