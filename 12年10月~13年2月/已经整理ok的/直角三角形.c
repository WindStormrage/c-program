#include<stdio.h>
int main()
{
    int n,x;
    for(n=1;n<=5;n++)
       {
        for(x=1;x<=n;x++)
            printf("*");
        printf("\n");
       }
    system("pause");
    return 0;
}
