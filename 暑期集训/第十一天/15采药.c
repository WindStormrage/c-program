#include<stdio.h>
int t/*��ʱ��*/,m/*��ҩ��Ŀ*/,money[1001]/*��ֵ*/,time[1001]/*ĳ���ҩ��ʱ��*/,f[1001][1001]={0};
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
          f[a][b]=max(f[a-1][b],/*��һ�� �� ����ʱ���ȥa�õ�ʱ��  ��Ӧ��Ǯ����a�ļ�Ǯ*/f[a-1][b-time[a]]+money[a]);
       }
 printf("%d",f[m][t]);
 system("pause");
 return 0;
}
