#include<stdio.h>
int main()
{
 int f=300,a,in[11],n=0,d=0,c=0;
 for(a=0;a<12;a++)
    scanf("%d",&in[a]);
 for(a=0;a<12;a++)
    {
     n=n+f-in[a];
     d=n/100;
     n=n-100*d;
     c=c+100*d;
     if(n<0)
       {
        n=-1;
        break;
       }
    }
 if(n!=-1)
   {
    c=c*1.2+n+1;
    printf("%d",c); 
   }
 else
   printf("-%d",++a);
 system("pause");
 return 0;
}
