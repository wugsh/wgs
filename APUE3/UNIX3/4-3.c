#include "apue.h"

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	printf("argc = %d\n", argc);
	for(i = 1; i < argc; i++)
	{
		printf("%s: ",argv[i]);
		if(stat(argv[i], &buf) < 0)
		{
			err_ret("lstat error");
			continue;
		}
	if(S_ISREG(buf.st_mode))
		ptr = "regular";
	else if(S_ISDIR(buf.st_mode))
		ptr = "direcyory";
	else if(S_ISCHR(buf.st_mode))
		ptr = "character special";
	else if(S_ISBLK(buf.st_mode))
		ptr = "block special";
	else if(S_ISFIFO(buf.st_mode))
		ptr = "fifo";
	else if(S_ISLNK(buf.st_mode))
		ptr = "sysmbolic link";
	else if(S_ISSOCK(buf.st_mode))
		ptr = "socket";
	else 
		ptr = "** unknown mode **";
	printf("%s\n",ptr);
	printf("%d\n",buf.st_uid);

	}
	exit(0);
}