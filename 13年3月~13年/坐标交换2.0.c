#include<stdio.h>
int x[3][3],y[3][3],a,b,j=0,i=0;
int jh()
 { 
  for(a=0;a<3;a++)
     for(b=0;b<3;b++)
        scanf("%d",&x[a][b]);
  for(x[a][b],a=0;a<3;a++)
     for(x[a][b],b=0;b<3;b++)
        {
         i=a;
         j=b;
         y[j][i]=x[a][b];
        }
 }
int main()
{
 jh();
 for(i=0;i<3;i++)
    for(j=0;j<3;j++)
       printf("%d ",y[i][j]);
 system("pause");
 return 0;
}
