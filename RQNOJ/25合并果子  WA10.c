#include<stdio.h>
int main()
{
 int m,n,i,j,t,a[10000];
 scanf("%d",&n);
 for(m=0;m<n;m++)
    scanf("%d",&a[m]);
 for(i=0;i<n;i++) //Ã°ÅÝ·¨ÅÅÐò 
    for(j=0;j<n-i-1;j++) 
       if(a[j]>a[j+1]) 
         {
          t=a[j];
          a[j]=a[j+1]; 
          a[j+1]=t;
         }
 for(j=0,m=0;m<n;m++)
    {
     if(m+2>n)
       if(a[m]+a[m+1]>a[m+2])
         {
          t=a[m+2];
          a[m+2]=a[m];
          a[m]=t;
          continue;
         }
     a[m+1]=a[m]+a[m+1];
     j=j+a[m+1];
    }
 printf("%d",j);
 system("pause");
 return 0;
} 
