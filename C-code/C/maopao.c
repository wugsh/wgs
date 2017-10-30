/*************************************************************************
	> File Name: maopao.c
	> Author: Wu GaoSHeng
	> Mail: 
	> Created Time: 2016年05月04日 星期三 22时17分24秒

    原理:

    俩俩比较相邻记录的排序码，若发生逆序，则交换；有俩种方式进行冒泡，一种是先把小的冒泡到前边去，
    另一种是把大的元素冒泡到后边。

    性能:
    时间复杂度为O(N^2)，空间复杂度为O(1)。排序是稳定的，排序比较次数与初始序列无关，但交换次数与初始序列有关。

    优化:    
        若初始序列就是排序好的，对于冒泡排序仍然还要比较O(N^2)次，但无交换次数。可根据这个进行优化，设置一个flag，
    当在一趟序列中没有发生交换，则该序列已排序好，但优化后排序的时间复杂度没有发生量级的改变。
 ************************************************************************/

#include<stdio.h>

void sequence(int b[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (b[i] < b[j])
            {
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }

    }
}


int main()
{
    int a[5],i = 0;

    while(i < 5)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("Before sequence:\n");
    for (i = 0; i < 5; i++ )
    {
        printf("a[%d] = %d ", i, a[i]);
    }
    printf("\n");

    sequence(a, 5);

    printf("After sequence:\n");
    i = 0;
    do{
        printf("a[%d] = %d ", i, a[i]);
        i++;
    }while(i < 5);

    return 0;

}
