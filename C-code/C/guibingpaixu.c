/*************************************************************************
    > File Name: 20.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年03月03日 星期四 21时33分19秒

	原理

	分而治之思想：

	Divide：将n个元素平均划分为各含n/2个元素的子序列；
	Conquer：递归的解决俩个规模为n/2的子问题；
	Combine：合并俩个已排序的子序列。
	性能

	时间复杂度总是为O(NlogN)，空间复杂度也总为为O(N)，算法与初始序列无关，排序是稳定的。

	优化

	优化思路：

	在规模较小时，合并排序可采用直接插入；
	在写法上，可以在生成辅助数组时，俩头小，中间大，这时不需要再在后边加俩个while循环进行判断，只需一次比完。
 ************************************************************************/

#include <stdio.h>

void merge(int r[], int s[], int x1, int x2, int x3)
{
	int i, j, k;
	i = x1;
	j = x2 + 1;
	k = x1;
	while ((i <= x2) && (j <= x3)){
		if (r[i] <= r[j]){
			s[k] = r[i];
			i++;
			k++;
		}else{
			s[k] = r[j];
			j++;
			k++;
		}
	}
	while (i <= x2)
		s[k++] = r[i++];
	while (j <= x3)
		s[k++] = r[j++];
}

void merge_sort(int r[], int s[], int m, int n)
{
	int p, t[20];
	if (m == n)
		s[m] = r[m];
	else{
		p = (m + n) / 2;
		merge_sort(r, t, m, p);
		merge_sort(r, t, p + 1, n);
		merge(t, s, m, p, n);
	}
}

void main()
{
	int	i, a[11];

	printf("请输入10个数据：\n");
	for (i = 1; i <= 10; i++)
		scanf("%d",&a[i]);

	merge_sort(a, a, 1, 10);

	printf("排序后的顺序是：\n");
	for (i = 1; i <= 10; i++)
		printf("%5d",a[i]);

	printf("\n");

}
