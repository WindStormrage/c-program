#include<stdio.h>
int main()
{
 int n,i,j,d,a,b,c=0;
 scanf("%d %d",&a,&b);
 n=b;
 for(;a>0;)
   {
    j=a%10;
    for(b=n;b>0;)  
      { 
       i=b%10;
       c=c+j*i;
       b=b/10;
      }
    a=a/10;
   }
 printf("%d",c);
 system("pause");
 return 0;
} 
