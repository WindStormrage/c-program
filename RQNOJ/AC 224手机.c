#include<stdio.h>
int main()
{
 char a[200],d;
 int b=0,c;
 gets(a);
 for(c=0;c<strlen(a);c++)
    {
     d=a[c];
     if(d=='b'||d=='e'||d=='h'||d=='k'||d=='n'||d=='q'||d=='u'||d=='x') b=b+2;
     else if(d=='c'||d=='f'||d=='i'||d=='l'||d=='o'||d=='r'||d=='v'||d=='y') b=b+3;
     else if(d=='s'||d=='z') b=b+4;
     else b++; 
    } 
 printf("%d",b);
 system("pause");
 return 0;
} 
