#include <stdio.h>
int main()
{
    int i,j,n,k,t; int s[65535];
    while(scanf("%d",&n)!=EOF)
    {
      for(t=0;t<n;t++)
         {
          scanf("%d",&s[t]);
         }
      for(i=0;i<n-1;i++)
         {
          for(j=i+1;j<n;j++)
            {
             if(s[i]>s[j])
              { k=s[i];
                s[i]=s[j];
                s[j]=k;
              }
            }
         }
     for(i=0;i<n;i++){
		 if(s[i]!=s[i+1])
			printf("%d\n",s[i]);
        }
   }
}
