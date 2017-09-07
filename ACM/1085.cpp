#include<stdio.h>
int main()
{
 int a[2][7],i,j,b=0;
 for(i=0;i<7;i++)
    for(j=0;j<2;j++)
       scanf("%d",&a[j][i]);
 for(j=0;j<7;j++)
    if((a[0][j]+a[1][j])>8) {b=j+1;break;}
 printf("%d",b);
 return 0;
}
