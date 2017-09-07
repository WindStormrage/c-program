#include<stdio.h>
int main()
{
  int a[12],money=0,i,j=0,mama=0;
  for(i=0;i<12;i++)
     scanf("%d",&a[i]);
  for(i=0;i<12;i++)
     {
      mama =((money+300-a[i])/100)*100+mama;
      money=(money+300-a[i]);
      if(money<0) {j=1;break;}
      money=money%100;
     }
  if(j==1) printf("%d",0-(i+1));
  else     printf("%d",(int)((float)mama*1.2+money));
  return 0;
}
