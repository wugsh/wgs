#include <unistd.h>
#include <stdlib.h>
#define BUFFSIZE 4096
int main(void)
{
	int n;
	char buf[BUFFSIZE];
	while((n = read(0, buf, BUFFSIZE)) > 0)
		if(write(0, buf, n) != n)
			err_sys("write error");
	if(n < 0)
		err_sys("read error");
	exit(0);
}
