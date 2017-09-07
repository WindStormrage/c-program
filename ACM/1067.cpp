#include<stdio.h>
int main()
{
	int n,i,a[200];
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
	   scanf("%d",&a[i]);
	if(a[0]!=1&&a[0]!=-1)
	  printf("%dx^%d",a[0],n);
	else if(a[0]!=-1)
	  printf("x^%d",n);
	else
	  printf("-x^%d",n);	  
	for(i=n-1;i>-1;i--)
	   {
	    if(a[n-i]>1)
	      {
		      if(i==0)
		        printf("+%d",a[n-i]);
		      else if(i==1)
		        printf("+%dx",a[n-i]);
		      else
		        printf("+%dx^%d",a[n-i],i);
	      }
		else if(a[n-i]==1)
		  {    
			  if(i==0)
		        printf("+1");
		      else if(i==1)
		        printf("+x");
		      else
		        printf("+x^%d",i);
		  }
	    else if(a[n-i]==0)
			;
	    else if(a[n-i]==-1)
	      {
		      if(i==0)
		        printf("-1");
		      else if(i==1)
		        printf("-x");
		      else
		        printf("-x^%d",i);
	      }
	    else if(a[n-i]<-1)
	      {  
		      if(i==0)
		        printf("%d",a[n-i]);
		      else if(i==1)
		        printf("%dx",a[n-i]);
		      else
		        printf("%dx^%d",a[n-i],i);
		  }
       }
}
