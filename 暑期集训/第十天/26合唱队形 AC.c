#include<stdio.h>
int main()
{
 int n,t[231],k[231]={0},z[231]={0};
 int nmax=0,max,a,b,c,m=0,i,j;
 scanf("%d",&n);
 for(a=0;a<n;a++)
    scanf("%d",&t[a]);
    
 for(b=1;b<n;b++)
    {
     k[0]=1;
     for(c=0;c<b;c++)
     if(t[b]>t[c]&&k[c]>m)
       m=k[c];
     k[b]=m+1;
     m=0;
    }
 for(b=n-2;b>=0;b--)
    {
     z[n-1]=1;
     for(c=n-1;c>b;c--)
     if(t[c]<t[b]&&z[c]>m)
       m=z[c];
     z[b]=m+1;
     m=0;
    }
 for(c=0;c<n;c++)
    if(k[c]+z[c]>nmax)
      nmax=k[c]+z[c];
 max=n-nmax+1;
 printf("%d",max);
 system("pause");
 return 0;
}
