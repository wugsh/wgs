/*************************************************************************
	> File Name: testxier.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月04日 星期三 21时14分31秒
 ************************************************************************/

#include<stdio.h>

void sequence(int b[], int n)
{
    int d, j, i;
    d = n / 2;

    while (d > 0)
    {
        for (i = d + 1; i <= n; i++)
        {
            b[0] = b[i];
            j = i - d;
            if (j > 0 && b[0] < b[j]) 
            {
                b[i] = b[j];
                b[j] = b[0];
            }
        }
        d = d / 2;
    
    }

}

int main()
{
    int a[6],i = 1;

    while(i < 6)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("Before sequence:\n");
    for (i = 1; i < 6; i++ )
    {
        printf("a[%d] = %d ", i, a[i]);
    }
    printf("\n");

    sequence(a, 5);

    printf("After sequence:\n");
    i = 1;
    do{
        printf("a[%d] = %d ", i, a[i]);
        i++;
    }while(i < 6);

    return 0;

}
