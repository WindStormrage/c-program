#include<stdio.h>
int main()
{
 int p1,p2,p3,b,c,d;
 char a[101];
 scanf("%d%d%d",&p1,&p2,&p3);
 scanf("%s",a);
 for(b=0;b<strlen(a);b++)
    {
     if(a[b]=='-')
       {
        if(((a[b-1]>='0'&&a[b-1]<='9')&&(a[b+1]>='0'&&a[b+1]<='9')||(a[b-1]>='a'&&a[b-1]<='z')&&(a[b+1]>='a'&&a[b+1]<='z'))&&(a[b+1]>a[b-1]))
          {
           if(p1==1||((a[b-1]>='0'&&a[b-1]<='9')&&(a[b+1]>='0'&&a[b+1]<='9')&&p1==2))
             {
              if(p3==1)
                for(c=1;c<(a[b+1]-a[b-1]);c++)
                   for(d=1;d<=p2;d++)
                      printf("%c",a[b-1]+c);
              if(p3==2)
                for(c=1;c<(a[b+1]-a[b-1]);c++)
                   for(d=1;d<=p2;d++)
                      printf("%c",a[b+1]-c);          
             } 
           if(p1==3)
             for(c=1;c<(a[b+1]-a[b-1]);c++)
                for(d=1;d<=p2;d++)
                   printf("*");
           if(p1==2&&(a[b-1]>='a'&&a[b-1]<='z')&&(a[b+1]>='a'&&a[b+1]<='z'))
             {
              if(p3==1)
                for(c=1;c<(a[b+1]-a[b-1]);c++)
                   for(d=1;d<=p2;d++)
                      printf("%c",a[b-1]+c-32);
              if(p3==2)
                for(c=1;c<(a[b+1]-a[b-1]);c++)
                   for(d=1;d<=p2;d++)
                      printf("%c",a[b+1]-c-32);   
             }           
           b++;
          }
       }
     printf("%c",a[b]);
    }
 system("pause");
 return 0;
}
