#include<stdio.h>
int main()
{
	int a;
	printf("请输入需要的形状:1为等腰三角形.2为菱形.3为直角三角形.\n");
	scanf("%d",&a);
	if(a==1)
    	{
        int n,x;
        for(n=1;n<=5;n++)
           {
            for(x=1;x<=5-n;x++)
                printf(" ");
            for(x=1;x<=n;x++)
                printf("* ");
            printf("\n");
           }
        }
    else
        {
            if(a==2)
            {
                int n,x;
                for(n=1;n<=5;n++)
                   {
                   for(x=1;x<=5-n;x++)
                       printf(" ");
                       for(x=1;x<=n;x++)
                       printf("* ");
                       printf("\n");
                    }
                for(n=6;n<=9;n++)
                   {
                    for(x=1;x<=n-5;x++)
                       printf(" ");
                    for(x=1;x<=10-n;x++)
                       printf("* ");
                       printf("\n");
                    }
             }
            else
                {
                 int n,x;
                 for(n=1;n<=5;n++)
                    {
                     for(x=1;x<=n;x++)
                     printf("*");
                     printf("\n");
                     }
                 }
        }  
    system("pause");
    return 0;
}
