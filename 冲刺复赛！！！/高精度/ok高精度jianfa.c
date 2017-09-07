#include<stdio.h>

int max(int a,int b)
{
 if(a>b)
   return a;
 else
   return b;
}

int main()
{
 char a[1000],b[1000]; 
 int c[1000]={0},d[1000]={0},e[1000]={0};
 int i,j,n,m,g;
 freopen("jian.txt","r",stdin);
 freopen("ans2.txt","w",stdout);
 gets(a);
 gets(b);
 n=strlen(a);
 m=strlen(b);
 
 if(n>m)//±£Ö¤c>d 
   g=1;
 else
   g=0;
 if(n==m)
   {
    for(i=0;i<max(n,m);i++)
       if(a[i]>b[i])
         {
          g=1;
          break;
         }
   }

 if(g==1)
   {
    for(i=1;i<=n;i++)
       c[n-i]=a[i-1]-48;
    for(i=1;i<=m;i++)
       d[m-i]=b[i-1]-48;
   }
 else  
   {
    for(i=1;i<=n;i++)
       d[n-i]=a[i-1]-48;
    for(i=1;i<=m;i++)
       c[m-i]=b[i-1]-48;
   }
 for(i=0;i<=max(n,m);i++)
    if(c[i]-d[i]<0)
      {
       c[i+1]--;
       e[i]=10+c[i]-d[i];
      }
    else
      e[i]=c[i]-d[i];

 for(i=max(n,m);i>0;i--)
    if(e[i]!=0)
      break;
 for(i;i>=0;i--)
    printf("%d",e[i]);
 return 0;
}
