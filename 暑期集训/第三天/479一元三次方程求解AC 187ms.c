#include<stdio.h>
int main()
{
 int q;
 float a,b,c,d,e;
 scanf("%f%f%f%f",&b,&c,&d,&e);
 for(q=-10000;q<=10000;q++)
    {
     a=q/100.00;
     if( b*a*a*a+c*a*a+d*a+e<0.0001 && b*a*a*a+c*a*a+d*a+e>-0.0001 )
       {
        printf("%.2f ",a);
       }
    }
 system("pause");
 return 0;
}
