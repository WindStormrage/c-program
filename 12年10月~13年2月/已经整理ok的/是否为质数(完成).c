#include<stdio.h>
int main()
{
    int m,k;
    printf("请输入数"); 
    scanf("%d",&k);
    if(k==1)
      goto remove;
    for(m=2;m<k;m++)
    {
     if(k%m==0)//如果k被m整除 
       {
        remove:
        printf("不为质数\n");
        goto to;
       }
    }
    printf("为质数\n");
    to:
    system("pause");
    return 0;
}
/*#include<stdio.h>
#include <stdlib.h>
int main()
{
int m, k;
int flag = 1;
printf ("请输入一个整数："); 
while (scanf ("%d", &k) == 1)
{
for(m = 2; m <= k; m++)
if (k % m == 0)
break;
if (k == m)
printf ("%d为质数\n", k);
else
printf ("%d不为质数\n", k);
printf ("请输入一个整数（输入q退出）：");
}
system ("pause");
return 0;
}
*/
