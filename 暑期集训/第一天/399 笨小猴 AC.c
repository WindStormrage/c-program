#include<stdio.h>
#include<string.h>
int main()
{
    int m,k,n,a,maxn/*最多字母的个数*/,min/*最少字母的个数*/;
    char i[26]={0},b,word[100];
    gets(word);
    for(n=0;n<=strlen(word)/*量长度*/;n++)
       i[word[n]-'a']=i[word[n]-'a']+1;
    for(a=0,maxn=i[0];a<26;a++)
       if(i[a]>maxn)
         maxn=i[a];
    for(a=0,min=101;a<26;a++)
       if(i[a]!=0&&i[a]<min)
         min=i[a];
   n=maxn-min;
    k=sqrt(n);
    for(a=2;a<=k;a++)
    {
       if(n%a==0)
       {
         break;
       }
    }
    if(a<=k||n==0||n==1)
       printf("No Answer\n0");
    else
       printf("Lucky Word\n%d",n);
    system("pause");
    return 0;
}
