#include <stdio.h>
#include<math.h>
#include<string.h>

#define exp 1e-9
#define MAXN 1000010

//using namespace std;

/*≤Â»Î≈≈–Ú*/
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

/*—°‘Ò≈≈–Ú*/
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

/*√∞≈›≈≈–Ú*/
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

/*øÏÀŸ≈≈–Ú*/
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

/*œ£∂˚≈≈–Ú*/
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



/*∂—≈≈–Ú*/
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

/*πÈ≤¢≈≈–Ú*/
#define N 100010
int tmp[N],R[N];
int ans=0;//À≥¥¯«ÛƒÊ–Ú ˝ 
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
