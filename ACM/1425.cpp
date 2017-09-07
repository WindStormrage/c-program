#include<stdio.h>
int main()
{
 int a,b,c,d,i,j;
 scanf("%d%d%d%d",&a,&b,&c,&d);
 i=a*60+b;
 j=c*60+d;
 printf("%d %d",(j-i)/60,(j-i)%60);
 return 0;
}
