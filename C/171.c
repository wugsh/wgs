/*************************************************************************
	> File Name: 171.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月28日 星期四 22时57分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

sort (char *string[], int n)
{
	char *p;
	int i,j;
	
	for (i = 0; i < n; i++ )
	{
		for (j = i + 1; j < n; j++)
		{	
			if (strcmp(string[i], string[j]) > 0)
			{
				p = string[j];
				string[j] = string[i];
				string[i]= p;
			}

		}
			
	}
	
}

int main()
{
	int k;
	char **q;
	char *string[5] = {"china", "usa", "atr", "ssh", "wsd"};
	q = string;
	sort(q, 5);
	for (k = 0; k < 5; k++)
	{
		printf("%s ", string[k]);
	}
	printf("\n");

	return 0;
}

