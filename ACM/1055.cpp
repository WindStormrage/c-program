#include<stdio.h>
int main()
{
 int a=0,i,b[13];
 char s[13];
 for(i=0;i<13;i++)
    scanf("%c",&s[i]); 
 b[0]=s[0]-'0';
 b[1]=s[2]-'0';
 b[2]=s[3]-'0';
 b[3]=s[4]-'0';
 b[4]=s[6]-'0';
 b[5]=s[7]-'0';
 b[6]=s[8]-'0';
 b[7]=s[9]-'0';
 b[8]=s[10]-'0';
 for(i=0;i<9;i++)
    {
	 b[i]=b[i]*(i+1);
     a=a+b[i];
    }
	a=a%11;
 if(a==10)
   if(s[12]=='X')
     printf("Right");
   else
     printf("%c%c%c%c%c%c%c%c%c%c%c%cX",s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9],s[10],s[11]);
 else
   if(s[12]==a+48)
     printf("Right");
   else
     printf("%c%c%c%c%c%c%c%c%c%c%c%c%d",s[0],s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9],s[10],s[11],a);
 return 0;
}
