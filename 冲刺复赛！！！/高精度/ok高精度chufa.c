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
 char a[1000]; 
 int c[1000]={0},d,e[1000]={0};
 int i,n,g=0;
 freopen("chufa.txt","r",stdin);
 freopen("ans3.txt","w",stdout);
 gets(a);
 scanf("%d",&d);
 n=strlen(a);
 for(i=0;i<n;i++)
    c[i]=a[i]-48;
 for(i=0;i<n;i++)
    {
     g=g*10+c[i];
     if(g/d==0)
       e[i]=0;
     else
       {
        e[i]=g/d;
        g=g%d;
       }
    }
 for(i=0;i<n;i++)
    if(e[i]!=0)
      break;
 for(i;i<n;i++)
    printf("%d",e[i]);
 return 0;
}
