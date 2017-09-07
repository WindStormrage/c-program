#include<stdio.h>
int main()
{
 int a,b,qm,yp,lw,z[101]={0},max=0,n,m=0;
 char name[101][30],xb,gb;
 scanf("%d",&b);
 for(a=0;a<b;a++)
    {
     scanf("%s %d %d %c %c %d",name[a],&qm,&yp,&gb,&xb,&lw);
     if(qm>80&&lw>=1)
       z[a]=z[a]+8000;
     if(qm>85&&yp>80)
       z[a]=z[a]+4000;
     if(qm>90)
       z[a]=z[a]+2000;
     if(qm>85&&xb=='Y')
       z[a]=z[a]+1000;
     if(yp>80&&gb=='Y')
       z[a]=z[a]+850;
    }
 for(a=0;a<b;a++)
    {
     if(z[a]>max)
       {
        max=z[a];
        n=a;
       }
     m=m+z[a];
    }
 printf("%s\n%d\n%d",name[n],max,m);
 system("pause");
 return 0;
}
