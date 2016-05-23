#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t t;
	struct tm *tmp;
	struct tm *tmp1;
	char buf1[64];
	char buf2[64];

	time(&t);
	tmp = localtime(&t);
//	tmp1 = gmtime(&t);

	if(strftime(buf1, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length 16 is too small\n");
	else
		printf("%s\n", buf1);
	if(strftime(buf2, 64, "time and date: %X, %F, %U", tmp) == 0)
		printf("buffer length 64 is too small\n");
	else
		printf("%s\n", buf2);
	exit(0);
}
