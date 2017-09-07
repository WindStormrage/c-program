#include<stdio.h>
int main()
{ 
  printf("\n");
  int n,i,max[5],a;
  for(a=0;a<=4;a++)
      {
       scanf("%d",&a);
      }
  for(i=max[0];i<=5;i++)
      {
       max[i]=i;
       if(i<=max[i])
           {
            n=max[i];
           }
       else
           {
            n=i;
           }
      }
  printf("max=%d",n);
  system("pause");
  return 0;
} 
