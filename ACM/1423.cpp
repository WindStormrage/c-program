#include<stdio.h>
int main()
{
 float i,j,m,n,a;
 scanf("%f",&n);
 if(n<=2.0)
   {
    printf("1");
    return 0;
   }
 m=2.0,a=2.0;
 for(j=2.0;;j++)
    {
     m=m+a*0.98;
     a=a*0.98;
     if(n<=m)
       break;
    }
 printf("%d",(int)j);
 return 0;
}