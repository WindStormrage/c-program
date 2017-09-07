#include<stdio.h>
int main()
{
	int m,n,a[1000],b[100]={-1},i,j,ans=0,sum;
	for(i=0;i<100;i++)
	   b[i]=-1;	
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);

	for(i=0;i<n;i++)
	   {
	   	sum=0;
	   	for(j=0;j<m;j++)
		   if(a[i]==b[j])
		     sum=1;
	   	if(sum==1) continue;
	   	else
	   	  {
	   	   for(j=0;j<m-1;j++)
	   	      b[j]=b[j+1];
	   	   b[m-1]=a[i];
		   ans++;
		  }	   	
	   }
	printf("%d",ans);
} 
