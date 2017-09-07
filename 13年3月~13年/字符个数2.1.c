#include<stdio.h>
 int a=0,b=0,c=0,d=0,n;
 int h(char y[]) ;
int main()
 { 
  
  char y[100];
  gets(y);
  h(y);
  printf("字母个数为:%d\n数字个数为:%d\n空格个数为:%d\n其他字符为:%d\n",a,b,c,d);
  system("pause");
  return 0;
 }
 
int h(char y[])
 {
  int n;
  for(n=0;n<strlen(y);n++)
  {
     if((y[n]>='a'&&y[n]<='z')||(y[n]>='A'&&y[n]<='Z'))
         a++;
     else if(y[n]>='0'&&y[n]<='9')
         b++;
     else if(y[n]==' ')
         c++;
     else   
         d++;
 }
 } 
