#include<unistd.h>
#include<stdio.h>
int main(void)
{
	if(symlink("ssss","lnk") < 0)
	{
		printf("link error\n");
	}
	return 0;
}
