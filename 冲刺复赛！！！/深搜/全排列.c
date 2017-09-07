#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n,m=0,a[11],b[11]={0},j,k=-1;

void g(int m)
   {
    int i;
    k++;
    a[k]=m;
    if(k==n)
      {
       for(i=1;i<=n;i++)
          printf("%d ",a[i]);
       printf("\n");
      }
    else    
      for(i=1;i<=n;i++)
         if(b[i]==0)
           {
            b[i]=1;
            g(i);
           }
    k--;
    b[m]=0;
   }

int main()
{
 freopen("shuzi.txt","r",stdin);
 freopen("ans.txt","w",stdout); 
 scanf("%d",&n);
 g(m);
 return 0 ;
}
