#include<stdio.h>

int k[10]={6,2,5,5,4,5,6,3,7,6};

int f(int a)
{
 if(a<10) return(k[a]);
 else if(a>=10&&a<100) return(k[a/10]+k[a%10]);
 else if(a>=100&&a<1000) return(k[a/100]+k[(a/10)%10]+k[a%10]);
}

int main()
{
 int a,b,c=0;
 int n;
 scanf("%d",&n);
 for(a=0;a<1000;a++)
    for(b=0;b<1000-a;b++)
       if(f(a)+f(b)+f(a+b)==n-4)
         c++;
 printf("%d\n",c);
 system("pause");
 return 0;
}
