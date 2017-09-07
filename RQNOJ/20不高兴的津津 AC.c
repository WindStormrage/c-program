#include<stdio.h>
int main()
{
 int i,max,d,a[6],b[6];
 for(i=0;i<=6;i++)
    scanf("%d %d",&a[i],&b[i]);
 max=a[0]+b[0];
 for(d=1,i=1;i<=6;i++)
    if(a[i]+b[i]>max)
      {
       max=a[i]+b[i];
       d=i+1;
      }
 if(i==6&&a[i]+b[i]<8)
   { 
    printf("0");
    return 0;
   }
 printf("%d",d);
 system("pause");
 return 0;
} 
