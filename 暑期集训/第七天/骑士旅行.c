#include<stdio.h>  
int main()
{
 int x[8]={-1,1,2,2,1,-1,-2,-2},y[8]={2,2,1,-1,2,-2,-1,1},g[51][51]={0}/*���*/,w[2][100000]/*����*/,l[10000]={0}/*·��*/;
 int m,n/*��Χ*/,i,j,/*Ŀ��*/k=1,z=1/*��ǰλ��*/;
 int a,b=1,c=0; 
 scanf("%d%d%d%d",&n,&m,&i,&j);
 w[0][0]=1;
 w[1][0]=1;
 while(k<z)
    {
     for(a=0;a<8;a++)
        {
         if( g [ w[0][b]+x[a] ] [ w[1][b]+y[a] ] == 0 )
           if(w[0][a-1]+x[a]>0&&w[0][a-1]+x[a]<m&&w[1][a-1]+y[a]>0&&w[1][a-1]+y[a]<n)
             {
              w[0][b]=w[0][c]+x[a];
              w[1][b]=w[1][c]+y[a];
              l[b]=l[c]+1;
              g [ w[0][b] ] [ w[1][b] ] = 1;
             }
         if(w[0][a-1]==i&&w[1][a-1]==j)
           {
            printf("%d",&l[a]);
            system("pause");
            return 0;
           }
         b++;//β 
        }
     c++;//ͷ 
    }
 printf("�޴�");
 system("pause");
 return 0;
}
