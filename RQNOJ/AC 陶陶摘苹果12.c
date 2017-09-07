#include<stdio.h>
int main()
{
 int a[9],h,i,x=0;
 for(i=0;i<10;i++)
    scanf("%d",&a[i]);
 scanf("%d",&h);
 h=h+30;
 for(i=0;i<10;i++)
    if(h>=a[i])
      x++;
 printf("%d",x);
 system("pause");
 return 0;
} 
