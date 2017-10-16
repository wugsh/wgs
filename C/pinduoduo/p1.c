/*************************************************************************
	> File Name: p1.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 01 Aug 2017 08:04:13 PM CST
 ************************************************************************/

#include<stdio.h>
void sort(int s[], int n)
{
	int i, j, d;
	d = n / 2;
	while(d >= 1){
		for(i = d+1; i <=n; i++){
			s[0] = s[i];
			j = i - d;
			while((j > 0) && (s[0] < s[j])){
				s[j+d] = s[j];
				j = j - d;
			}
			s[j+d] = s[0];
		}
		d  = d / 2;
	}

}

int main()
{
	int n, A[1024];
	int i, max1, max2;

	while(scanf("%d", &n) != EOF){
		for (i = 1; i <= n; i++){
			scanf("%d",A+i);
		}
		sort(A, n);
		max1 = A[n] * A[n-1] * A[n-2];
		max2 = A[1] * A[2] * A[n];
		if ( max1 > 0 || max2 > 0)
        {	if(max1 > max2)
				printf("%d\n", max1);
			else
				printf("%d\n", max2);
        }
        else
            printf("0\n");
	}
	return 0;
}
