#include<stdio.h>
int t/*总时间*/,m/*草药数目*/,money[1001]/*价值*/,time[1001]/*某株草药的时间*/,f[1001][1001]={0};
int max(int a,int b)
{ 
 if(a>b)
   return a;
 else
   return b;
} 
int main()
{
 int a,b,c;
 scanf("%d%d",&t,&m);
 for(a=1;a<=m;a++)
    scanf("%d%d",&time[a],&money[a]);
 for(a=1;a<=m;a++)
    for(b=1;b<=t;b++)
       {
        if(time[a]>b)
          f[a][b]=f[a-1][b];
        else
          f[a][b]=max(f[a-1][b],/*上一行 ， 所在时间减去a用的时间  对应价钱加上a的价钱*/f[a-1][b-time[a]]+money[a]);
       }
 printf("%d",f[m][t]);
 system("pause");
 return 0;
}
