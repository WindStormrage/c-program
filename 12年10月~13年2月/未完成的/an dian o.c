#include<stdio.h>
int main()
{
    int e,a,b,c,d,p,i;
    int h[100][100];
 zyt:
   printf("请输入行列数"); 
   scanf("%d",&e);
   scanf("%d",&a);
   printf("请输入数据");
   for (b=0;b<e;b++)
       for(c=0;c<a;c++)
       scanf("%d",&h[b][c]);
   for (b=0;b<e;b++)
   {
       p=h[b][0];
       for (c=0;c<a;c++)
       if(p<h[b][c])
       {
            i=c; 
            p=h[b][c];
       }
       
       d=h[0][i];
       for (c=0;c<e;c++)
       if(d>h[c][i]) 
       d=h[c][i];
       
       if(p==d)  printf("该组数的鞍点为%d",p);
   }
   system("pause");
   system("CLS");
 goto zyt;
    return 0;
}
