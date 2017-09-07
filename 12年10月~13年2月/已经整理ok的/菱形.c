#include<stdio.h>
int main()
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
    system("pause");
    return 0;
}
