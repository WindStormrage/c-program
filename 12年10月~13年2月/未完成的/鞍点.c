#include<stdio.h>
int main()
{
    int a,b,c,d,e,p/*���е���Сֵ*/,n/*hang*/,m/*lie*/;
    int h[3][4];
 zyt:
   /*
   print4
   f("���������ݸ���"); */
   scanf("%d",&e);
    scanf("%d",&a);
    printf("����������");
    for (b=0;b<e;b++)
        for(c=0;c<a;c++)
        scanf("%d",&h[b][c]);
      d = h[0][0];
      for (b=0;b<e;b++)
          for (c = 1;c < a;c ++)
            { 
               if(d < h[b][c]) 
                 {
                  d = h[b][c];
                  m=c;
                 }
               for(b=0;b<e;b++)
               {
                if(d > h[b][m])
                  {p=h[b][m];
                   n=b; 
                   } 
                p=h[n][m];
               }
               if(p==d)     printf("����Ϊ%d\n",d);           
               
            } 
     printf("����Ϊ%d\n",d);
    system("pause");
    system("CLS");
 goto zyt;
    return 0;
}
