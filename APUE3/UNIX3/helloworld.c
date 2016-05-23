#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	printf("in the helloworld\n");
	for(i = 0; i < argc; i++)
		printf("NO.%d para:%s\n", i,*(argv+i));

	return 0;

}
