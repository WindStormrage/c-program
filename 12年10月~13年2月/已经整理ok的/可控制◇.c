#include<stdio.h>
int main()
{
 int n,j,i;
 printf("请输入您要输出菱形的边为几个* ："); 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    {
     for(j=1;j<=i+n-1;j++)
        {
         if(j==n+1-i||j==n-1+i)
             {
              printf("*");
             }
         else
             {
              printf(" ");
             }
        } 
         printf("\n");
    }
 for(i=1;i<=n-1;i++)
   {
    for(j=1;j<=2*n-1-i;j++)
       {
        if(j==i+1||j==2*n-1-i)
            {
             printf("*");
            }
        else
            {
             printf(" ");
            }
        }
        printf("\n");
   }
 system("pause");
 return 0;
}
