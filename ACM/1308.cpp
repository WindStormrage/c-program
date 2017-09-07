/*#include<stdio.h>
#include<string.h>
int main()
{
 char a[10],b[1000000];
 int i,j,n=0,time=1,sum=1,first;
 gets(a);
 gets(b);
 for(i=0;i<strlen(a);i++)
    if(a[i]<'a'&&a[i]!=' ')  a[i]=a[i]+32;
 for(i=0;i<strlen(b);i++)
    if(b[i]<'a'&&b[i]!=' ')  b[i]=b[i]+32;
 for(i=0;i<strlen(b);i++)
    if(i==0||b[i-1]==' ')
      {
       for(j=0;!((a[j]=='\0'||a[j]==' ')&&(b[i]==' '||b[i]=='\0'));i++,j++)
          if(b[i]==' '||b[i]=='\0'||a[j]=='\0'||b[i]!=a[j])
            {
             sum=0;
             break;
            }
       if(sum==1)
         {
          n++;
          if (n==1)
            first=time;
         }
       time++; 
       sum=1;
      }
  if(n==0)  printf("-1");
  else
     printf("%d %d",n,first-1);
  return 0;
}

To 
to be or not to be is a question 

*/

#include <stdio.h>
#include<string.h> 
char a[100],b[100];


int main()
{int k,time=0,s=0,i,j = 0;
    gets(a);
    gets(b);
    for (k=0; k<strlen(b); k++) {
        if(b[k]<'Z'&&b[k]>'A')
            b[k]=b[k]+32;
    }//转换大小写
        for (k=0; k<strlen(a); k++) {
        if(a[k]<'Z'&&a[k]>'A')
            a[k]=a[k]+32;
    }
    
    for (i=0; i<strlen(b); i++) {
        j=0;
        if(i==0||b[i-1]==' ')
        {for(j=0;j<strlen(a);j++)
            
            if(a[j]!=b[i+j])
            break;
            
        }
        if((j==strlen(a))&&(b[j+i]==' '||b[j+i]=='\0'))//判断条件
        {
            time++;
            j=0;
            if(time==1)
                s=i+1;
        }
    }
    if(time==0)
        printf("-1");
    else
    printf("%d %d",time,s);
    return 0;
}

