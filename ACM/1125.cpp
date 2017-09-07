#include<stdio.h>
#include<string.h>

int zhishu(int k);
int main()
{
	int d=0;	
	char a[100];
	int  b[26]={0},i,max,min;
    gets(a);
	for(i=0;i<strlen(a);i++)
	   {
		b[(int)(a[i]-97)]++;
	   }
	max=0;
	min=100;
	for(i=0;i<26;i++)
	   {
	    if(b[i]!=0)
	   	  {
		   if(b[i]>max) max=b[i];
	   	   if(b[i]<min) min=b[i];
          }
	   } 
	   
	   
	if(zhishu(max-min)==1)	printf("Lucky Word\n%d",max-min);
    else                    printf("No Answer\n0");
}

int zhishu(int k)
{
    int m;
    if(k==0||k==1)
      return 0;
    if(k==2)
      return 1;
    for(m=2;m<k;m++)
       if(k%m==0)
         return 0;
    return 1;
}
