/*************************************************************************
	> File Name: erfenchazhao.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年05月19日 星期四 22时19分50秒
 ************************************************************************/

#include<stdio.h>

void binary_search(int key, int a[], int n)
{
    int low, high, mid, count = 0, count1 = 0;
    low = 0;
    high = n - 1;
    while (low < high){
        count++;
        mid = (low + high) / 2;
        if (key < a[mid])
        high = mid -1;
        else if (key > a[mid])
                low  = mid + 1;
            else if (key == mid){
                    printf ("find success!\n find times = %d a[%d] = %d\n", count, mid, key);
                    count ++;
                    break;
                }
    }
    if (count == 0)
        printf ("find error!\n");
}

void main()
{
    int i , key, n;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    key = 8;
    binary_search(key, a, 10);
    
}
