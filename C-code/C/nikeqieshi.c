/*************************************************************************
	> File Name: nikeqieshi.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年06月03日 星期五 22时31分41秒
 ************************************************************************/

#include<stdio.h>

void main()
{
    int i, j, k = 0, l, n, m, sum, flag = 1;
    printf("please input an number: \n");
    scanf("%d", &n);
    m = n * n * n;
    i = m / 2;
    if (i % 2 == 0)
        i = i + 1;
    while(flag == 1 && i >= 1){
        sum = 0; 
        k = 0;
        while(1){
            sum += (i - 2 * k);
            k++;
            if (sum == m){
                printf("%d*%d*%d=%d=", n, n, n, m);
                for (l = 0; l < k - 1; l++)
                    printf("%d+", i - 1 * 2);
                printf("%d\n", i - (k - 1) * 2);
                flag = 0;
                break;
            }
            if (sum > m)
                break;
            
        }
        i -= 2;   
    }
}
