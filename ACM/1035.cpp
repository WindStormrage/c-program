#include<stdio.h>
int main()
{
 float k,sn=0;
 int n;
 scanf("%f",&k);
 for(n=1;sn<=k;n++)
    sn=sn+(float)1/(float)n;
 printf("%d",n);
 return 0;
}
