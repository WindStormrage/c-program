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
 freopen("add.txt","r",stdin);
 freopen("ans1.txt","w",stdout);
 gets(a);
 gets(b);
 
 n=strlen(a);
 m=strlen(b);
 
 for(i=1;i<=n;i++)//把char型数组的数字转移到int型中   要反着放  因为要进位 
    c[n-i]=a[i-1]-48;
 for(i=1;i<=m;i++)
    d[m-i]=b[i-1]-48;

 for(i=0;i<max(m,n);i++)//判断是否进位 
    if(e[i]+c[i]+d[i]<10)
      {
       e[i]=e[i]+c[i]+d[i];
      }
    else
      { 
       e[i+1]=(e[i]+c[i]+d[i])/10;
       e[i]=(e[i]+c[i]+d[i])%10;
      }

 if(e[max(m,n)]==0)//求输出数组e的长度 ：看最后有没有进位 
   for(i=max(m,n)-1;i>=0;i--)//反着输出 
      printf("%d",e[i]);
 else
   for(i=max(m,n);i>=0;i--)
      printf("%d",e[i]);
 return 0;
}
