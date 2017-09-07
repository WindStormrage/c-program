#include<stdio.h>
int main()
{
 int a,i,j;
 char y[101],m[101],x[101],n[101];
 scanf("%s",m);
 scanf("%s",y);
 scanf("%s",x);
 for(a=0;a<strlen(m);a++)
    n[m[a]-'A']++;
 for(a=0;a<26;a++)
    if(n[a]==0)
      { 
       printf("Failed");
       return 0;
      }
 for(i=0;i<strlen(m);i++)
    for(j=i+1;j<strlen(m);j++)
       if(m[i]==m[j])
         if(y[i]!=y[j])
           { 
            printf("Failed");
            return 0;
           } 
 for(i=0;i<strlen(m);i++)
    for(j=i+1;j<strlen(m);j++)
       if(y[i]==y[j])
         if(m[i]!=m[j])
           { 
            printf("Failed");
            return 0;
           } 
 for(j=0;j<strlen(x);j++)
    for(i=0;i<strlen(m);i++)
       if(x[j]==m[i])
         {
          x[j]=y[i];
          break;
         }
 printf("%s",x);
 system("pause");
 return 0;
}
