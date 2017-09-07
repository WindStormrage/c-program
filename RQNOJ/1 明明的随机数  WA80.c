#include<stdio.h>
int main()
{
 int a[1000],i,b=0,k,n,j;
    scanf("%d",&i);
 for(k=0;k<i;k++)
    scanf("%d",&a[k]);
    
 for(n=0;n<i-b;n++)
    for(k=n+1;k<i-b;k++)
       if(a[n]==a[k])
         {
          for(j=k;j<i-b;j++)
              a[j]=a[j+1];
          k--;
          b++;
         }
 for(j=0;j<i-b;j++)
    {
     for(k=0;k<i-b-j;k++)
        {
         if(a[k]>a[k+1])
           {
            n=a[k]; 
            a[k]=a[k+1]; 
            a[k+1]=n;
           }
        }
    }
 printf("%d\n",i-b);
 for(k=0;k<i-b;k++)
    printf("%d ",a[k]);
 system("pause");
 return 0; 
} 


