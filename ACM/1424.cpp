#include<stdio.h>
int main()
{
 long int n,x=0;
 int day,i;
 scanf("%d%ld",&day,&n);
 for(i=1;i!=n+1;day++,i++)
    {
     if(day!=6&&day!=7)
       x=250+x;
     else if(day==7) 
       day=0;
    }
 printf("%ld",x);
 return 0;
}
