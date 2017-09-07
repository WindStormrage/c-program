#include<stdio.h>
int main()
{
 char k[100],c[1000];
 int i,j,key,a;
 gets(k);
 gets(c);
 a=strlen(k);
 for(i=0;i<strlen(k);i++)
    {
     if(k[i]>='a'&&k[i]<='z')
       k[i]=k[i]-'a';
     else
       k[i]=k[i]-'A';
    }
 for(i=0;i<strlen(c);i++)
     {
      key=i%a;
      if(c[i]+k[key]>'z')
        printf("%s",c[i]+k[key]-26);
      else
        printf("%s",c[i]+k[key]);
     }
 system("pause");
 return 0;
}
