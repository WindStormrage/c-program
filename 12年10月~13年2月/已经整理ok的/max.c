#include<stdio.h>
int main()
{
 int i,max,a[5];
 printf("请输入需要比较的五个数：\n");
 for(i=0;i<5;i++)
    {
     scanf("%d",&a[i]);
    }
 max=a[0];
 for(i=1;i<5;i++)
    {
     if(a[i]>max)
       max=a[i];
    }
 printf("max=%d",max);
 system("pause");
 return 0;
}
