#include<stdio.h>
int main()
{
 int n,t[231],k[231]={0};
 int nmax=1000,max,a,b,c,m=0,i,j;
 scanf("%d",&n);
 for(a=0;a<n;a++)
    scanf("%d",&t[a]);
 for(a=0;a<n;a++)
    {
     for(b=a;b>=0;b--)//<--
        {
         k[a]=1;
         for(c=a-1;c>=0;c--)
            if(t[c+1]>t[c]&&k[c+1]>m)
              m=k[c+1];
         k[b]=m+1;
         m=0;
        }
     max=k[1];
     for(c=2;c<=a;c++)
        if(k[c]>max)
          max=k[c];
     i=n-max;
     for(b=a;b<n;b++)//-->
        {
         k[a]=1;
         for(c=a;c<n;c++)
            if(t[c+1]<t[c]&&k[c+1]>m)
              m=k[c+1];
         k[b]=m+1;
         m=0;
        }
     max=k[1];
     for(c=2;c<=a;c++)
        if(k[c]>max)
          max=k[c];
     j=n-max;
     if((i+j)<nmax)
       nmax=i+j;
    }
printf("%d",nmax);
 system("pause");
 return 0;
}
