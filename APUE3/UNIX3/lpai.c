#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{   
	char token[]="1";	
	int i;	int n = 3;	
	pid_t pid = 0;	
	int fd[2];	
	
	if (pipe(fd) == -1)
	{ /* create pipe */
	   perror("Failed to create the pipe");
	   return 1;	
	}	

	for (i = 1; i < n; i++) /* parent creates all children */	
	{	
		if ((pid = fork()) <= 0)
		break;
	}	       

	close(fd[0]);
	if (pid > 0)	
	{ //parent	
		 write(fd[1],token,1);     
		 wait(NULL);	
	}else //child	
	{   
	   while(1)     
	   { 
		   read(fd[0],token,1);   
		   int tmp = atoi(token[0]);	
		   tmp = tmp % 10;	     
	   if(tmp == 0)     
	   {	
		   printf("I got the token, my PID is %ld",(long)getpid());
		   exit(0);   
	    }	
		tmp++;   
		token[0] = (char)tmp; 
		write(fd[1],token,1);	
	    }     
	   
	}
	printf("I got the token, my PID is %ld\n",(long)getpid());
}
