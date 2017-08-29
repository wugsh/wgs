#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE 1024

extern int setup_tty (int);

int
main (void) 
{
	int fd;
	char buf1[SIZE], buf2[SIZE];


	while (1)
	  {
		  if ((fd = open ("/dev/tty100", O_EXCL | O_CREAT)) == -1)
//      parse the parameters from init, get which tty to open
		    {	    
			    close(fd);
			    perror (strerror (errno));
			 
			    continue;
		    }
		  else
		    {
			    close(fd);

			    printf ("open fd success\n");



			    if (dup2 (fd, 0) == -1 | dup2 (fd, 1) ==
				-1 | dup2 (fd, 2) == -1)
//       reopen STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO
			      {
				      printf ("open STDIN_FILENO or STDOUT_FILENO or STDERR_FILENO error\n");
				      return 1;
			      }


			    /*
			       modify the tty's attribute

			     */
			    if (fflush (stdin) != 0)
			      {
				      printf ("fflush fail\n");
			      }

			    while (1)
			      {
				      printf ("input your name:\n");
				      if (strcmp (gets (buf1), "dslab") == 0)
					{
						printf ("input your passwd:\n");
						if (strcmp(gets (buf2), "123") == 0)
						  {
							  printf ("welcome!\n");
				//      system("gnome-terminal -e ./mytty.c");


						  }
						else
						  {
							  printf ("your passwd error\n");
							  continue;
						  }
					}
				      else
					{
						printf ("your name error\n");
						continue;
					}
			      }


//      system("gnome-terminal -e ./mytty.c");
			    close (fd);
			    break;
		    }
	  }
	return 0;
}
