/*原理

每次从未排序的序列中找到最小值，记录并最后存放到已排序序列的末尾

性能

时间复杂度为O(N^2)，空间复杂度为O(1)，排序是不稳定的（把最小值交换到已排序的末尾导致的），每次都能确定一个元素所在的最终位置，比较次数与初始序列无关。*/

#include <stdio.h>

void sequence(int a[], int n)
{
	int i, j, t;

	for (i = 1; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				t = a[i];	
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

int main()
{
    int a[6],i = 1;

    while (i < 6){
        scanf("%d", &a[i]);
        i++;
    }

    printf("Before sequence:\n");
    for (i = 1; i < 6; i++ ) {
        printf("a[%d] = %d ", i, a[i]);
    }
    printf("\n");

    sequence(a, 6);

    printf("After sequence:\n");
    i = 1;
    do{
        printf("a[%d] = %d ", i, a[i]);
        i++;
    }while (i < 6);

    return 0;

}
