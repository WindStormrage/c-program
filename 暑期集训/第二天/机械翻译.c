#include<stdio.h>
int main()
{
 int a[1001],m,n,i;
 int b,c,d;
 scanf("%d%d",&m,&n);
 for(b=0;b<n;b++)
    scanf("%d",&a[b]);
 for(c=0,i=m;c<m-1;c++) 
    for(d=c+1;d<m;d++)
       {
        if(a[c]==a[d])
          {
           i--;
           break;
          }
       }       
 for(b=0;b<n;b++)
    {
     i++;
     for(c=b;c<b+m;c++) 
        {
         if(a[c]==a[b+m])
           {
            i--;
            break;
           }
        }
    }
 printf("%d",i);
 system("pause");
 return 0;
}
