//3．笨小猴
/*#include<stdio.h>
int main()
{
    int n,c,d,maxn=0*最多字母的个数*,min=0*最少字母的个数*;
    char i[100][24]*行为同种字符,列为几种字母*,word[100]*a出现最多的字母/,b出现最少的字母*,out*输出;
    printf("请输入要检测的单词");
     gets(word);
    word[n];
    i[c][d];
    for(n=0;n<=strlen(word)/*量长度*;n++)
       {
        word[n]=a;
        for(c=0,d=0;;)
           {
            i[c][d]=a
           } 
       } 
    printf("%s\n",);
    system("pause");
    return 0;
}*/



//先输入要测的字母，
//设一个一维数组计算每一个字母的次数，方法是：
//把每个字母循环一次，比如说“a”把a放入【a-97】=【0】中i[a-97]++.“b”into【b-97】=【1】i[b-97]++。 
//然后计算最大最小的，然后。。。 
#include<stdio.h>
#include<string.h>
int main()
{
    int m,k,n,a,b,maxn/*最多字母的个数*/,min/*最少字母的个数*/;
    char i[23],word[100];
    printf("请输入检测单词"); 
     gets(word);
    word[n];
    for(n=0;n<=strlen(word)/*量长度*/;n++)
       {
        word[n]=b;
        i[b-97]++;
       }
    for(i[a],a=0,maxn=i[0];a<24;a++)
       {
        if(i[a]>maxn)
          maxn=i[a];
       }
    for(i[a],a=0,min=i[0];a<24;a++)
       {
        if(i[a]<min)
          min=i[a];
       } 
    
   // 素数（又称质数）：就是除了1和它本身，没有其他因子的整数。
   // 注：1不是素数。
   k==maxn-min;
    if(k==1)
      goto remove;
    for(m=2;m<k;m++)
    {
     if(k%m==0)//如果k被m整除 
       {
        remove:
        printf("No Answer\n0");//不为质数
        goto to;
       }
    }
    printf("Lucky Work\nk,");//为质数
    to:
    return 0;
}
