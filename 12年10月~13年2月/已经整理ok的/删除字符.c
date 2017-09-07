/*1．编写一个程序删除字符串中所有与指定字符相同的字符。
2．编写一个判定一字符串是否是另一字符串子串的程序。
3．笨小猴*/
#include<stdio.h>
int main()
{
    int n,a;
    char str[50],i/*想删除的字符*/;
    printf("初始字符串:");
     gets(str);
    printf("您想删除的字符:");
     scanf("%c",&i);
    str[n];
    for(n=0;n<=strlen(str)/*量长度*/;n++)
       {
        if(i==str[n])
          {
           for(a=1;a<=strlen(str)-n;a++)
              str[n+a-1]=str[n+a];        
           n==n--;
          }
       } 
    printf("%s\n",str);
    system("pause");
    return 0;
}
