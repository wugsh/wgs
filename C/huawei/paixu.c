//排序算法讲解：http://www.runoob.com/w3cnote/sort-algorithm-summary.html
/*
1、几种常见排序算法的时间复杂度
排序方法		平均情况	最好情况	最坏情况	
直接插入排序         O(n2)       O(n2)       O(n2)
冒泡排序		 O(n2)       O(n)        O(n2)
快速排序		O(nlog2n)   O(nlog2n)   O(n2)
简单选择排序	       O(n2)	    O(n2)       O(n2)
堆排序		 O(nlog2n)   O(nlog2n)   O(nlog2n）
归并排序		O(nlog2n)   O(nlog2n)   O(nlog2n)

由此可见，在最好情况下，直接插入排序和起泡排序最快；平均情况下，快速排序最快；在最坏情况下，堆排序和归并排序最快。

2、稳定性比较

稳定性算法包括：直接插入排序，起泡排序，归并排序；

非稳定性算法包括：堆排序，快速排序，简单选择排序；

3、使用情形分析
当待排序记录个数n较大，关键码分布较随机，且对稳定性不作要求时，宜采用快速排序
当待排序记录个数n较大，内存空间允许，且要求排序稳定时，宜采用归并排序
当待排序记录个数n较大，关键码分布可能出现正序或逆序的情况，且对稳定性不作要求时，宜采用堆排序或归并排序。
当待排序记录个数n较大，而只要找出最小的前几个记录，采用堆排序或者简单选择排序
当待排序记录个数n较小，记录已基本有序，且要求稳定，宜采用直接插入排序
快速排序和归并排序在待排序记录个数n值较小时的性能不如直接插入排序，因此在实际应用时，可将它们和直接插入排序“混合”使用。
*/

#include <stdio.h>
#include<math.h>
#include<string.h>

#define exp 1e-9
#define MAXN 1000010

//using namespace std;

/*插入排序*/
void InsertSort(int R[],int n)
{
	int i,j,tmp;
	for(i=2;i<=n;i++)
	{
		tmp=R[i];
		j=i-1;
		while(j>=1 && R[j]>tmp)
		{
			R[j+1]=R[j];
			j--;
		}
		R[j+1]=tmp;
	}
} 

/*选择排序*/
void SelectSort(int R[],int n)
{
	int i,j,k,tmp;
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(R[j]<R[k])
			{
				k=j;
			}
		}
		tmp=R[i];
		R[i]=R[k];
		R[k]=tmp;
	}
}

/*冒泡排序*/
void BubbleSort(int R[],int n)
{
	int i,j,tmp,flag;
	for(i=n;i>=2;i--)
	{
		flag=0;
		for(j=1;j<i;j++)
		{
			if(R[j]>R[j+1])
			{
				tmp=R[j];
				R[j]=R[j+1];
				R[j+1]=tmp;
				flag=1;
			}
		}
		if(flag==0)
			return;
	}
}

/*快速排序*/
void QuickSort(int s[], int start, int end)
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
        QuickSort(s, start, j - 1);
    if (i < end)
        QuickSort(s, j + 1, end);
}

/*希尔排序*/
void Shsort(int s[], int n)
{
	int i, j, d;
	d = n / 2;
	while(d >= 1){
		for (i = d + 1; i <=n; i++){
			s[0] = s[i];
			j = i - d;
			while((j > 0) && (s[0] < s[j])){
				s[j+d] = s[j];
				j = j - d;
			} 
			s[j+d] = s[0];
		}
		d = d / 2;
	}
}



/*堆排序*/
void Sift(int R[],int low,int high)
{
	int i=low,j=2*i;
	int tmp=R[i];
	while(j<=high)
	{
		if(j<high && R[j]<R[j+1])
		{
			++j;	
		}
		if(tmp<R[j])
		{
			R[i]=R[j];
			i=j;
			j=2*i;	
		}
		else
			break;	
	}
	R[i]=tmp;	
}

void heapSort(int R[],int n)
{
	int i;
	int tmp;
	for(i=n/2;i>=1;--i)
	{
		Sift(R,i,n);	
	}
	for(i=n;i>=2;--i)
	{
		tmp=R[1];
		R[1]=R[i];
		R[i]=tmp;	
		Sift(R,1,i-1);
	}	
} 

/*归并排序*/
#define N 100010
int tmp[N],R[N];
int ans=0;//顺带求逆序数 
void Merge(int l,int m,int r)
{
	int i=l;
	int j=m+1;
	int k=l;
	
	while(i<=m && j<=r)
	{
		if(R[i]>R[j])
		{
			tmp[k++]=R[j++];
			ans+= m-i+l;	
		}
		else
		{
			tmp[k++]=R[i++];	
		}	
	}
	while(i<=m)
		tmp[k++]=R[i++];
	while(j<=r)
		tmp[k++]=R[j++];
	for(i=l;i<=r;i++)
	{
		R[i]=tmp[i];	
	}	
}

void MergeSort(int l,int r)
{
	if(l<r)
	{
		int m=(l+r)>>1;
		MergeSort(l,m);
		MergeSort(m+1,r);
		Merge(l,m,r);	
	}	
} 

int main()
{
//	freopen("D:\\in.txt","r",stdin);
    int len,i;
    while(scanf("%d",&len)!=EOF)
    {
    	for(i=1;i<=len;i++)
    	{
    		scanf("%d",&R[i]);
		}
//		InsertSort(R,len);
//		SelectSort(R,len);
//		BubbleSort(R,len);
//		QuickSort(R,1,len);
		Shsort(R, len);
//		heapSort(R,len);
//		MergeSort(1,len);
		for(i=1;i<=len;i++)
		{
			printf("%d ",R[i]);
		}
		printf("\n");
	}
	return 0;   
}
