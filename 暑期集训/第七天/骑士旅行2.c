#include<stdio.h>  
int main()
{
 int x[8]={-1,1,2,2,1,-1,-2,-2},y[8]={2,2,1,-1,2,-2,-1,1},g[51][51]={0}/*标记*/,w[2][2501]/*队列*/,l[2501]={0}/*路程*/;
 int m,n/*范围*/,i,j/*目标*/;
 int a,b=1,c=0; 
 scanf("%d%d%d%d",&n,&m,&i,&j);
 g[1][1]=1;
 w[0][0]=1;
 w[1][0]=1;
 while(b!=c)
    {
 //printf("1 ");
     for(a=0;a<8;a++)
        {
 //printf("2 ");
 if( g [ w[0][c]+x[a] ] [ w[1][c]+y[a] ] == 0 )
         if(w[0][c]+x[a]>0&&w[0][c]+x[a]<=n&&w[1][c]+y[a]>0&&w[1][c]+y[a]<=m)
    //       if( g [ w[0][c]+x[a] ] [ w[1][c]+y[a] ] == 0 )
             {
 //printf("3 ");
              w[0][b]=w[0][c]+x[a];
              w[1][b]=w[1][c]+y[a];
              l[b]=l[c]+1;
              g [ w[0][b] ] [ w[1][b] ] = 1;
              if(w[0][b]==j&&w[1][b]==i)
                {
                 printf("%d",l[b]);
                 system("pause");
                 return 0;
                }
              b++;//尾 
             }
        }
     c++;//头 
    }
 printf("无答案!");
 system("pause");
 return 0;
}
