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
 
 for(i=1;i<=n;i++)//��char�����������ת�Ƶ�int����   Ҫ���ŷ�  ��ΪҪ��λ 
    c[n-i]=a[i-1]-48;
 for(i=1;i<=m;i++)
    d[m-i]=b[i-1]-48;

 for(i=0;i<max(m,n);i++)//�ж��Ƿ��λ 
    if(e[i]+c[i]+d[i]<10)
      {
       e[i]=e[i]+c[i]+d[i];
      }
    else
      { 
       e[i+1]=(e[i]+c[i]+d[i])/10;
       e[i]=(e[i]+c[i]+d[i])%10;
      }

 if(e[max(m,n)]==0)//���������e�ĳ��� ���������û�н�λ 
   for(i=max(m,n)-1;i>=0;i--)//������� 
      printf("%d",e[i]);
 else
   for(i=max(m,n);i>=0;i--)
      printf("%d",e[i]);
 return 0;
}
