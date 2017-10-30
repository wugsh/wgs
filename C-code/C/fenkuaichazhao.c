/*************************************************************************
	> File Name: fenkuaichazhao.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年05月23日 星期一 21时30分03秒

	要点：
		要求所有元素均匀的分成块，块间按大小排序，块內不排序，所以要建立一个块的最大（或最小）关键字表，称为索引表
		整个数组排序可以有序也可以无序，但满足第一块的元素都小于第二块的所有元素，第二块的又小于第三块的，以此类推。
 ************************************************************************/

#include<stdio.h>

struct index
{
    int key;
    int start;
    int end;
}index_table[4];

int block_search(int key, int a[])
{
    int i,j;
    i = 1;
    while (i <= 3 && key > index_table[i].key)
        i++;
    if (i > 3)
        return 0;
    j = index_table[i].start;
    while (j <= index_table[i].end && a[j] != key)
        j++;
    if (j > index_table[i].end)
        j = 0;
    return j;
}

void main()
{
    int i, j = 0, k, key, a[16];
    printf("please input 15 numbers: \n");
    for (i = 1; i < 16; i++) 
        scanf("%d", &a[i]);
    for (i = 1; i <= 3; i++){  //分成3块，每块5项
        index_table[i].start = j + 1; //确定每块的首项
        j = j + 1;
        index_table[i].end = j + 4; //确定每块的末项
        j =  j + 4;
        index_table[i].key = a[j]; //确定每块的最大值
    }
    printf("which number do you want search:\n");
    scanf("%d", &key);
    k = block_search(key, a);
    if (k != 0)
        printf("search success, the location is: %d\n", k);
    else
    printf("search error\n");
}
