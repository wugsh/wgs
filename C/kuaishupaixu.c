/*************************************************************************
	> File Name: kuaishupaixu.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年05月04日 星期三 22时57分42秒
快速排序

原理

分而治之思想：

Divide：找到基准元素pivot，将数组A[p..r]划分为A[p..pivotpos-1]和A[pivotpos+1…q]，左边的元素都比基准小，右边的元素都比基准大;
Conquer：对俩个划分的数组进行递归排序；
Combine：因为基准的作用，使得俩个子数组就地有序，无需合并操作。
性能

快排的平均时间复杂度为O(NlogN），空间复杂度为O(logN)，但最坏情况下，时间复杂度为O(N^2)，空间复杂度为O(N)；且排序是不稳定的，但每次都能确定一个元素所在序列中的最终位置，复杂度与初始序列有关。

优化

当初始序列是非递减序列时，快排性能下降到最坏情况，主要因为基准每次都是从最左边取得，这时每次只能排好一个元素。
所以快排的优化思路如下：

优化基准，不每次都从左边取，可以进行三路划分，分别取最左边，中间和最右边的中间值，再交换到最左边进行排序；或者进行随机取得待排序数组中的某一个元素，再交换到最左边，进行排序。
在规模较小情况下，采用直接插入排序)
************************************************************************/

#include<stdio.h>

void qusort(int s[], int start, int end)
{
    int i, j;

    i = start;
    j = end;
    s[0] = s[i];
    
    while (i < j){
        while (i < j && s[0] < s[j])
            j--;
        if (i < j){
            s[i] = s[j];
            i++; 
        }
        while (i < j && s[i] <= s[0])
            i++;
        if (i < j){
            s[j] = s[i];
            j--;
        }
    }
    s[i] = s[0];

    if (start < i)
        qusort(s, start, j - 1);
    if (i < end)
        qusort(s, j + 1, end);
}

void main()
{
    int a[11], i;
    printf("input 10 numbers : \n");
    for (i = 1; i <= 10; i++)
        scanf("%d", &a[i]);
    
    qusort(a, 1,10);
    
    printf("After 10 numbers: \n");
    for (i = 1; i <= 10; i++)
        printf("%5d",a[i]);

    printf("\n");
}
