#include <stdio.h>

int main()
{
	int m, n, min, i, count = 0;
	int data1[100], data2[100];
	scanf("%d %d", &m, &n);
	if (m > n)
		min = n;
	else
		min = m;
	for (i = 0; i < m; i++){
		scanf("%d", data1+i);
	}
	printf("\n");	
	for (i = 0; i < n; i++){
		scanf("%d", data2+i);
	}
   for (i = min-1; i >= 0; i--){
		if(data1[--m] != data2[--n])
			count++;	
   }	
   printf("%d\n", count);
   return 0;
}
