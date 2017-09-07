#include<stdio.h>
#include<math.h>
int main()
{
 int i,j,a,n,b[10000],m=0,ans=0;
 scanf("%d",&a);
 if(a>-10&&a<10)
   printf("%d",a);
 else if(a>=10)
   for(i=1;;i++)
      {
       if(a/(int)pow(10,i-1)==0)
          break;
       n=1;
	   for(j=1;j<i;j++)
          if(j==1)
		    { 
  		     b[i]=a/10;
  	         n=0;
		    }
		  else
		    {
  	  	     b[i]=b[i]/10;
  	  	     n=0;
			}
	   if(n==0)
         b[i]=b[i]%10;
	   else
	     b[i]=a%10;
	  }
 else
   {
   	m=1;
    a=0-a;
    for(i=1;;i++)
       {
        if(a/(int)pow(10,i-1)==0)
           break;
        n=1; 
   	    for(j=1;j<i;j++)
           if(j==1)
 		     { 
   		      b[i]=a/10;
  	          n=0;
		     }
		   else
		     {
  	  	      b[i]=b[i]/10;
  	  	      n=0;
			 }
	    if(n==0)
          b[i]=b[i]%10;
	    else
	      b[i]=a%10;
	   }
   }
 for(j=1;;j++)
    if(b[j]!=0)
      break;
 for(n=i-j-1;j!=i;j++,n--)
    ans=ans+b[j]*(int)pow(10,n);
 if(m==1)
   ans=0-ans;
 printf("%d",ans);
 return 0;
}




#include<stdio.h>
#include<cstring>
#include<math.h>
int main()
{
 char a[1000000];
 int b,c,d,ans=0;
 gets(a);
 b=strlen(a);
 if(b==1)
   {
    printf("%c",a[0]);
    return 0;
   }
 if(b>1&&a[0]!='-')
   {
	for(c=b-1;;c--)
       if(a[c]!='0')
   	     break;
    for(;c>=0;c--) 
       ans=ans+(a[c]-48)*pow(10,c);
   }
 else
   {
	for(c=b-1;;c--)
       if(a[c]!='0')
   	     break;
    for(;c>0;c--) 
       ans=ans+(a[c]-48)*pow(10,c);
    ans=0-ans;
    ans=ans/10;
   }

 printf("%d",ans);
 return 0;
}


