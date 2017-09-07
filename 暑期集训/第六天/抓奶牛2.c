#include<stdio.h>  
int main()
{
 int a[100000]={0},b[100000]={0},c[100000]={0};
 int m,k,i,j;
 scanf("%d%d",&m,&k);
 if(m>=k)
   {
    printf("%d",m-k);
    system("pause");
    return 0;
   }
 a[0]=m;
 b[0]=0;
 c[m]=1;
 for(i=0,j=1;i<j;i++)
    {
     if(a[i]+1>=0&&a[i]+1<=100000)
       {
        if(c[a[i]+1]==0)
          { 
           a[j]=a[i]+1;
           b[j]=b[i]+1;
           c[a[j]]++;
           
           if(a[j]==k)
             {
              printf("%d",b[j]);
              system("pause");
              return 0;
             }
             j++;
          }
       }
     if(a[i]-1>=0&&a[i]-1<=100000)
       {
        if(c[a[i]-1]==0)
          {
           a[j]=a[i]-1;
           b[j]=b[i]+1;
           c[a[j]]++;
           
           if(a[j]==k)
             {
              printf("%d",b[j]);
              system("pause");
              return 0;
             }
           j++;
          }
       }
     if(a[i]*2>=0&&a[i]*2<=100000)
       {
        if(c[a[i]*2]==0)                         
          {
           a[j]=a[i]*2;
           b[j]=b[i]+1;
           c[a[j]]++;
           
           if(a[j]==k)
             {
              printf("%d",b[j]);
              system("pause");
              return 0;
             }
             j++;
          }
       } 
    }
 system("pause");
 return 0;
}
