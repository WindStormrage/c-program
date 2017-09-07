#include<stdio.h>  
int main()
{
 int n,a[1001]={0},b[1001]={0},max,w;
 int c,d;
 scanf("%d",&n); 
 for(c=1;c<=n;c++)
    scanf("%d",&a[c]);
 b[1]=1;
 for(c=2;c<=n;c++)
    {
     for(d=1;d<c;d++)
        if(a[d]>a[c]&&b[d]>w)
          w=b[d];
     b[c]=w+1;
     w=0;
    }
 max=b[1];
 for(c=2;c<=n;c++)
    if(b[c]>max)
      max=b[c];
 printf("%d ",max);

 b[1]=1;
 for(c=2;c<=n;c++)
    {
     for(d=1;d<c;d++)
        if(a[d]<a[c]&&b[d]>w)
          w=b[d];
     b[c]=w+1;
     w=0;
    }
 max=b[1];
 for(c=2;c<=n;c++)
    if(b[c]>max)
      max=b[c];
 printf("%d",max);

 system("pause");
 return 0;
}
