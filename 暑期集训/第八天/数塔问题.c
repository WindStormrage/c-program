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
 int k,w[101][101];
 int a,b,wmax=0;
 scanf("%d",&k);
 for(a=0;a<k;a++)
    for(b=0;b<=a;b++)
       scanf("%d",&w[a][b]);
 for(a=0;a<k;a++)
    {
     w[a+1][0]=w[a][0]+w[a+1][0];
     w[a+1][a+1]=w[a][a]+w[a+1][a+1];
     for(b=1;b<=a;b++)
        w[a+1][b]=max(w[a][b],w[a][b-1])+w[a+1][b];
    }
 for(b=0;b<k;b++)
    if(w[k-1][b]>wmax)
      wmax=w[k-1][b];
 printf("%d",wmax);
 system("pause");
 return 0;
}
