/*#include<stdio.h>
int main()
{
    int m,n,a,b;其中a为最小公倍数，b为最大公因数，m、n为输入两数
    printf("请输入两个数:\n");
    scanf("%d%d",&m,&n);
    for(a=1;a%m!=0&&a%n!=0;a++)
    {
     a==a++;
    }   
    printf("最小公倍数为:");
    printf("%d\n",a);
    b==(m*n)/a;
    printf("最大公因数为:");
    printf("%d",b);
system("pause");
return 0;
} */
/*先用小的数除大的数，得第一个余数；
再用第一个余数除小的数，得第二个余数；
又用第二个余数除第一个余数，得第三个余数；
这样逐次用后一个余数去除第一个余数，直到余数是0为止，
那么最后一个除数就是所求的最大公约数。（
如果最后的除数是1，那么原来两个数是互质的！）*/
#include<stdio.h>
int main()
{
    int m,n,a,b;  /*其中a为最小公倍数，b为最大公因数，m、n为输入两数,c为其他数*/
    printf("请输入两个数:\n");
    scanf("%d%d",&m,&n);
    if(m>n)
    {
      c==n%m;
      b==c%n;
      for(;b=0;)
         {
          b=(b%n)%(n%m);
         }
    }
    else
        {
         for(;b=0;)
            {
             b==m%n;
             b==b%m;
            } 
    }      
    printf("最大公因数为:");
    printf("%d",b);
    a==(m*n)/b;
    printf("最小公倍数为:");
    printf("%d\n",a);
system("pause");
return 0;
}

