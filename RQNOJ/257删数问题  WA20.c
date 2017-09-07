#include<stdio.h>
int main()
{
 long int a,n,b[9999]; 
 int i,j,k,t,f=0;
 scanf("%d %d",&a,&n);
 for(i=0;a!=0;i++)
    {
     b[i]=a%10;
     a=a/10;
    }
 for(k=0;k<i;k++) //Ã°ÅÝ·¨ÅÅÐò 
    {
     for(j=0;j<i-k-1;j++) 
        if(b[j]>b[j+1]) 
          {
           t=b[j];
           b[j]=b[j+1]; 
           b[j+1]=t;
           f=1;
          }
     if(f==0)
       break;
     else
       f=0;
    }
 for(j=0;j<i-n;j++)
    printf("%d",b[j]);
 system("pause");
 return 0;
} 
